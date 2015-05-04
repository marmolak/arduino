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
	bool up;
	bool down;
	bool left;
	bool right;
	bool a;
	bool b;
	bool c;
	bool start;
};

struct mg_six_button_state {
	bool up;
	bool down;
	bool left;
	bool right;
	bool a;
	bool b;
	bool c;
	bool start;
	bool x;
	bool y;
	bool z;
};

struct mg_three_callbacks {
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

static void pin_setup(const struct mg_pin_setup &ps)
{
	pinMode(ps.D0, INPUT);
	pinMode(ps.D1, INPUT);
	pinMode(ps.D2, INPUT);
	pinMode(ps.D3, INPUT);
	pinMode(ps.D4, INPUT);
	pinMode(ps.D5, INPUT);
	pinMode(ps.SELECT, OUTPUT);
}

template<class T> class MegaDrive {
};

typedef MegaDrive<struct mg_three_button_state> MDThreeBtnsState;
template<>
class MegaDrive <struct mg_three_button_state>
{
	public:
		MegaDrive(const struct mg_pin_setup &ps_p)
		: state(), ps(ps_p)
		{
			pin_setup(ps_p);
		}

		void update_states(void);

	private:
		struct mg_three_button_state state;
		const struct mg_pin_setup &ps;
};

typedef MegaDrive<struct mg_six_button_state> MDSixBtnsState;
template<>
class MegaDrive <struct mg_six_button_state>
{
	public:
		MegaDrive(const struct mg_pin_setup &ps_p)
		: state(), ps(ps_p)
		{
			pin_setup(ps_p);
		}

		void update_states(void);

	private:
		struct mg_six_button_state state;
		const struct mg_pin_setup &ps;
};

typedef MegaDrive<struct mg_three_callbacks> MDThreeBtnsCallbacks;
template<>
class MegaDrive <struct mg_three_callbacks>
{
	public:
		MegaDrive(const struct mg_pin_setup &ps_p,
				struct mg_three_callbacks &call_backs_up_p,
				struct mg_three_callbacks &call_backs_down_p) 
		: call_backs_up(call_backs_up_p), call_backs_down(call_backs_down_p), ps(ps_p), state(),
		  prev_state()
		{
			pin_setup(ps_p);
		}

		void update_states(void);

	private:
		struct mg_three_callbacks &call_backs_up;
		struct mg_three_callbacks &call_backs_down;
		const struct mg_pin_setup &ps;
		struct mg_three_button_state state;
		struct mg_three_button_state prev_state;
};

typedef MegaDrive<struct mg_six_callbacks> MDSixBtnsCallbacks;
template<>
class MegaDrive <struct mg_six_callbacks>
{
	public:
		MegaDrive(const struct mg_pin_setup &ps_p,
				struct mg_six_callbacks &call_backs_up_p,
				struct mg_six_callbacks &call_backs_down_p
				)
		: call_backs_up(call_backs_up_p), call_backs_down(call_backs_down_p), ps(ps_p), state(),
		  prev_state()
		{
			pin_setup(ps_p);
		}

		void update_states(void);

	private:
		struct mg_six_callbacks &call_backs_up;
		struct mg_six_callbacks &call_backs_down;
		const struct mg_pin_setup &ps;
		struct mg_six_button_state state;
		struct mg_six_button_state prev_state;
};

#endif /* __MEGADRIVE_H */
