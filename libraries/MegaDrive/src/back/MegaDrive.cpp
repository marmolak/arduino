#include <Arduino.h>

#include "MegaDrive.h"

void MegaDrive::pin_setup(const struct mg_pin_setup &ps)
{
	pinMode(ps.D0, INPUT);
	pinMode(ps.D1, INPUT);
	pinMode(ps.D2, INPUT);
	pinMode(ps.D3, INPUT);
	pinMode(ps.D4, INPUT);
	pinMode(ps.D5, INPUT);
	pinMode(ps.SELECT, OUTPUT);
}

void MegaDrive::update_states(void)
{
	digitalWrite(ps.SELECT, LOW);

	call_backs.state.left 	= !digitalRead(ps.D2);
	call_backs.state.right 	= !digitalRead(ps.D3);
	call_backs.state.a 	= !digitalRead(ps.D4);
	call_backs.state.start 	= !digitalRead(ps.D5);

	digitalWrite(ps.SELECT, HIGH);

	call_backs.state.up 	= !digitalRead(ps.D0);
	call_backs.state.down 	= !digitalRead(ps.D1);
	call_backs.state.b 	= !digitalRead(ps.D4);
	call_backs.state.c 	= !digitalRead(ps.D5);

}

# define CALL_FNC(btn) \
	if (call_backs.state.btn && call_backs.btn##_fnc != (void *)0) { \
		call_backs.btn##_fnc(); \
	}

void MegaDrive::update_states_six_call(void)
{
	digitalWrite(ps.SELECT, LOW);

	call_backs_six.state.left 	= !digitalRead(ps.D2);
	call_backs_six.state.right 	= !digitalRead(ps.D3);
	call_backs_six.state.a 	= !digitalRead(ps.D4);
	call_backs_six.state.start 	= !digitalRead(ps.D5);

	digitalWrite(ps.SELECT, HIGH);

	call_backs_six.state.up 	= !digitalRead(ps.D0);
	call_backs_six.state.down 	= !digitalRead(ps.D1);
	call_backs_six.state.b 	= !digitalRead(ps.D4);
	call_backs_six.state.c 	= !digitalRead(ps.D5);

	CALL_FNC(left);
	CALL_FNC(right);
	CALL_FNC(a);
	CALL_FNC(start);

	CALL_FNC(up);
	CALL_FNC(down);
	CALL_FNC(b);
	CALL_FNC(c);
}
