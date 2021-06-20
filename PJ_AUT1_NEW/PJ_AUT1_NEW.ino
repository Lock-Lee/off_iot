#include <SoftwareSerial.h>
SoftwareSerial mySerial(A8, A9); // RX, TX
#include <Wire.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <RealTimeClockDS1307.h>
int x = 0;
//จอ LDC 20*4 จอแสดงผล
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); //ถ้าจอไม่แสดงผลให้เปลี่ยน 0x27 เป็น0x3F
int read_num(int nmax, int x, int y);

bool stateph1 = 0;
bool stateph2 = 0;
bool stateph3 = 0;
bool stateTime1 =  0;
bool stateTime2 =  0;
bool stateTime3 =  0;
const byte ROWS = 4; //four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void read_time();
void readKeypad();
char key;
int address = 0;

bool stateph  = false;
int starttimeph_m ;
int starttimeph_h;


int Moisture;
int SoilStartINT = 0;
int SoilENDINT = 0;
int xx1, xx2;

float PH;


int water_state = 0, ph_state = 0;

int PHStartInt;
int PHStartfloat;
int PHEndInt;
int PHEndfloat;

float PHstart;
float PHstop;

int t1 = 0;

int pump1 = 14;
int pump2 = 15;
int pump3 = 16;
int pump4 = 17;

//เซ็นเซอร์วัดความชื้นในดิน Soil Moisture Sensor
int MoistureSensor = A1;

//เซ็นเซอร์วัดค่า PH ในดิน
int PHSensor = A2;




typedef struct  {  // the time record
  int hour;      // hour
  int min;       // minute
  int sec;       // second
} TIMER;
TIMER realTime;
TIMER timeStart1;
TIMER timeEnd1;
TIMER timeStart2;
TIMER timeEnd2;
TIMER timeStart3;
TIMER timeEnd3;
TIMER timePHStart1;
TIMER timePHEnd1;
TIMER timePHStart2;
TIMER timePHEnd2;
TIMER timePHStart3;
TIMER timePHEnd3;

typedef struct  {  // the time record
  String hour;      // hour
  String min;       // minute
  String sec;       // second
} TIME;
TIME RealTime;
TIME SetTimestart1;
TIME SetTimeEnd1;
TIME SetTimestart2;
TIME SetTimeEnd2;
TIME SetTimestart3;
TIME SetTimeEnd3;
TIME SetTimephstart1;
TIME SetTimephEnd1;
TIME SetTimephstart2;
TIME SetTimephEnd2;
TIME SetTimephstart3;
TIME SetTimephEnd3;


//ทำ map ให้เป็นจุดทศนิยม
double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
  return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}



////////////////////////////////////   ตั้งเวลา น้ำ /////////////////////////////////////////////////


void setTime() {
  RTC.setHours(23);
  RTC.setMinutes(3);
  RTC.setSeconds(15);
  RTC.setClock();
}
void show_time(void)  {

  lcd.print(RealTime.hour);
  lcd.print(":");
  lcd.print(RealTime.min);
  lcd.print(":");
  lcd.print(RealTime.sec);
  //  Serial.print(RealTime.hour);
  //  Serial.print(RealTime.min);
  //  Serial.println(RealTime.sec);

  //  Serial.print(realTime.hour);
  //  Serial.print(realTime.min);
  //  Serial.println(realTime.sec);



}

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.setTimeout(100);
  mySerial.setTimeout(100);

  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pump3, OUTPUT);
  pinMode(pump4, OUTPUT);

  lcd.init();
  lcd.backlight();

  
  //setTime();
  getEProm();
}

