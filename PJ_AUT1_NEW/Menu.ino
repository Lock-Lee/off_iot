void Show_Time1() {     // time pump //
  lcd.setCursor(2, 1);

  lcd.print(SetTimestart1.hour);
  lcd.print(":");
  lcd.print(SetTimestart1.min);


  lcd.setCursor(2, 3);

  lcd.print(SetTimeEnd1.hour);
  lcd.print(":");
  lcd.print(SetTimeEnd1.min);


}


void Show_Time2() {     // time pump //
  lcd.setCursor(2, 1);

  lcd.print(SetTimestart2.hour);
  lcd.print(":");
  lcd.print(SetTimestart2.min);


  lcd.setCursor(2, 3);

  lcd.print(SetTimeEnd2.hour);
  lcd.print(":");
  lcd.print(SetTimeEnd2.min);


}

void Show_Time3() {     // time pump //
  lcd.setCursor(2, 1);


  lcd.print(SetTimestart3.hour);
  lcd.print(":");
  lcd.print(SetTimestart3.min);

  lcd.setCursor(2, 3);


  lcd.print(SetTimeEnd3.hour);
  lcd.print(":");
  lcd.print(SetTimeEnd3.min);


}



/////  time ph /////
void Show_TimePH1() {
  lcd.setCursor(2, 1);

  lcd.print(SetTimephstart1.hour);
  lcd.print(":");
  lcd.print(SetTimephstart1.min);



  lcd.setCursor(2, 3);


  lcd.print(SetTimephEnd1.hour);
  lcd.print(":");
  lcd.print(SetTimephEnd1.min);


}

void Show_TimePH2() {
  lcd.setCursor(2, 1);
  lcd.print(SetTimephstart2.hour);
  lcd.print(":");
  lcd.print(SetTimephstart2.min);
  lcd.setCursor(2, 3);
  lcd.print(SetTimephEnd2.hour);
  lcd.print(":");
  lcd.print(SetTimephEnd2.min);


}

void Show_TimePH3() {
  lcd.setCursor(2, 1);
  lcd.print(SetTimephstart3.hour);
  lcd.print(":");
  lcd.print(SetTimephstart3.min);
  lcd.setCursor(2, 3);
  lcd.print(SetTimephEnd3.hour);
  lcd.print(":");
  lcd.print(SetTimephEnd3.min);


}