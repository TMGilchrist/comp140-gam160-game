//Code adapted from the Adafruit LIS3DH accelerometer example.

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// software SPI
Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);

int inByte;

void setup(void) 
{
  Serial.begin(115200);
  Serial.println("LIS3DH test!");
  
  if (! lis.begin(0x18)) 
  {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  
  Serial.print("Range = "); Serial.print(2 << lis.getRange());  
  Serial.println("G");
}

void loop() 
{
  /* Get a new sensor event, normalized */ 
  sensors_event_t event; 
  lis.getEvent(&event);

  if(Serial.available() > 0)
  {
      inByte = Serial.read();

      if(inByte == 'P')
      {        
        /* Display the results (acceleration is measured in m/s^2) */
        Serial.print(event.acceleration.x); Serial.print(";");
        Serial.print(event.acceleration.y); Serial.print(";");
        Serial.print(event.acceleration.z); Serial.print(";"); Serial.print("Q");
      }    
  }

}