void loop() {

  //////// รับค่าจาก nodemcu ///////////
  if (mySerial.available()) {
    String received = mySerial.readStringUntil('\n');


    Serial.println(received);
    if (!received.indexOf("phstart=")) {    ///ph
      String str = received.substring(8);
      String part1 = splitOfstrng(str, '.', 0);
      String part2 = splitOfstrng(str, '.', 1);
      
      PHStartInt = part1.toInt();
      PHStartfloat = part2.toInt();
      String phstart  = (String)PHStartInt + "." + PHStartfloat;
      PHstart = phstart.toFloat();



    }
    else if (!received.indexOf("phend=")) {    ///ph
     
      String str = received.substring(6);
      String part1 = splitOfstrng(str, '.', 0);
      String part2 = splitOfstrng(str, '.', 1);



      PHEndInt  = part1.toInt();
      PHEndfloat = part2.toInt();
      String phend  = (String)PHEndInt + "." + PHEndfloat;
      PHstop = phend.toFloat();

    }
    else if (!received.indexOf("humi=")) {
     
      received = received.substring(5);
      String part1 = splitOfstrng(received, ',', 0);
      String part2 = splitOfstrng(received, ',', 1);
      SoilENDINT =  part2.toInt();
      SoilStartINT =  part1.toInt();

      
    }
    else if (!received.indexOf("timephstart1=")) {


      received = received.substring(13);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimephstart1.hour = (String) part1;
      SetTimephstart1.min = (String) part2;
      


    }
    else  if (!received.indexOf("timephEnd1=")) {
      received = received.substring(11);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimephEnd1.hour = part1;
      SetTimephEnd1.min = part2;

      

    }
    else  if (!received.indexOf("timephstart2=")) {
      received = received.substring(13);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimephstart2.hour = (String) part1;
      SetTimephstart2.min = (String) part2;



    }
    else if (!received.indexOf("timephEnd2=")) {
      received = received.substring(11);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimephEnd2.hour = part1;
      SetTimephEnd2.min = part2;



    }
    else if (!received.indexOf("timephstart3=")) {
      received = received.substring(13);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimephstart3.hour = (String) part1;
      SetTimephstart3.min = (String) part2;

   
    }
    else  if (!received.indexOf("timephEnd3=")) {
      received = received.substring(11);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimephEnd3.hour = part1;
      SetTimephEnd3.min = part2;

      Serial.print(SetTimephEnd3.hour);
      Serial.println(SetTimephEnd3.min);
    }
    else if (!received.indexOf("timestart1=")) {
      received = received.substring(11);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimestart1.hour = part1;
      SetTimestart1.min = part2;

      Serial.print( SetTimestart1.hour);
      Serial.print( SetTimestart1.min);


    }
    else if (!received.indexOf("timeEnd1=")) {
      received = received.substring(9);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimeEnd1.hour = part1;
      SetTimeEnd1.min = part2;
      Serial.print( SetTimeEnd1.hour);
      Serial.print( SetTimeEnd1.min);

    }
    else if (!received.indexOf("timestart2=")) {
      received = received.substring(11);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimestart2.hour = part1;
      SetTimestart2.min = part2;
      Serial.print( SetTimestart2.hour);
      Serial.print( SetTimestart2.min);

    }
    else if (!received.indexOf("timeEnd2=")) {
      received = received.substring(9);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimeEnd2.hour = part1;
      SetTimeEnd2.min = part2;
      Serial.print( SetTimeEnd2.hour);
      Serial.print( SetTimeEnd2.min);

    }
    else if (!received.indexOf("timestart3=")) {
      received = received.substring(11);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimestart3.hour = part1;
      SetTimestart3.min = part2;
      Serial.print( SetTimestart3.hour);
      Serial.print( SetTimestart3.min);


    }
    else if (!received.indexOf("timeEnd3=")) {
      received = received.substring(9);
      String part1 = splitOfstrng(received, ':', 0);
      String part2 = splitOfstrng(received, ':', 1);
      SetTimeEnd3.hour = part1;
      SetTimeEnd3.min = part2;
       Serial.print( SetTimeEnd3.hour);
      Serial.print( SetTimeEnd3.min);


    }

  }
  readKeypad();
}
//set time
int read_num(int nmax, int x, int y) {
  int num, i;
  lcd.setCursor(x, y);
  num = 0, i = 0;
  do {
    do {
      key = keypad.getKey();

    } while (!key);
    if (key == '*' && i > 0)  { //check key ''
      x = x - 1;
      lcd.setCursor(x, y);
      lcd.print(" ");
      lcd.setCursor(x, y);
      num = num / 10;
      i = i - 1;
    }

    else if (key != '#' && key != '*') {
      if ((num * 10 + (key - 0x30)) <= nmax) {
        num = num * 10 + (key - 0x30);
        lcd.print(key);
        x = x + 1;
        i = i + 1;
      }
    }
  } while (key != '#');         //&& num !=0);
  return (num);

}



