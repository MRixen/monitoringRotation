// Pins for the switches
#define di_m1_s1s2 2
#define di_m2_s1s2 3
#define di_m3_s1s2 4
#define di_m4_s1s2 5
#define di_m5_s1s2 6
#define di_m6_s1s2 7

// Pins for the input pwm values
#define ai_m1_pwm A0
#define ai_m2_pwm A1
#define ai_m3_pwm A2
#define ai_m4_pwm A3
#define ai_m5_pwm A4
#define ai_m6_pwm A5

// Pins for the output pwm values
#define do_m1_pwm 8
#define do_m2_pwm 9
#define do_m3_pwm 10
#define do_m4_pwm 11
#define do_m5_pwm 12
#define do_m6_pwm 13

int pinData_pwm_out[6] = { do_m1_pwm, do_m2_pwm, do_m3_pwm, do_m4_pwm, do_m5_pwm, do_m6_pwm };
int pinData_pwm_in[6] = { ai_m1_pwm, ai_m2_pwm, ai_m3_pwm, ai_m4_pwm, ai_m5_pwm, ai_m6_pwm };

int DELAY_WRITE_READ = 50;

bool debugMode;
bool switchOnOff = true;

void setup()
{
	// Configure serial interface
	Serial.begin(9600);

	// USER CONFIGURATION
	debugMode = true;

	// Define I/Os
	pinMode(di_m1_s1s2, INPUT);
	pinMode(di_m2_s1s2, INPUT);
	pinMode(di_m3_s1s2, INPUT);
	pinMode(di_m4_s1s2, INPUT);
	pinMode(di_m5_s1s2, INPUT);
	pinMode(di_m6_s1s2, INPUT);
}

void loop()
{
	for (int i = 0; i < 6; i++)
	{
		// Set incoming pwm value as output when the switch isnt pushed (incoming signal is high)
		if (digitalRead(di_m1_s1s2) == HIGH) analogWrite(pinData_pwm_out[i], analogRead(pinData_pwm_in[i]));
		else analogWrite(pinData_pwm_out[i], 0);
	}
}
