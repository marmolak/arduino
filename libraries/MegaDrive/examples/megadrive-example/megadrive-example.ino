#include <MegaDrive.h>

MegaDrive<mg_three_callbacks> *X;

void up(void)
{
  
}

void setup() {
  struct mg_pin_setup ps;
  struct mg_three_callbacks clbs;
  X = new MegaDrive<mg_three_callbacks>(ps, clbs);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  X->update_states();
}
