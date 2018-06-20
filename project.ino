#include <SoftwareSerial.h>


SoftwareSerial BTserial(2, 3); // RX | TX


int LED_G = 13;
char c = ' ';
void setup(){
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    BTserial.begin(9600);
    // HC-05 default serial speed for commincation mode is 9600
    pinMode(LED_G, OUTPUT);
}


void loop(){
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available()){
        String Data = "";
        c = BTserial.read();
        Data.concat(c);
        BTserial.println(c);
    }else{
        BTserial.println("Não disponivel");
    }
    if (c == 'H'){
        BTserial.println(c);
        digitalWrite(LED_G, HIGH);
        BTserial.println("GREEN LED IS ON");
    }else{
        if (c == 'L'){
            BTserial.println(c);
            digitalWrite(LED_G, LOW);
            BTserial.println("GREEN LED IS OFF");
        }
    }
}
