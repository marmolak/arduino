#ifndef __MEGADRIVE_H
#define __MEGADRIVE_H

#include <Arduino.h>

struct md_pin_setup {
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

struct md_three_button_state {
	bool up;
	bool down;
	bool left;
	bool right;
	bool a;
	bool b;
	bool c;
	bool start;
};

struct md_six_button_state {
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

static void pin_setup_impl(const struct md_pin_setup &pin_setup)
{
	pinMode(pin_setup.D0, INPUT);
	pinMode(pin_setup.D1, INPUT);
	pinMode(pin_setup.D2, INPUT);
	pinMode(pin_setup.D3, INPUT);
	pinMode(pin_setup.D4, INPUT);
	pinMode(pin_setup.D5, INPUT);
	pinMode(pin_setup.SELECT, OUTPUT);
}

// Abstract prototype
class MD_JoypadActionsThree {
	public:
		virtual void up_key_down() = 0;
		virtual void up_key_up();
		virtual void down_key_down();
		virtual	void down_key_up();
		virtual	void left_key_down();
		virtual	void left_key_up();
		virtual	void right_key_down();
		virtual	void right_key_up();
		virtual	void a_key_down();
		virtual	void a_key_up();
		virtual	void b_key_down();
		virtual	void b_key_up();
		virtual	void c_key_down();
		virtual	void c_key_up();
		virtual	void start_key_down();
		virtual	void start_key_up();
};

class MD_JoypadActionsSix {
	public:
		virtual void up_key_down() = 0;
		virtual void up_key_up();
		virtual void down_key_down();
		virtual	void down_key_up();
		virtual	void left_key_down();
		virtual	void left_key_up();
		virtual	void right_key_down();
		virtual	void right_key_up();
		virtual	void a_key_down();
		virtual	void a_key_up();
		virtual	void b_key_down();
		virtual	void b_key_up();
		virtual	void c_key_down();
		virtual	void c_key_up();
		virtual	void start_key_down();
		virtual	void start_key_up();
		virtual	void x_key_down();
		virtual	void x_key_up();
		virtual	void y_key_down();
		virtual	void y_key_up();
		virtual	void z_key_down();
		virtual	void z_key_up();
};

template<class T> class MegaDriveJoypad {
};

typedef MegaDriveJoypad<struct MD_JoypadActionsThree> MD_JoypadThree;
template<>
class MegaDriveJoypad <struct MD_JoypadActionsThree>
{
	public:
		MegaDriveJoypad(const struct md_pin_setup &pin_setup_p, MD_JoypadActionsThree &joypad_actions_p)
		: pin_setup(pin_setup_p), state(), prev_state(), joypad_actions(joypad_actions_p)
		{
			pin_setup_impl(pin_setup_p);
		}

		void update_states(void);

	private:
		const struct md_pin_setup &pin_setup;
		struct md_three_button_state state;
		struct md_three_button_state prev_state;
		MD_JoypadActionsThree &joypad_actions;
};

typedef MegaDriveJoypad<struct MD_JoypadActionsSix> MD_JoypadSix;
template<>
class MegaDriveJoypad <struct MD_JoypadActionsSix>
{
	public:
		MegaDriveJoypad(const struct md_pin_setup &pin_setup_p, MD_JoypadActionsSix &joypad_actions_p)
		: pin_setup(pin_setup_p), state(), prev_state(), joypad_actions(joypad_actions_p)
		{
			pin_setup_impl(pin_setup_p);
		}

		void update_states(void);

	private:
		const struct md_pin_setup &pin_setup;
		struct md_six_button_state state;
		struct md_six_button_state prev_state;
		MD_JoypadActionsSix &joypad_actions;
};

#endif /* __MEGADRIVE_H */
