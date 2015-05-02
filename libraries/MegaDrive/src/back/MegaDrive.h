#ifndef __MEGADRIVE_H
#define __MEGADRIVE_H

#include <Arduino.h>

struct mg_pin_setup {
				// .-----------------.------------------------------.
				// | Pin on joypad   |	Meaning  |  Select state    |
				// |------------------------------------------------|
	unsigned char D0;	// |      1          |  Up       |     1 || 0       |
	unsigned char D1;	// |      2          |  Down     |     1 || 0       |
	unsigned char D2;	// |      3	     |	Left     |     0            |
	unsigned char D3;	// |	  4	     |	Right    |     0            |
				// |	  5	     |  +5V      |		    |
	unsigned char D4;	// |	  6	     |  B || A   |   1 = B; 0 = A   |
	unsigned char SELECT;	// |	  7	     | 		 |		    |
				// |	  8 	     |  GND	 |		    |
	unsigned char D5;	// |      9	     | C || Start| 1 = C; 0 = Start |
				// '------------------------------------------------'
};

struct mg_three_button_state {
	bool up 	: 1;
	bool down 	: 1;
	bool left	: 1;
	bool right	: 1;
	bool a		: 1;
	bool b		: 1;
	bool c		: 1;
	bool start	: 1;
};

struct mg_six_button_state {
	bool up 	: 1;
	bool down 	: 1;
	bool left 	: 1;
	bool right 	: 1;
	bool a 		: 1;
	bool b 		: 1;
	bool c 		: 1;
	bool start 	: 1;
	bool x 		: 1;
	bool y 		: 1;
	bool z 		: 1;
};

struct mg_three_callbacks {
	struct mg_three_button_state state;
	void (*up_fnc)();
	void (*down_fnc)();
	void (*left_fnc)();
	void (*right_fnc)();
	void (*a_fnc)();
	void (*b_fnc)();
	void (*c_fnc)();
	void (*start_fnc)();
};

struct mg_six_callbacks {
	struct mg_six_button_state state;
	void (*up_fnc)();
	void (*down_fnc)();
	void (*left_fnc)();
	void (*right_fnc)();
	void (*a_fnc)();
	void (*b_fnc)();
	void (*c_fnc)();
	void (*start_fnc)();
	void (*x_fnc)();
	void (*y_fnc)();
	void (*z_fnc)();
};


class MegaDrive
{
	public:
		void pin_setup(const struct mg_pin_setup &ps);
		MegaDrive(const struct mg_pin_setup &ps_p)
		: call_backs(), call_backs_six(), ps(ps_p)
		{
			pin_setup(ps_p);
		}

		MegaDrive(const struct mg_pin_setup &ps_p, struct mg_three_callbacks &call_backs_p) 
		: call_backs(call_backs_p), call_backs_six(), ps(ps_p)
		{
			pin_setup(ps_p);
		}

		MegaDrive(const struct mg_pin_setup &ps_p, struct mg_six_callbacks &call_backs_p)
		: call_backs(), call_backs_six(call_backs_p), ps(ps_p)
		{
			pin_setup(ps_p);
		}

		void update_states(void);
		void update_states_six_call(void);

	private:
		struct mg_three_callbacks call_backs;
		struct mg_six_callbacks call_backs_six;
		const struct mg_pin_setup ps;
};

#endif /* __MEGADRIVE_H */