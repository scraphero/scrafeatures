// Supported by Pablo Hernandez Martinez | @scraphero on github

// Librarys
	#include <Servo.h>

// PINS
	// Joystick
		const int PIN_JOYSTICK_5V  = 8  ;  // Joystick 5v Supply
		const int PIN_JOYSTICK_GND = 9  ;  // Joystick gnd supply
		const int PIN_JOYSTICK_VRX = A0 ;  // Joystick X Axis input
		const int PIN_JOYSTICK_VRY = A1 ;  // Joystick Y Axis input

// CONST & VARIABLES
	//Joystick
		int joystick_x_value = 0 ;
		int joystick_y_value = 0 ;	
	// Servo
		int servo_bar_val = 0 ;

// FUNCTIONS
	// Joystick
		// Setup   | call from Arduino Setup
			void joystick_setup ()
			{
				pinMode(PIN_JOYSTICK_5V, OUTPUT);
				digitalWrite(PIN_JOYSTICK_5V, HIGH);

				pinMode(PIN_JOYSTICK_GND, OUTPUT);
				digitalWrite(PIN_JOYSTICK_GND, LOW);
			}
		// Read    | call when joystick position is desired
			void joystick_read()
			{
				joystick_x_value = analogRead(PIN_JOYSTICK_VRX);
				joystick_x_value = joystick_x_value +2 ;

				joystick_y_value = analogRead(PIN_JOYSTICK_VRY);
			}
		// Debug   | call for serial printing X and Y axes values
			void joystick_debug ()
			{
				Serial.print   (joystick_x_value);
				Serial.print   ("x | ");
				Serial.print   (joystick_y_value);
				Serial.print   ("y | ");
			}
	
	// Joystick > Servo | Joystick to servo interaction
		void joystick_servo ()
		{
			servo_bar_val = map(joystick_x_value, 0, 1023, 0, 180);
		}

	// Servo
		Servo servo_bar;   // Created servo object
		// Setup   | call from Arduino Setup
			void servo_setup ()
			{
				servo_bar.attach(3);
			}
		// Actuate | call for Servo actuation
			void servo_actuate ()
			{
				servo_bar_val = constrain(servo_bar_val, 0, 176);
				servo_bar.write(servo_bar_val);
			}
		// Debug
			void servo_debug ()
			{
				Serial.print(servo_bar_val);
				Serial.print   ("° | ");
			}

// ARDUINO SETUP
	void setup()
	{
		Serial.begin(2000000);
		joystick_setup();
		servo_setup();
	}
// ARDUINO LOOP
	void loop()
	{
		joystick_read();
		joystick_debug();  // DEBUG for joystick values
		joystick_servo();  //
		servo_actuate();   //
		servo_debug();     // DEBUG for servo value
		Serial.println();  // line break after all debug prints, coment this line if debug prints are disabled.
	}
