#include <MegaDrive.h>

const int led = 13;

static const struct mg_pin_setup ps = {
  .D0 = 4, // Use pin 4 of Arduino uno as input (UP key)
};

static const struct mg_three_callbacks clbs_up = {
  .up_fnc = &up_keyup,
};

static const struct mg_three_callbacks clbs_down = {
  .up_fnc = &up_keydown,
};

 MDThreeBtnsCallbacks *X = new  MDThreeBtnsCallbacks(ps, clbs_up, clbs_down);

void up_keyup(void)
{
  digitalWrite(led, LOW);
}

void up_keydown(void)
{
  digitalWrite(led, HIGH);
}


void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  X->update_states();
  delay(20);
}
