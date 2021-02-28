#include <Servo.h>
#include <LiquidCrystal.h>

Servo servo_radar;

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

const int signal_pin = 13;

int vl_distance;
long vl_time;
const int sound_speed = 0.0343;

void setup() {
  servo_radar.attach(3);

  lcd.begin(16, 2);

  lcd.setCursor(3, 0);
  lcd.print("Welcome to");
  delay(1000);

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("ST4RK");
  lcd.setCursor(1, 1);
  lcd.print("Distance Meter");
  delay(2500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Loading.");
  delay(500);

  lcd.clear();
  lcd.print("Loading..");
  delay(1000);
  lcd.clear();

  lcd.print("Loading...");
  delay(1500);
  lcd.clear();

}

void loop() {

  for (int j = 15; j <= 165; j++) {
    servo_radar.write(j);
    delay(10);

    vl_distance = calc_distance();

    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(vl_distance);
    lcd.print("cm");
    delay(10);
  }

  for (int j = 165; j >= 15; j--) {
    servo_radar.write(j);
    delay(10);

    vl_distance = calc_distance();

    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(vl_distance);
    lcd.print("cm");
    delay(100);

  }
}

int calc_distance() {
  pinMode(signal_pin, OUTPUT);

  digitalWrite(signal_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(signal_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(signal_pin, LOW);

  pinMode(signal_pin, INPUT);
  vl_time = pulseIn(signal_pin, HIGH);

  //Converts time to distance
  vl_distance = vl_time / 29 / 2;

  return vl_distance, distanceIn;
}