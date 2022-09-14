#include <Arduino.h>
#line 1 "c:\\Users\\robot\\Desktop\\state_LED\\State_LED.ino"

//LED port set, just allow "port_1", "port_2", "port_3"
#define Power_LED port_1
#define Action_LED port_2
#define EMS_LED port_3

//set emergency switch a-contact or b-contact, only use "NC", "NO"
#define EMS_contact NC

//set Action_LED lights when logic HIGH or LOW, only use "Positive_logic", "Negative_logic"
#define Action_logic Negative_logic








#define port_1 2
#define port_2 1
#define port_3 0

#define NC 0
#define NO 1

#define Positive_logic 0
#define Negative_logic 1




#define ACT_pin 4
#define EMS_pin 3

#line 36 "c:\\Users\\robot\\Desktop\\state_LED\\State_LED.ino"
void setup();
#line 48 "c:\\Users\\robot\\Desktop\\state_LED\\State_LED.ino"
void loop();
#line 36 "c:\\Users\\robot\\Desktop\\state_LED\\State_LED.ino"
void setup()
{
	pinMode(Power_LED, OUTPUT );
	pinMode(Action_LED, OUTPUT );
	pinMode(EMS_LED, OUTPUT );
    pinMode(ACT_pin, INPUT_PULLUP );
    pinMode(EMS_pin, INPUT );
    digitalWrite(Power_LED, 1);
    digitalWrite(Action_LED, 1);
    digitalWrite(EMS_LED, 1);
}

void loop()
{
	bool EMS_state = digitalRead(EMS_pin) ^ EMS_contact;
    if (EMS_state) {
        digitalWrite(Power_LED, 0);
        digitalWrite(Action_LED, 0);
        digitalWrite(EMS_LED, 1);
    }
    else {
        bool ACT_state = digitalRead(ACT_pin) ^ Action_logic;
        if(ACT_state) {
            digitalWrite(Power_LED, 0);
            digitalWrite(Action_LED, 1);
            digitalWrite(EMS_LED, 0);
        }
        else{
            digitalWrite(Power_LED, 1);
            digitalWrite(Action_LED, 0);
            digitalWrite(EMS_LED, 0);
        }
    }
}

