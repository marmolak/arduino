#include <MegaDrive.h>

int led = 13;

static struct mg_pin_setup ps = {
  .D0 = 4, // Use pin 4 of Arduino uno as input (UP key)
};

static struct mg_three_callbacks clbs = {
  .up_fnc = &up_keyup,
};

static struct mg_three_callbacks clbs_down = {
  .up_fnc = &up_keydown,
};

MegaDrive<mg_three_callbacks> *X = new MegaDrive<mg_three_callbacks>(ps, clbs, clbs_down);;

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
