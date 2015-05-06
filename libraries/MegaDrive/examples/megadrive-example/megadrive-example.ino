#include <MegaDrive.h>

const int up_led = 13;
const int left_led = 12;
const int down_led = 11;
const int right_led = 10;

class JoypadActions : public MegaDrive_JoypadActions {
    void up_key_down() {
      led_high(up_led);
    };
    void up_key_up() {
      led_low(up_led);
    };
    void down_key_down() {
      led_high(down_led);
    };
    void down_key_up() {
      led_low(down_led);
    };
    void left_key_down() {
      led_high(left_led);
    };
    void left_key_up() {
      led_low(left_led);
    };
    void right_key_down() {
      led_high(right_led);
    };
    void right_key_up() {
      led_low(right_led);
    };
    void a_key_down() {};
    void a_key_up() {};
    void b_key_down() {};
    void b_key_up() {};
    void c_key_down() {};
    void c_key_up() {};
    void start_key_down() {};
    void start_key_up() {};
  private:
    void led_high(const int led) {
      digitalWrite(led, HIGH);
    };
    void led_low(const int led) {
      digitalWrite(led, LOW);
    };
};
JoypadActions ja = JoypadActions();

static const struct mg_pin_setup ps = {
  .D0 = 1,     // (UP key)
  .D1 = 2,     // (DOWN key)
  .D2 = 3,     // (LEFT key)
  .D3 = 4,     // (RIGHT key)
  .D4 = 5,     // (B or A key)
  .SELECT = 6, // (SELECT signal - output)
  .D5 = 7,     // (C or START key)
};

MDThreeBtnsCallbacks MegaDriveEngine = MDThreeBtnsCallbacks(ps, ja);

void setup() {
  pinMode(up_led, OUTPUT);
  pinMode(left_led, OUTPUT);
  pinMode(down_led, OUTPUT);
  pinMode(right_led, OUTPUT);
}

void loop() {
  MegaDriveEngine.update_states();
  delay(20);
}

