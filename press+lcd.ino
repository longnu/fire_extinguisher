#include <Wire.h>
#include <SparkFun_MS5803_I2C.h> 
#include <Arduino.h>      
#include <U8g2lib.h>       
#include <SPI.h>            


MS5803 sensor(ADDRESS_HIGH);

//Create variables to store results
double pressure_abs, pressure_relative, altitude_delta, pressure_baseline;
int lcd_pressure ;
// Create Variable to store altitude in (m) for calculations;


//lcd/////////////////////////////////////////
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);
//lcd/////////////////////////////////////////

void setup() {
  // Start your preferred I2C object
  Wire.begin();
  //Initialize Serial Monitor
  Serial.begin(115200);
  //Retrieve calibration constants for conversion math.
  sensor.reset();
  sensor.begin();

  pressure_baseline = sensor.getPressure(ADC_4096);


  
//lcd/////////////////////////////////////////
   u8g2.begin();       //u8g2 통신을 시작합니다.
//lcd/////////////////////////////////////////
}


void loop() {
  
 
  // Read pressure from the sensor in mbar.
  pressure_abs = sensor.getPressure(ADC_4096);
  int lcd_pressure = (int)pressure_abs;
  

  // Report values via UART  
  Serial.println(lcd_pressure);

  delay(1000);


    u8g2.firstPage();
    do{
        u8g2.setFont(u8g2_font_logisoso28_tr);
        u8g2.setCursor(10, 30);
        u8g2.print(lcd_pressure);
    }while(u8g2.nextPage());


}
