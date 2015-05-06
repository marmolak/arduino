#include <MegaDrive.h>

const int up_led = 13;
const int left_led = 12;
const int down_led = 11;
const int right_led = 10;

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
  .down_fnc = &down_keyup,
  .left_fnc = &left_keyup,
  .right_fnc = &right_keyup,
  .a_fnc = NULL,
  .b_fnc = NULL,
  .c_fnc = NULL,
  .start_fnc = NULL
};

static const struct mg_three_callbacks clbs_down = {
  .up_fnc = &up_keydown,
  .down_fnc = &down_keydown,
  .left_fnc = &left_keydown,
  .right_fnc = &right_keydown,
  .a_fnc = NULL,
  .b_fnc = NULL,
  .c_fnc = NULL,
  .start_fnc = NULL
};

MDThreeBtnsCallbacks X = MDThreeBtnsCallbacks(ps, clbs_up, clbs_down);

void left_keyup(void)
{
  digitalWrite(left_led, LOW);
}

void left_keydown(void)
{
  digitalWrite(left_led, HIGH);
}

void down_keyup(void)
{
  digitalWrite(down_led, LOW);
}

void right_keydown(void)
{
  digitalWrite(right_led, HIGH);
}

void right_keyup(void)
{
  digitalWrite(right_led, LOW);
}


void down_keydown(void)
{
  digitalWrite(down_led, HIGH);
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
  pinMode(down_led, OUTPUT);
  pinMode(right_led, OUTPUT);
}

void loop() {
  X.update_states();
  delay(20);
}

