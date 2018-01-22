/* Tugas EL3013 Sistem Instrumentasi
 * Light Intensity Sensor (Photoresistor)
 * Contributors : 
 *               1. Bobbi Winema Yogatama (13214071)
 *               2. Nur Laila (13214042)
 *			     3. Jhonson Lee (13214011)
 */ 

/* File Header */
#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Program Utama */
void setup() { 
  lcd.begin(16, 2);
  lcd.print("---Lux  Meter---");
  delay(2000);
  lcd.clear();
  lcd.print("Initialization");
  lcd.print(".");
  delay(1000);
  lcd.print(".");  
  delay(3000);
  Serial.begin(9600);
}

/*  */
void loop()
{
 int sensorValue = analogRead(A0);
 double sV = double(sensorValue)*5.00/1023;
 lcd.setCursor(0, 0);
 double le;
 
 if((sensorValue >= 0) && (sensorValue <= 27))
 {
 le = (546.5012*(pow(0.034776,sV)));
 }
 else if((sensorValue >= 27) && (sensorValue <= 71))
 {
 le = (462.39245*(pow(0.131706,sV)));
 }
 else if((sensorValue >= 71) && (sensorValue <= 150))
 {
 le = (442.7675*(pow(0.14712,sV)));
 }
 else if((sensorValue >= 150) && (sensorValue <= 259))
 {
 le = (397.2244*(pow(0.18955,sV)));
 }
 else if((sensorValue >= 259) && (sensorValue <= 638))
 {
 le = (190.1829*(pow(0.26844,sV)));
 }
 else if((sensorValue >= 638) && (sensorValue <= 921))
 {
 le = (-2.174*sV)+9.7826;
 }
 else
 {
  lcd.print("ERROR");
  delay(500);
  lcd.clear();
 }

 int level = le;
 
 Serial.println(le);
 Serial.println(sV);
 Serial.println();
 delay(1);        // delay in between reads for stability

 /* Output LCD */
 lcd.print("level :");
 lcd.print(level);
 lcd.print("  lux");
 lcd.setCursor(0, 1);
 if ((level >= 0) && (level <= 10))
 {
  lcd.print("Not Ideal"); 
 }
 else if ((level > 10) && (level <= 40))
 {
  lcd.print("Fairly Ideal"); 
 }
 else if ((level > 40) && (level <= 200))
 {
  lcd.print("Ideal"); 
 }
 else if ((level > 200) && (level <= 500))
 {
  lcd.print("Fairly Ideal");
 }
 else 
 {
  lcd.print("Not Ideal"); 
 }
 
 delay(1000); 
 lcd.clear();
 
}


