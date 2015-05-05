#include <MegaDrive.h>

const int up_led = 13;
const int left_led = 12;

static const struct mg_pin_setup ps = {
  .D0 = 1,     // (UP key)
  .D1 = 2,     // (DOWN key)
  .D2 = 3,     // (LEFT key)
  .D3 = 4,     // (RIGHT key)
  .D4 = 5,     // (B or A key)
  .SELECT = 6, // (SELECT signal - output)
  .D5 = 7,     // (C or START key)
};

static const struct mg_three_callbacks clbs_up = {
  .up_fnc = &up_keyup,
  .down_fnc = NULL,
  .left_fnc = &left_keyup,
  .right_fnc = NULL,
  .a_fnc = NULL,
  .b_fnc = NULL,
  .c_fnc = NULL,
  .start_fnc = NULL
};

static const struct mg_three_callbacks clbs_down = {
  .up_fnc = &up_keydown,
  .down_fnc = NULL,
  .left_fnc = &left_keydown,
  .right_fnc = NULL,
  .a_fnc = NULL,
  .b_fnc = NULL,
  .c_fnc = NULL,
  .start_fnc = NULL
};

MDThreeBtnsCallbacks *const X = new  MDThreeBtnsCallbacks(ps, clbs_up, clbs_down);

void left_keyup(void)
{
  digitalWrite(left_led, LOW);
}

void left_keydown(void)
{
  digitalWrite(left_led, HIGH);
}


void up_keyup(void)
{
  digitalWrite(up_led, LOW);
}

void up_keydown(void)
{
  digitalWrite(up_led, HIGH);
}


void setup() {
  pinMode(up_led, OUTPUT);
  pinMode(left_led, OUTPUT);
}

void loop() {
  X->update_states();
  delay(20);
}
