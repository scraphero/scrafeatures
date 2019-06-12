// Supported by Pablo Hernandez Martinez | @scraphero on github

// PINS
	// Joystick
		const int PIN_JOYSTICK_5V  = 8  ;  // Joystick 5v Supply
		const int PIN_JOYSTICK_GND = 9  ;  // Joystick gnd supply
		const int PIN_JOYSTICK_VRX = A0 ;  // Joystick X Axis input
		const int PIN_JOYSTICK_VRY = A1 ;  // Joystick Y Axis input

// JOYSTICK
	// Const & Variables
		int joystick_x_value = 0 ;
		int joystick_y_value = 0 ;
	// Functions
		// Setup
			void joystick_setup ()
			{
				pinMode(PIN_JOYSTICK_5V, OUTPUT);
				digitalWrite(PIN_JOYSTICK_5V, HIGH);

				pinMode(PIN_JOYSTICK_GND, OUTPUT);
				digitalWrite(PIN_JOYSTICK_GND, LOW);
			}
		// Read
			void joystick_read()
			{
				joystick_x_value = analogRead(PIN_JOYSTICK_VRX);
				joystick_y_value = analogRead(PIN_JOYSTICK_VRY);
			}
		// Debug
			void joystick_debug ()
			{
				Serial.print   (joystick_x_value);
				Serial.print   ("x | ");
				Serial.print   (joystick_y_value);
				Serial.println   ("y");
			}
// SETUP
	void setup()
	{
		Serial.begin(2000000);
		joystick_setup();
	}
// LOOP
	void loop()
	{
		joystick_read();
		joystick_debug();
	}
