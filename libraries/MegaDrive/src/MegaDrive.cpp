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
	if (call_backs.state.btn && call_backs.btn##_fnc != (void *)0) { \
		call_backs.btn##_fnc(); \
	}

void MegaDrive<mg_three_callbacks>::update_states(void)
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
