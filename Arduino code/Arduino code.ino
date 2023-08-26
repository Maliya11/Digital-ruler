#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <MPU6050_light.h> 
#include <ClickEncoder.h>
#include <TimerOne.h>
#include "Adafruit_VL53L0X.h"

MPU6050 mpu(Wire); 
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
LiquidCrystal_I2C lcd(0x27, 16, 2);

int menuItem = 1;
int subMenuItem = 1;
int frame = 1;
int page = 1;
int lastMenuItem = 1;
int lastSubMenuItem = 1;
int subFrame = 1;

String menuItem1 = "Wheel mode";
String menuItem2 = "Laser mode";
String menuItem3 = "Angle";
String menuItem4 = "Battery level";
String subMenuItem1 = "m";
String subMenuItem2 = "cm";
String subMenuItem3 = "back";
// String submenuitem4 = "ft";
// String submenuitem5 = "m";s

boolean up = false;
boolean down = false;
boolean middle = false;

ClickEncoder *encoder;
int16_t last, value;

unsigned long timer = 0;    

void setup() {
  Serial.begin(9600);
  pinMode(11,INPUT);
  encoder = new ClickEncoder(A2, A1, A3);
  encoder->setAccelerationEnabled(false);
  Wire.begin();     
  mpu.begin(); 
  mpu.calcGyroOffsets();
  lcd.init();
  lcd.backlight();  
  Wire.begin();     
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("STARTING.");
  delay(1000);
  lcd.clear();
  lcd.print("STARTING..");
  delay(1000);
  lcd.clear();
  lcd.print("STARTING...");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("   Main Menu   ");
  delay(3000);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr); 
  
  last = encoder->getValue();
}

void loop() {
  drawMenu();
  readRotaryEncoder();

  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
   switch (b) {
      case ClickEncoder::Clicked:
        middle=true;
        break;
    }
  }

  if (up && page == 1) {
     
    up = false;
    if(menuItem==2 && frame ==2)
    {
      frame--;
    }
    if(menuItem==3 && frame ==3)
    {
      frame--;
    }
    lastMenuItem = menuItem;
    menuItem--;
    if (menuItem==0)
    {
      menuItem=1;
    }

  }
  
  else if (up && page == 2){
    up = false;
    if(subMenuItem==2 && subFrame == 2)
    {
      subFrame--;
    }
    lastSubMenuItem = subMenuItem;
    subMenuItem--;
    if (subMenuItem==0)
    {
      subMenuItem=1;
    }
  }

  if (down && page == 1) //We have turned the Rotary Encoder Clockwise
  {

    down = false;
    if(menuItem==2 && lastMenuItem == 1)
    {
      frame ++;
    }else  if(menuItem==3 && lastMenuItem == 2)
    {
      frame ++;
    }
    lastMenuItem = menuItem;
    menuItem++;  
    if (menuItem==5) 
    {
      menuItem--;
    }
  }

  else if (down && page == 2){
    down = false;
    if(subMenuItem==2 && subFrame == 1)
    {
      subFrame++;
    }
    lastSubMenuItem = subMenuItem;
    subMenuItem++;
    if (subMenuItem==4)
    {
      subMenuItem=3;
    }
  }
  

  if (middle) //Middle Button is Pressed
  {
    middle = false;

    if (page == 1 && (menuItem==1 || menuItem==2))
     {
      page=2;
     }
    else if(page == 2 && menuItem == 1 && (subMenuItem==1 || subMenuItem==2)) 
     {
      wheel_mode();
     }
    else if(page == 2 && menuItem == 2 && (subMenuItem==1 || subMenuItem==2))
    {
      laser_mode();
    }
    else if(page==2 && (menuItem==1||menuItem==2) && subMenuItem==3){
      page = 1;
      frame = 1;
      menuItem = 1;
      lastMenuItem = 1;
    }
    else if(page == 1 && menuItem == 3)
    {
      angle_val();
    }
    else if(page == 1 && menuItem == 4)
    {
      battery_level();
    }
   }
}

void timerIsr() {
  encoder->service();
}

