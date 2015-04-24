/* Blink three diodes:
  1 0 0 <--.
  0 1 0    |
  0 0 1    |
  0 1 0    |
  jump ----'
*/

int led = 13;
int led2 = led - 1;
int led3 = led2 - 1;

int blink_delay = 200;

void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(led2, OUTPUT);     
  pinMode(led3, OUTPUT);     
}

void loop() {
	int p = 0;
	for (; p < 3; ++p) {
		digitalWrite(led - p, HIGH);
		delay(blink_delay);              
		digitalWrite(led - p, LOW);
		delay(blink_delay);
	}

        for (p -= 2; p >= 1; --p) {
		digitalWrite(led - p, HIGH);
		delay(blink_delay);
		digitalWrite(led - p, LOW);
		delay(blink_delay);
	}
}
