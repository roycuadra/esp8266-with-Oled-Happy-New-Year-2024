#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int xPos = 0;      
int yPos = 20;     
int xSpeed = 2;   
int ySpeed = 2;    
int textRed = 255; 
int textGreen = 255; 
int textBlue = 255; 

// LED pins
int led1 = 16;
int led2 = 14;
int led3 = 12;

void setup() {
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;)
      ;
  }
  delay(2000);

  display.setFont(&FreeSerif9pt7b);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(xPos, yPos);
  display.println("HAPPY NEW");
  display.println("YEAR 2024");
  display.display();
  delay(2000);
}

void loop() {
  // Clear the display
  display.clearDisplay();
  display.setCursor(xPos, yPos);
  display.setTextColor(SSD1306_WHITE);
  display.println("HAPPY NEW");
  display.println("YEAR 2024");
  display.display();

  // LED effects
  ledEffect(led1, 1);  
  ledEffect(led2, 2);  
  ledEffect(led3, 3); 
  delay(500);
}


void updateTextColor() {
  
  textRed = random(256);
  textGreen = random(256);
  textBlue = random(256);
}

void ledEffect(int ledPin, int effect) {
  switch (effect) {
    case 1:
   
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
      break;
    case 2:
    
      for (int i = 0; i <= 255; i += 5) {
        analogWrite(ledPin, i);
        delay(20);
      }
      for (int i = 255; i >= 0; i -= 5) {
        analogWrite(ledPin, i);
        delay(20);
      }
      break;
    case 3:
    
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
      break;
    case 4:
      
      digitalWrite(ledPin, HIGH);
      delay(random(50, 500)); 
      digitalWrite(ledPin, LOW);
      delay(random(50, 500));
      break;
    case 5:
    
      for (int i = 0; i < 256; i++) {
        analogWrite(ledPin, i);
        delay(10);
      }
      for (int i = 255; i >= 0; i--) {
        analogWrite(ledPin, i);
        delay(10);
      }
      break;
  }
}
