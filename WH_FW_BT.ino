
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU9150.h"
#include "helper_3dmath.h"
#include "SoftwareSerial.h"
#include <Math.h>
#include <SPI.h>


// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69

SoftwareSerial bluetooth(8, 9); //tx, rx

MPU9150 accelGyroMag;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;

const int16_t offsetax = -282;
const int16_t offsetay = 378;
const int16_t offsetaz = -1310;

int16_t softpot0_pin = A0;
int16_t softpot1_pin = A1;
int16_t softpot2_pin = A2;
int16_t softpot3_pin = A3;
int16_t softpot4_pin = A6;

int16_t softpot0_reading;
int16_t softpot1_reading;
int16_t softpot2_reading;
int16_t softpot3_reading;
int16_t softpot4_reading;



char ctrlCMD = 0;


void setup() {

    Wire.begin();
    //Serial.begin(115200);
    bluetooth.begin(9600);
    // initialize device
    accelGyroMag.initialize();

}

void loop() {
    // read raw accel/gyro/mag measurements from device
    accelGyroMag.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
    
    ax -= offsetax;
    ay -= offsetay;
    az -= offsetaz;
    
    softpot0_reading = analogRead(softpot0_pin);
    softpot1_reading = analogRead(softpot1_pin);
    softpot2_reading = analogRead(softpot2_pin);
    softpot3_reading = analogRead(softpot3_pin);
    softpot4_reading = analogRead(softpot4_pin);
    
    if (bluetooth.available())
    {
    ctrlCMD = bluetooth.read();
    bluetooth.flush();
    if (ctrlCMD == 'd') 
    {
      bluetooth.write('#');
      bluetooth.write('#');
      byte * a = (byte *) &ax;
      bluetooth.write(a, 2);
      byte * b = (byte *) &ay;
      bluetooth.write(b, 2);
      byte * c = (byte *) &az;
      bluetooth.write(c, 2);
      byte * d = (byte *) &gx;
      bluetooth.write(d, 2);
      byte * e = (byte *) &gy;
      bluetooth.write(e, 2);
      byte * f = (byte *) &gz;
      bluetooth.write(f, 2);
      byte * g = (byte *) &mx;
      bluetooth.write(g, 2);
      byte * h = (byte *) &my;
      bluetooth.write(h, 2);
      byte * i = (byte *) &mz;
      bluetooth.write(i, 2);
      
      byte * j = (byte *) &softpot0_reading;
      bluetooth.write(j, 2);
      byte * k = (byte *) &softpot1_reading;
      bluetooth.write(k, 2);
      byte * l = (byte *) &softpot2_reading;
      bluetooth.write(l, 2);
      byte * m = (byte *) &softpot3_reading;
      bluetooth.write(m, 2);
      byte * n = (byte *) &softpot4_reading;
      bluetooth.write(n, 2);
      
      }
    }
    

}
