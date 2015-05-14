#include <SoftwareSerial.h>
#include <MegaDrive.h>

class JoypadActions : 
public MD_JoypadActionsSix {

  void up_key_down() {
    send_msg("up!");
  };

  void up_key_up() {
  };

  void down_key_down() {
    send_msg("down!");
  };

  void down_key_up() {
  };

  void left_key_down() {
    send_msg("left!");
  };

  void left_key_up() {

  };

  void right_key_down() {
    send_msg("right!");
  };

  void right_key_up() {
  };

  void a_key_down() {
    send_msg("a!");
  };
  void a_key_up() {
  };
  void b_key_down() {
    send_msg("b!");
  };
  void b_key_up() {
  };
  void c_key_down() {
    send_msg("c!");
  };
  void c_key_up() {
  };
  void x_key_down() {
    send_msg("x!");
  };
  void x_key_up() {
  };
  void y_key_down() {
    send_msg("y!");
  };
  void y_key_up() {
  };
  void z_key_down() {
    send_msg("z!");
  };
  void z_key_up() {
  };
  void start_key_down() {
    send_msg("stat!");
  };
  void start_key_up() {
  };
  void mode_key_down() {
    send_msg("mode!");
  };
  void mode_key_up() {
  };
private:
  void send_msg(const char *const btn)
  {
    Serial.println(btn);
  }
};
JoypadActions ja = JoypadActions();

static const struct md_pin_setup ps = {
  .D0 = 12,     // (UP key or Z key)
  .D1 = 13,     // (DOWN key ot Y key)
  .D2 = 3,     // (LEFT key or X key)
  .D3 = 8,     // (RIGHT key)
  .D4 = 5,     // (B or A key)
  .SELECT = 6, // (SELECT signal - output    
  .D5 = 7,     // (C or START key)
};

MD_JoypadSix Joypad = MD_JoypadSix(ps, ja);

void setup() {
  Serial.begin(57600);
}

void loop() {
  Joypad.update_states();
  delay(100);


}









