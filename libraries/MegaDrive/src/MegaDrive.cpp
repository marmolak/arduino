#include <Arduino.h>

#include "MegaDrive.h"

void MegaDrive<mg_three_button_state>::update_states(void)
{
	digitalWrite(ps.SELECT, LOW);

	state.left 	= !digitalRead(ps.D2);
	state.right 	= !digitalRead(ps.D3);
	state.a 	= !digitalRead(ps.D4);
	state.start 	= !digitalRead(ps.D5);

	digitalWrite(ps.SELECT, HIGH);

	state.up 	= !digitalRead(ps.D0);
	state.down 	= !digitalRead(ps.D1);
	state.b 	= !digitalRead(ps.D4);
	state.c 	= !digitalRead(ps.D5);
}

void MegaDrive<mg_six_button_state>::update_states(void)
{
}

# define CALL_FNC(btn) \
	if (state.btn) { \
		if (call_backs_down.btn##_fnc != (void *)0) { \
			call_backs_down.btn##_fnc(); \
		} \
	} else { \
		if (prev_state.btn) { \
			if (call_backs_up.btn##_fnc != (void *)0) { \
				call_backs_up.btn##_fnc(); \
			} \
		} \
	} \
	prev_state.btn = state.btn;
// end of CALL_FNC

void MegaDrive<mg_three_callbacks>::update_states(void)
{
	digitalWrite(ps.SELECT, LOW);

	state.left 	= !digitalRead(ps.D2);
	state.right 	= !digitalRead(ps.D3);
	state.a 	= !digitalRead(ps.D4);
	state.start 	= !digitalRead(ps.D5);

	digitalWrite(ps.SELECT, HIGH);

	state.up 	= !digitalRead(ps.D0);
	state.down 	= !digitalRead(ps.D1);
	state.b 	= !digitalRead(ps.D4);
	state.c 	= !digitalRead(ps.D5);

	CALL_FNC(left);
	CALL_FNC(right);
	CALL_FNC(a);
	CALL_FNC(start);

	CALL_FNC(up);
	CALL_FNC(down);
	CALL_FNC(b);
	CALL_FNC(c);
}

void MegaDrive<mg_six_callbacks>::update_states(void)
{
}
