#include <LiquidCrystal.h>
int red = 9;
int green = 10;
int blue = 11;
int buzzer = A5;
int sayac = 0;

String serialData = String(10);
String cmd = String(10);
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
 void setup() {
  Serial.setTimeout(100);
  Serial.begin(115200);
  lcd.begin(16, 2);
  delay(50);
  lcd.setCursor(0, 0);
  lcd.print(" GEDIZ BILSEM ");
  lcd.setCursor(0, 1);
  lcd.print("Ardunio Y-Z");
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(buzzer, HIGH);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
 }
void loop(){
if (Serial.available() > 0)
{
  serialData = Serial.readString();
  Serial.println(serialData);
  serialData.toLowerCase();
  serialData.trim();
 
  if (serialData == "kadin")
  {
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("    KADIN    ");
    lcd.setCursor(0, 1);
    lcd.print(" GECIS UYGUN ");
    delay(500);
    digitalWrite(buzzer, HIGH);
    delay(5000);
    digitalWrite(green, LOW);
}
else if (serialData == "erkek")
{
 digitalWrite(red, HIGH);
  digitalWrite(buzzer, LOW);
  lcd.setCursor(0, 0);
  lcd.print("     ERKEK      ");
    lcd.setCursor(0, 1);
    lcd.print("  GECIS KAPALI  ");
    for (sayac=0; sayac<10; sayac++);
    {
      delay(250);
      digitalWrite(buzzer, HIGH);
      digitalWrite(red, HIGH);
      delay(250);
      digitalWrite(buzzer, HIGH);
      digitalWrite(red, LOW);
    }
    delay(2000);
    digitalWrite(buzzer, HIGH);
}
else if (serialData == "none")
{
  digitalWrite(buzzer, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  lcd.setCursor(0, 0);
  lcd.print( "GEDIZ BILSEM" );
  lcd.setCursor(0, 1);
  lcd.print("Tespit Edilmedi");
  delay(250);
  digitalWrite(blue, LOW);
  delay(250);

    }
  }
}











