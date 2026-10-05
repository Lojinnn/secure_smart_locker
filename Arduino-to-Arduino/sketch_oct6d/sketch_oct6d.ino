// этот скетч для нано с дисплеем

#include <GyverOLED.h>

GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;




short ad_lock1 = 8; // 8 - младший бит, 9 - старший бит   
short ad_lock2 = 9;
short pin_stat1 = 10; // 10 - младший, 11 - старший
short pin_stat2 = 11;
short read_write = 12;



int cmd; // 0 - 0ячейка открыть. 1 - 1ячейка открыть. 4 - прочитать 0ячейку. 5 - прочитать 1ячейку

int inf1 = 0;
int inf2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(ad_lock1, OUTPUT);
  pinMode(ad_lock2, OUTPUT);
  pinMode(read_write, OUTPUT);

  pinMode(pin_stat1, INPUT_PULLUP);
  pinMode(pin_stat2, INPUT_PULLUP);

  oled.init();
  oled.clear();
  oled.setScale(1);

}

void write(){
  digitalWrite(ad_lock1, 0);
  digitalWrite(ad_lock2, 0);
  digitalWrite(read_write, 1);
  
  delay(30);

  digitalWrite(read_write, 0);
}

void read(){
  inf1 = !digitalRead(pin_stat1);
  inf2 = !digitalRead(pin_stat2);
}

void loop() {
  Serial.println(cmd);
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    cmd = Serial.parseInt();
  }

  if(cmd >=0 and cmd <=3){
    write();
  }

  if(cmd >=4 and cmd <= 5){
    read();

    oled.clear();
    oled.setCursor(1, 1);
    if(inf1 == 1){
      oled.print("Дверь открыта");
    }
    if(inf1 == 0){
      oled.print("Дверь закрыта");
    }

    oled.setCursor(1, 5);
    if(inf2 == 1){
      oled.print("Телефон внутри");
    }
    if(inf2 == 0){
      oled.print("Телефона нет");
    }
  }
}