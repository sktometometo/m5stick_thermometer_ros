#include <M5StickC.h>
#include <Wire.h>

#include <ros.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;

std_msgs::Float32 temp_msg;
ros::Publisher publisher("temperature", &temp_msg);

uint16_t result;
float temperature;
float temperature_display;
bool state = true;
uint8_t btn = HIGH, btn_pre = HIGH;

void setup() {
  M5.begin();
  Wire.begin(0,26);

  M5.Lcd.setRotation(3);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 40);

  pinMode( 37, INPUT_PULLUP );

  nh.initNode();
  nh.advertise(publisher);
}

void loop() {
  btn_pre = btn;
  btn = digitalRead( 37 );

  Wire.beginTransmission(0x5A);          // Send Initial Signal and I2C Bus Address
  Wire.write(0x07);                      // Send data only once and add one address automatically.
  Wire.endTransmission(false);           // Stop signal
  Wire.requestFrom(0x5A, 2);             // Get 2 consecutive data from 0x5A, and the data is stored only.
  result = Wire.read();                  // Receive DATA
  result |= Wire.read() << 8;            // Receive DATA
  
  temperature = result * 0.02 - 273.15;

  temp_msg.data = temperature;
  publisher.publish( &temp_msg );
  nh.spinOnce();

  if ( btn_pre == HIGH and btn == LOW ) {
      state = not state;
  }

  if ( state ) {
      temperature_display = temperature;
  }
  
  M5.Lcd.fillRect(0,40,120,100,BLACK);
  M5.Lcd.setCursor(0, 40);
  
  M5.Lcd.print(temperature_display);

  delay(100);
  M5.update();
}
