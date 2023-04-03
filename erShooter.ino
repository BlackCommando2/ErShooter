#include <Motor.h>
#include<EspNow.h>

Motor rightMotor(10, 8);
Motor leftMotor(10, 8);

Peer remote;
JSONVar feedback;
int currentPwm = 0,pwmChange = 10;
int pneumaticPin = 32; 
void setup()
{
    Serial.begin(115200);
    pinMode(pneumaticPin,OUTPUT);
    setId("EShoo");
    remote.init("TenZZ");
    remote.setOnRecieve(poleOne,"pOne");
    remote.setOnRecieve(poleTwo,"pTwo");
    remote.setOnRecieve(poleThree,"pThr");
    remote.setOnRecieve(incPwm,"up");
    remote.setOnRecieve(decPwm,"down");
    remote.setOnRecieve(resetAll,"shRst");
    remote.setOnRecieve(pneumaticOpen,"pOpen");
    remote.setOnRecieve(pneumaticClose,"pClose");
}

void loop()
{
    
}

void incPwm(JSONVar msg)
{
    currentPwm = currentPwm + pwmChange;
    currentPwm = currentPwm > 255 ? 255 : currentPwm;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
}

void decPwm(JSONVar msg)
{
    currentPwm = currentPwm - pwmChange;
    currentPwm = currentPwm < 0 ? 0 : currentPwm;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
}

void poleOne(JSONVar msg)
{
    currentPwm = 90;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
}
void poleTwo(JSONVar msg)
{
    currentPwm = 180;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
}
void poleThree(JSONVar msg)
{
    currentPwm = 255;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
}

void resetAll(JSONVar msg)
{
    currentPwm = 0;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
}

void pneumaticOpen(JSONVar msg)
{
    digitalWrite(pneumaticPin,HIGH);
    Serial.println(JSON.stringify(msg));
}

void pneumaticClose(JSONVar msg)
{
    digitalWrite(pneumaticPin,LOW);
    Serial.println(JSON.stringify(msg));
}