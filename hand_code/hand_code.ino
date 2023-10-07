#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2,3); //RX, TX

#include <Wire.h>

const int MPU = 0X68; //I2C address of the MPU6050 accelerometer
int16_t AcX, AcY, AcZ;

int flag = 0;

void setup () {
  Serial.begin(9600);
  BT_Serial.begin(9600);

  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  delay(500);  
}

void loop() {
  Read_accelerometer();

  if (AcX<60 && flag == 0){ flag = 1; BT_Serial.write('f');  } //FRONT
  if (AcX>130 && flag == 0){ flag = 1; BT_Serial.write('b'); } //BACK
  
  if (AcY<60 && flag == 0){ flag = 1; BT_Serial.write('l'); } //LEFT 
  if (AcY>130 && flag == 0){ flag = 1; BT_Serial.write('r'); } //RIGHT 

  if ( (AcX>70) && (AcX<120) && (AcY>70) && (AcY<120) && (flag == 1) ){
    flag = 0;
    BT_Serial.write('s');
  }

  delay(100);
   
}

void Read_accelerometer(){
    //Read acceleromet data

    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU,6, true);

    AcX = Wire.read() << 8 | Wire.read(); //X-axis value
    AcY = Wire.read() << 8 | Wire.read(); //Y-axis value
    AcZ = Wire.read() << 8 | Wire.read(); //Z-axis value

    AcX = map(AcX, -17000, 17000, 0, 180);
    AcY = map(AcY, -17000, 17000, 0, 180);
    AcZ = map(AcZ, -17000, 17000, 0, 180);

    Serial.print(AcX);
    Serial.print("\t");
    Serial.print(AcY);
    Serial.print("\t");
    Serial.print(AcZ);

}
