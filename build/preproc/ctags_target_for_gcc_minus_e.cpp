# 1 "c:\\Users\\robot\\Desktop\\state_LED\\State_LED.ino"

//LED port set, just allow "port_1", "port_2", "port_3"




//set emergency switch a-contact or b-contact, only use "NC", "NO"


//set Action_LED lights when logic HIGH or LOW, only use "Positive_logic", "Negative_logic"
# 36 "c:\\Users\\robot\\Desktop\\state_LED\\State_LED.ino"
void setup()
{
 pinMode(2, 0x1 );
 pinMode(1, 0x1 );
 pinMode(0, 0x1 );
    pinMode(4, 0x2 );
    pinMode(3, 0x0 );
    digitalWrite(2, 1);
    digitalWrite(1, 1);
    digitalWrite(0, 1);
}

void loop()
{
 bool EMS_state = digitalRead(3) ^ 0;
    if (EMS_state) {
        digitalWrite(2, 0);
        digitalWrite(1, 0);
        digitalWrite(0, 1);
    }
    else {
        bool ACT_state = digitalRead(4) ^ 1;
        if(ACT_state) {
            digitalWrite(2, 0);
            digitalWrite(1, 1);
            digitalWrite(0, 0);
        }
        else{
            digitalWrite(2, 1);
            digitalWrite(1, 0);
            digitalWrite(0, 0);
        }
    }
}
