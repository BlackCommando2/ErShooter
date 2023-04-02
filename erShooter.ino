#include <Motor.h>
#include<EspNow.h>

Motor rightMotor(10, 8);
Motor leftMotor(10, 8);

Peer remote;
JSONVar feedback;
int currentPwm = 0,pwmChange = 10;
void setup()
{
    Serial.begin(115200);
    setId("EShoo");
    remote.init("TenZZ");
    remote.setOnRecieve(poleOne,"pOne");
    remote.setOnRecieve(poleTwo,"pTwo");
    remote.setOnRecieve(poleThree,"pThr");
    remote.setOnRecieve(incPwm,"up");
    remote.setOnRecieve(decPwm,"down");
    remote.setOnRecieve(resetAll,"shRst");
}

void loop()
{
    
}

void incPwm(JSONVar msg)
{
    rightMotor.setPWM(currentPwm + pwmChange);
    leftMotor.setPWM(currentPwm + pwmChange);
}

void decPwm(JSONVar msg)
{
    rightMotor.setPWM(currentPwm - pwmChange);
    leftMotor.setPWM(currentPwm + pwmChange);
}

void poleOne(JSONVar msg)
{
    currentPwm = 90;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
}
void poleTwo(JSONVar msg)
{
    currentPwm = 180;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
}
void poleThree(JSONVar msg)
{
    currentPwm = 255;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
}

void resetAll(JSONVar msg)
{
    currentPwm = 0;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
}
