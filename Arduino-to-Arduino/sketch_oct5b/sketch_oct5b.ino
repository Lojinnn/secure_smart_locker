//скетч для унки
short ad_lock1 = 8; // 8 - младший бит, 9 - старший бит   
short ad_lock2 = 9;
short pin_stat1 = 10; // 10 - младший, 11 - старший
short pin_stat2 = 11;
short read_write = 12;

int adress1 = 0;
int adress2 = 0;
int inf1 = 0;
int inf2 = 0;

int tele = 6;
int door = 7;

int read_write_state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ad_lock1, INPUT_PULLUP);
  pinMode(ad_lock2, INPUT_PULLUP);
  pinMode(read_write, INPUT_PULLUP);

  pinMode(pin_stat1, OUTPUT);
  pinMode(pin_stat2, OUTPUT);

  pinMode(tele, INPUT);
  pinMode(door, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}



void loop() {
  adress1 = digitalRead(ad_lock1);
  adress2 = digitalRead(ad_lock2);
  read_write_state = digitalRead(read_write);

  if(adress1 == 0 && adress2 == 0 && read_write_state == 0){
    digitalWrite(13, 1);
  }
  else{
    digitalWrite(13, 0);
  }

  digitalWrite(pin_stat2, digitalRead(tele));
  digitalWrite(pin_stat1, digitalRead(door));

}
