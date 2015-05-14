#include <Arduino.h>

#include "MegaDrive.h"


# define CALL_FNC(btn) \
	if (state.btn) { \
		joypad_actions.btn##_key_down(); \
	} else { \
		if (prev_state.btn) { \
			joypad_actions.btn##_key_up(); \
		} \
	} \
	prev_state.btn = state.btn;
// end of CALL_FNC

void MegaDriveJoypad<MD_JoypadActionsThree>::update_states(void)
{
	digitalWrite(pin_setup.SELECT, LOW);

	state.a 	= !digitalRead(pin_setup.D4);
	state.start 	= !digitalRead(pin_setup.D5);

	digitalWrite(pin_setup.SELECT, HIGH);

	state.left 	= !digitalRead(pin_setup.D2);
	state.right 	= !digitalRead(pin_setup.D3);
	state.up 	= !digitalRead(pin_setup.D0);
	state.down 	= !digitalRead(pin_setup.D1);
	state.b 	= !digitalRead(pin_setup.D4);
	state.c 	= !digitalRead(pin_setup.D5);

	CALL_FNC(left);
	CALL_FNC(right);
	CALL_FNC(a);
	CALL_FNC(start);

	CALL_FNC(up);
	CALL_FNC(down);
	CALL_FNC(b);
	CALL_FNC(c);
}

void MegaDriveJoypad<MD_JoypadActionsSix>::update_states(void)
{
	state.up 	= !digitalRead(pin_setup.D0);
	state.left 	= !digitalRead(pin_setup.D2);
	state.b 	= !digitalRead(pin_setup.D4);
	state.c 	= !digitalRead(pin_setup.D5);
	state.right 	= !digitalRead(pin_setup.D3);

	digitalWrite(pin_setup.SELECT, LOW);

	state.a 	= !digitalRead(pin_setup.D4);
	state.start 	= !digitalRead(pin_setup.D5);
	state.down 	= !digitalRead(pin_setup.D1);

	// Pulse...
	digitalWrite(pin_setup.SELECT, HIGH);
	digitalWrite(pin_setup.SELECT, LOW);
	digitalWrite(pin_setup.SELECT, HIGH);
	digitalWrite(pin_setup.SELECT, LOW);
	digitalWrite(pin_setup.SELECT, HIGH);

	state.z		= !digitalRead(pin_setup.D0);
	state.y		= !digitalRead(pin_setup.D1);
	state.x		= !digitalRead(pin_setup.D2);
	state.mode	= !digitalRead(pin_setup.D3);

	CALL_FNC(left);
	CALL_FNC(right);
	CALL_FNC(a);
	CALL_FNC(start);

	CALL_FNC(up);
	CALL_FNC(down);
	CALL_FNC(b);
	CALL_FNC(c);

	CALL_FNC(x);
	CALL_FNC(y);
	CALL_FNC(z);
	CALL_FNC(mode);
}