void drawMenu()
  {
    
  if (page==1) 
  {    

    if(menuItem==1 && frame ==1)
    { 
      lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
      displayMenuItem(menuItem1, 0,true);
      displayMenuItem(menuItem2, 1,false);
    }
    else if(menuItem == 2 && frame == 1)
    {
      lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
      displayMenuItem(menuItem1, 0,false);
      displayMenuItem(menuItem2, 1,true);
    }
     else if(menuItem == 2 && frame == 2)
    {
      lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
      displayMenuItem(menuItem2, 0,true);
      displayMenuItem(menuItem3, 1,false);
    }

      else if(menuItem == 3 && frame == 2)
    {
      lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
      displayMenuItem(menuItem2, 0,false);
      displayMenuItem(menuItem3, 1,true);
    }
    
    else if(menuItem == 3 && frame == 3)
    {
      lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
      displayMenuItem(menuItem3, 0,true);
      displayMenuItem(menuItem4, 1,false);
    }

    else if(menuItem == 4 && frame == 3)
    {
      lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
      displayMenuItem(menuItem3, 0,false);
      displayMenuItem(menuItem4, 1,true);
    }
  }

  else if (page==2 && subFrame == 1 && subMenuItem == 1) 
  {    
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    displayMenuItem(subMenuItem1, 0,true);
    displayMenuItem(subMenuItem2, 1,false);
  }

  else if (page==2 && subFrame == 1 && subMenuItem == 2) 
  {
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    displayMenuItem(subMenuItem1, 0,false);
    displayMenuItem(subMenuItem2, 1,true);
  }

  else if (page==2 && subFrame == 2 && subMenuItem == 2) 
  {
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    displayMenuItem(subMenuItem2, 0,true);
    displayMenuItem(subMenuItem3, 1,false);
  }

  else if (page==2 && subFrame == 2 && subMenuItem == 3) 
  {
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    displayMenuItem(subMenuItem2, 0,false);
    displayMenuItem(subMenuItem3, 1,true);
  }
}

void displayMenuItem(String item, int position, boolean selected)
{
    if(selected)
    {
      lcd.setCursor(0, position);
      lcd.print("X"+item);
    }else
    {
      lcd.setCursor(0, position);
      lcd.print(">"+item);
    }
    
}

void readRotaryEncoder()
{
  value += encoder->getValue();
  
  if (value/2 > last) {
    last = value/2;
    down = true;
    delay(150);
  }else   if (value/2 < last) {
    last = value/2;
    up = true;
    delay(150);
  }
}

void angle_val(){
  while(!middle){

  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
   switch (b) {
      case ClickEncoder::Clicked:
        middle=true;
        break;
    }
  }
  mpu.update();    //Get values from MPU

  if ((millis() - timer) > 100) { // print data every 100ms
    timer = millis();
    lcd.clear();
    lcd.print(" Angle X: ");
    lcd.print(int(mpu.getAngleX()));     //Print Z angle value on LCD 
    lcd.setCursor(0, 1);
    lcd.print(" Angle Y: ");
    lcd.print(int(mpu.getAccAngleY()));
    delay(10);
    }
  }
  middle=false;
}

void wheel_mode(){
  int distance = 0;
  while(!middle){
  
    ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
   switch (b) {
      case ClickEncoder::Clicked:
        middle=true;
        break;
    }
  }

    lcd.clear();
    int ifRead = digitalRead(11);  
    if(ifRead==1){
      distance += 1;
    }
    lcd.clear();
    lcd.print("Distance (cm)");
    lcd.setCursor(0, 1);
    lcd.print(distance);    
  }
  middle = false;
}

void laser_mode(){

    // wait until serial port opens for native USB devices
  while (!Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 


  while(!middle){
  
  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
   switch (b) {
      case ClickEncoder::Clicked:
        middle=true;
        break;
    }
  }

  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    lcd.clear();
    lcd.print("Distance (mm)");
    lcd.setCursor(0, 1);
    lcd.print(measure.RangeMilliMeter);
  } else {
    lcd.clear();
    lcd.print("Distance (mm)");
    lcd.setCursor(0, 1);
    lcd.print(" out of range ");
  }
    
  delay(500);
  }

  middle = false;
}

void battery_level(){

  while(!middle){

  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
   switch (b) {
      case ClickEncoder::Clicked:
        middle=true;
        break;
    }
  }

  int val = analogRead(A0);
  int voltage = map(val,0,800,2,3.7);
  int voltage_perc = ((voltage-2)/1.7)*100;
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Battery:");
  lcd.setCursor(0,1);
  lcd.print(voltage_perc);
  lcd.setCursor(2, 1);
  lcd.print("%");

  }
  middle = false;
}
