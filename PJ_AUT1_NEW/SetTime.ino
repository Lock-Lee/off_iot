void setTimeStart1(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time1();
  lcd.cursor();
  timeStart1.hour = read_num(23, x, y);
  Show_Time1();
  timeStart1.min = read_num(59, x + 3, y);
  Show_Time1();
  Serial.println((String)"timeStart1="+timeStart1.hour+":"+timeStart1.min);
  Serial.print(timeStart1.hour);
  Serial.println(timeStart1.min);
  lcd.noCursor();
  if (timeStart1.hour < 10) {
    SetTimestart1.hour = (String)"0" + timeStart1.hour;
  }
  if (timeStart1.min < 10) {
    SetTimestart1.min = (String)"0" + timeStart1.min;
  }

  else {
    SetTimestart1.hour = (String)timeStart1.hour;
    SetTimestart1.min = (String)timeStart1.min;

  }

}
void setTimeEnd1(int x, int y) {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time1();
  lcd.cursor();
  timeEnd1.hour = read_num(23, x, y);
   Show_Time1();
  timeEnd1.min = read_num(59, x + 3, y );
   Show_Time1();
 Serial.println((String)"timeEnd1="+timeEnd1.hour+":"+timeEnd1.min);
  lcd.noCursor();
  if (timeEnd1.hour < 10) {
    SetTimeEnd1.hour = (String)"0" + timeEnd1.hour;
  }
  if (timeEnd1.min < 10) {
    SetTimeEnd1.min = (String)"0" + timeEnd1.min;
  }

  else {
    SetTimeEnd1.hour = (String)timeEnd1.hour;
    SetTimeEnd1.min = (String)timeEnd1.min;

  }
}
void setTimeStart2(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time2();
  lcd.cursor();
  timeStart2.hour = read_num(23, x, y);
   Show_Time2();
  timeStart2.min = read_num(59, x + 3, y);
   Show_Time2();
Serial.println((String)"timeStart2="+timeStart2.hour+":"+timeStart2.min);
  lcd.noCursor();

  if (timeStart2.hour < 10) {
    SetTimestart1.hour = (String)"0" + timeStart1.hour;
  }
  if (timeStart2.min < 10) {
    SetTimestart2.min = (String)"0" + timeStart1.min;
  }

  else {
    SetTimestart2.hour = (String)timeStart2.hour;
    SetTimestart2.min = (String)timeStart2.min;

  }

}
void setTimeEnd2(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time2();
  lcd.cursor();
  timeEnd2.hour = read_num(23, x, y);
   Show_Time2();
  timeEnd2.min = read_num(59, x + 3, y);
   Show_Time2();
Serial.println((String)"timeEnd2="+timeEnd2.hour+":"+timeEnd2.min);
  lcd.noCursor();
  if (timeEnd2.hour < 10) {
    SetTimeEnd2.hour = (String)"0" + timeEnd2.hour;
  }
  if (timeEnd2.min < 10) {
    SetTimeEnd2.min = (String)"0" + timeEnd2.min;
  }

  else {
    SetTimeEnd2.hour = (String)timeEnd2.hour;
    SetTimeEnd2.min = (String)timeEnd2.min;

  }
}
void setTimeStart3(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time3();
  lcd.cursor();
  timeStart3.hour = read_num(23, x, y);
  Show_Time3();
  timeStart3.min = read_num(59, x + 3, y);
  Show_Time3();
  Serial.println((String)"timeStart3="+timeStart3.hour+":"+timeStart3.min);
  lcd.noCursor();
  if (timeStart3.hour < 10) {
    SetTimestart3.hour = (String)"0" + timeStart1.hour;
  }
  if (timeStart3.min < 10) {
    SetTimestart3.min = (String)"0" + timeStart1.min;
  }

  else {
    SetTimestart3.hour = (String)timeStart3.hour;
    SetTimestart3.min = (String)timeStart3.min;

  }

}
void setTimeEnd3(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_Time3();
  lcd.cursor();
  timeEnd3.hour = read_num(23, x, y);
  Show_Time3();
  timeEnd3.min = read_num(59, x + 3, y);
  Show_Time3();
Serial.println((String)"timeEnd3="+timeEnd3.hour+":"+timeEnd3.min);
  lcd.noCursor();
  if (timeEnd3.hour < 10) {
    SetTimeEnd3.hour = (String)"0" + timeEnd3.hour;
  }
  if (timeEnd3.min < 10) {
    SetTimeEnd3.min = (String)"0" + timeEnd3.min;
  }
  if (timeEnd3.sec < 10) {
    SetTimeEnd3.sec = (String)"0" + timeEnd3.sec;
  }
  else {
    SetTimeEnd3.hour = (String)timeEnd3.hour;
    SetTimeEnd3.min = (String)timeEnd3.min;


  }
}
//////////////////////////////////   ตั้งเวลา PH /////////////////////////////////////////////////
void setTimePHStart1(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH1();
  lcd.cursor();
  timePHStart1.hour = read_num(23, x, y);
  Show_TimePH1();
  timePHStart1.min = read_num(59, x + 3, y);
  Show_TimePH1();
Serial.println((String)"timePHStart1="+timePHStart1.hour+":"+timePHStart1.min);
  lcd.noCursor();
  if (timePHStart1.hour < 10) {
    SetTimephstart1.hour = (String)"0" + timePHStart1.hour;
  }
  if (timePHStart1.min < 10) {
    SetTimephstart1.min = (String)"0" + timePHStart1.min;
  }

  else {
    SetTimephstart1.hour = (String)timePHStart1.hour;
    SetTimephstart1.min = (String)timePHStart1.min;

  }

}
void setTimePHEnd1(int x, int y) {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH1();
  lcd.cursor();
  timePHEnd1.hour = read_num(23, x, y);
   Show_TimePH1();
  timePHEnd1.min = read_num(59, x + 3, y );
   Show_TimePH1();
Serial.println((String)"timePHEnd1="+timePHEnd1.hour+":"+timePHEnd1.min);
  lcd.noCursor();
  if (timePHEnd1.hour < 10) {
    SetTimephEnd1.hour = (String)"0" + timePHEnd1.hour;
  }
  if (timePHEnd1.min < 10) {
    SetTimephEnd1.min = (String)"0" + timePHEnd1.min;
  }

  else {
    SetTimephEnd1.hour = (String)timePHEnd1.hour;
    SetTimephEnd1.min = (String)timePHEnd1.min;

  }
}
void setTimePHStart2(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH2();
  lcd.cursor();
  timePHStart2.hour = read_num(23, x, y);
   Show_TimePH2();
  timePHStart2.min = read_num(59, x + 3, y);
   Show_TimePH2();
Serial.println((String)"timePHStart2"+timePHStart2.hour+":"+timePHStart2.min);
  lcd.noCursor();
  if (timePHStart2.hour < 10) {
    SetTimephstart2.hour = (String)"0" + timePHStart2.hour;
  }
  if (timePHStart1.min < 10) {
    SetTimephstart2.min = (String)"0" + timePHStart2.min;
  }

  else {
    SetTimephstart2.hour = (String)timePHStart2.hour;
    SetTimephstart2.min = (String)timePHStart2.min;

  }

}