void read_time(void)  {
  RTC.readClock();
  realTime.hour = RTC.getHours();
  realTime.min = RTC.getMinutes();
  realTime.sec = RTC.getSeconds();

  RealTime.hour = (String)realTime.hour;
  RealTime.min = (String)realTime.min;
  RealTime.sec = (String)realTime.sec;
  if (realTime.hour < 10) {
    RealTime.hour = "0" + RealTime.hour;
  }
  if (realTime.min < 10) {
    RealTime.min = "0" + RealTime.min;
  }
  if (realTime.sec < 10) {
    RealTime.sec = "0" + RealTime.sec;
  }




}

void Set_Moisture () {
  unsigned long currentMillis = millis();
  long previousMillis = 0;
  Moisture = show_MoistureSensor();
  if (currentMillis - previousMillis > 3000) {
    previousMillis = currentMillis;
    mySerial.println((String)"Moisture=" + Moisture);
  }

  if (Moisture >= SoilStartINT && Moisture <= SoilENDINT ||( stateTime1 == 1 || stateTime2 == 1  || stateTime3 == 1) ) {
    digitalWrite(pump1, HIGH);
//    Serial.println("Start pump1 " );
  }
  

  else if ((Moisture >= SoilENDINT || Moisture <= SoilStartINT )  && SoilENDINT > 0   &&( stateTime1 == 0 || stateTime2 == 0  || stateTime3 == 0)) {
   digitalWrite(pump1, LOW);
    Serial.println("END pump1 " );
  }

}

void Set_PH() {
  PH = show_PH();
  unsigned long currentMillis = millis();
  long previousMillis = 0;
  if (currentMillis - previousMillis > 2000) {
    previousMillis = currentMillis;
    mySerial.println((String)"PH=" + PH);

  }

  

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //  if (realTime.min == 58) {
  //    stateph = 0;
  //    starttimeph_h += 1;
  //
  //  }
  //  if (starttimeph_h >= 6) {
  //
  //    stateph = 1;
  //
  //  }
  //  Serial.println(stateph);
  //  if (stateph == 1 && starttimeph_h >= 6) {
  //    starttimeph_m += 1;
  //  }
  //
  //  if (starttimeph_m > 100) {
  //
  //    stateph = 0;
  //    starttimeph_h = 0;
  //    starttimeph_m = 0;
  //  }





  stateph = 1;
  if (stateph == 1) {
    if (PHstart < PHstop && PHstop > 0 && PHstart > 0 ) {

      if (PH < PHstart ) {
        digitalWrite(pump2, HIGH);
        Serial.println("Start  pump2 " );
      }

       if (PH > PHstop ) {
        digitalWrite(pump3, HIGH);
        digitalWrite(pump4, HIGH);
        Serial.println("Start pump3 + pump4 " );
      }
     else if ((PH > PHstart && PH < PHstop &&  PHstart > 0 && PHstop > 0) && ( stateph1  == 0 || stateph2 == 0 ||  stateph3  == 0) ) {
         Serial.println("Start pump3 + pump4 " );
        digitalWrite(pump2, 0);
        digitalWrite(pump3, 0);
        digitalWrite(pump4, 0);
      }
    }

  } else {
     Serial.println("Start pump3 + pump4 " );
    digitalWrite(pump2, 0);
    digitalWrite(pump3, 0);
    digitalWrite(pump4, 0);
  }

}

String splitOfstrng(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
