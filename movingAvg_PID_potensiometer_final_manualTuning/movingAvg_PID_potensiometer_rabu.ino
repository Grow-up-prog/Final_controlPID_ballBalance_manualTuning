/*
PROGRAM PEMBACAAN DAN MOVING AVG
Septian Saputra
Pendidikan Teknik Elektro
Universitas Negeri Jakarta
percobaan ke -9
*/

//D =1.71, 2.12

//Pendefinisian servo
#include <Servo.h> //library servo
Servo servo; //variabel nama pada servo
//pendefinisian PIN sensor pada arduino
#define trig 9
#define echo 8
float a;
float b;

//POTENSIOMETER
float sensorValueA = 0;
float sensorValueB = 0;
float sensorValueC = 0;

float A = 0;
float B = 0;
float C = 0;

float n1, n2, n3;

float outputA = 0;
float outputB = 0;
float outputC = 0;

//MOVING-AVG
  const int numReadings = 5;
int readings [numReadings];//  menyimpan  nilai 
int readIndex = 0; //variabel penyimpan nilai
float total = 0; //variabel penjumlahan nilai

//PID 
//00 03 10
//0.19  0.02 8
float priError = 0;
float toError = 0;

void setup() {
  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  servo.attach(4);
  Serial.begin(9600);
  servo.write(84); //86 titik keseimbangan, 86 > kearah kiri (maks kiri 110), 86 < kearah kanan (maks 72)  
}
void loop() {
 
//    a = jarak();
//    Serial.print(a);Serial.println("");
    
    n1 = KP();
    n2 = KI();
    n3 = KD();
   Serial.print(n1);Serial.print(" ");Serial.print(n2);Serial.print(" ");Serial.println(n3);
    PID();
}