void setTimePHEnd2(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH2();
  lcd.cursor();
  timePHEnd2.hour = read_num(23, x, y);
   Show_TimePH2();
  timePHEnd2.min = read_num(59, x + 3, y);
   Show_TimePH2();
  Serial.println((String)"timePHEnd2"+timePHEnd2.hour+":"+timePHEnd2.min);
  lcd.noCursor();
  if (timePHEnd2.hour < 10) {
    SetTimephEnd2.hour = (String)"0" + timePHEnd2.hour;
  }
  if (timePHEnd2.min < 10) {
    SetTimephEnd2.min = (String)"0" + timePHEnd2.min;
  }
 
  else {
    SetTimephEnd2.hour = (String)timePHEnd2.hour;
    SetTimephEnd2.min = (String)timePHEnd2.min;
  }
}
void setTimePHStart3(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH3();
  lcd.cursor();
  timePHStart3.hour = read_num(23, x, y);
  Show_TimePH3();
  timePHStart3.min = read_num(59, x + 3, y);
  Show_TimePH3();
  Serial.println((String)"timePHStart3"+timePHStart3.hour+":"+timePHStart3.min);
  lcd.noCursor();
  if (timePHStart3.hour < 10) {
    SetTimephstart3.hour = (String)"0" + timePHStart3.hour;
  }
  if (timePHStart3.min < 10) {
    SetTimephstart3.min = (String)"0" + timePHStart3.min;
  }
 
  else {
    SetTimephstart3.hour = (String)timePHStart3.hour;
    SetTimephstart3.min = (String)timePHStart3.min;
   
  }
}
void setTimePHEnd3(int x, int y)  {
  RTC.readClock();
  lcd.setCursor(x, y);
  Show_TimePH3();
  lcd.cursor();
  timePHEnd3.hour = read_num(23, x, y);
  Show_TimePH3();
  timePHEnd3.min = read_num(59, x + 3, y);
  Show_TimePH3();
  Serial.println((String)"timePHEnd3"+timePHEnd3.hour+":"+timePHEnd3.min);
  lcd.noCursor();
  if (timePHEnd3.hour < 10) {
    SetTimephEnd3.hour = (String)"0" + timePHEnd3.hour;
  }
  if (timePHEnd2.min < 10) {
    SetTimephEnd3.min = (String)"0" + timePHEnd3.min;
  }
 
  else {
    SetTimephEnd3.hour = (String)timePHEnd3.hour;
    SetTimephEnd3.min = (String)timePHEnd3.min;
  }
}