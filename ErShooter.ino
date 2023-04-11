#include <Motor.h>
#include<EspNow.h>

Motor rightMotor(32,33);
Motor leftMotor(26,27);
Peer dataShooter;
Peer remote;
JSONVar feedback;
JSONVar datafeed;
int currentPwm = 0,pwmChange = 5;
int pneumaticPin = 13; 
bool pOpen = true;
static long start = 0;
void setup()
{
    Serial.begin(115200);
    pinMode(13,OUTPUT);
    setId("EShoo");
    remote.init("TenZZ");
    dataShooter.init("DATAZ");
    remote.setOnRecieve(poleOne,"pOne");
    remote.setOnRecieve(poleTwo,"pTwo");
    remote.setOnRecieve(poleThree,"pThr");
    remote.setOnRecieve(incPwm,"up");
    remote.setOnRecieve(decPwm,"down");
    remote.setOnRecieve(resetAll,"shRst");
    remote.setOnRecieve(pneumaticMove,"MOVp");
//    remote.setOnRecieve(pneumaticClose,"pClose");
      leftMotor.invertDirection();
      rightMotor.invertDirection();

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
    datafeed["type"]="cpwm";
    datafeed["curr"]=currentPwm;
    dataShooter.send(datafeed);
}

void decPwm(JSONVar msg)
{
    currentPwm = currentPwm - pwmChange;
    currentPwm = currentPwm < 0 ? 0 : currentPwm;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
    datafeed["type"]="cpwm";
    datafeed["curr"]=currentPwm;
    dataShooter.send(datafeed);
}

void poleOne(JSONVar msg)
{
    currentPwm = 90;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
    datafeed["type"]="cpwm";
    datafeed["curr"]=currentPwm;
    dataShooter.send(datafeed);
}
void poleTwo(JSONVar msg)
{
    currentPwm = 180;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
    datafeed["type"]="cpwm";
    datafeed["curr"]=currentPwm;
    dataShooter.send(datafeed);
}
void poleThree(JSONVar msg)
{
    currentPwm = 255;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
    datafeed["type"]="cpwm";
    datafeed["curr"]=currentPwm;
    dataShooter.send(datafeed);
}

void resetAll(JSONVar msg)
{
    currentPwm = 0;
    rightMotor.setPWM(currentPwm);
    leftMotor.setPWM(currentPwm);
    Serial.println(JSON.stringify(msg));
    Serial.println("CurrentPWM: " +String(currentPwm));
    datafeed["type"]="cpwm";
    datafeed["curr"]=currentPwm;
    dataShooter.send(datafeed);
}

void pneumaticMove(JSONVar msg)
{
//  if (pOpen)
//  {
//    digitalWrite(13, HIGH);
//    Serial.println("close");
//    pOpen = false;
//  }
//  else if (!pOpen)
//  {
//    digitalWrite(13, LOW);
//    Serial.println("open");
//    pOpen = true;
//  }
    start=millis();
    while(millis()-start<1000)
    {
      digitalWrite(13, HIGH);
      Serial.println("close");
    }
    digitalWrite(13,LOW);
    datafeed["type"]="pneu";
    datafeed["move"]="pmove";
    
}
//void pneumaticOpen(JSONVar msg)
//{
//    digitalWrite(pneumaticPin,HIGH);
//    Serial.println(JSON.stringify(msg));
//}
//
//void pneumaticClose(JSONVar msg)
//{
//    digitalWrite(pneumaticPin,LOW);
//    Serial.println(JSON.stringify(msg));
//}
