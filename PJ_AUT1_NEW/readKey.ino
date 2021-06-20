void readKeypad() {
  key = keypad.getKey();

 if (key == 'B') {
      Serial.println("Resetwifi");
      mySerial.println("Resetwifi");
    }
  if (key == 'A'  )   {
    key = keypad.getKey();
    while (1) {
      lcd.setCursor(0, 0);
      lcd.print("               ");
      lcd.setCursor(2, 0);
      lcd.print("1-3 SET TIME SOI");
      lcd.setCursor(2, 1);
      lcd.print("4-6 SET TIME PH");
      lcd.setCursor(2, 2);
      lcd.print(" 7  SET SOI");
      lcd.setCursor(2, 3);
      lcd.print(" 8  SET PH");
      key = keypad.getKey();
      if (key == '1') {
        x = 1;
        break;
      }
      if (key == '2') {
        x = 2;
        break;
      }
      if (key == '3') {
        x = 3;
        break;
      }
      if (key == '4') {
        x = 4;
        break;
      }
      if (key == '5') {
        x = 5;
        break;
      }
      if (key == '6') {
        x = 6;
        break;
      }
      if (key == '7') {
        x = 7;
        break;
      }
      if (key == '8') {
        x = 8;
        break;
      }

    }


    if (key == '1' || x == 1  ) {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time Start 1");
      lcd.setCursor(2, 2);
      lcd.print("Time End 1");
      setTimeStart1(2, 1);
      lcd.print("               ");
      setTimeEnd1(2, 3);
      lcd.print("               ");
      //break;
      lcd.clear();

    }
    else if (key == '2' || x == 2  ) {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time Start 2");
      lcd.setCursor(2, 2);
      lcd.print("Time End 2");
      setTimeStart2(2, 1);
      setTimeEnd2(2, 3);
      lcd.clear();

    }
    else if (key == '3' || x == 3  ) {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time Start 3");
      lcd.setCursor(2, 2);
      lcd.print("Time End 3");
      setTimeStart3(2, 1);
      setTimeEnd3(2, 3);

    }
    else if (key == '4' || x == 4  )   {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time PH Start 1");
      lcd.setCursor(2, 2);
      lcd.print("Time PH End 1");
      setTimePHStart1(2, 1);
      setTimePHEnd1(2, 3);
      lcd.clear();
    }
    else if (key == '5' || x == 5)   {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time PH Start 2");
      lcd.setCursor(2, 2);
      lcd.print("Time PH End 2");
      setTimePHStart2(2, 1);
      setTimePHEnd2(2, 3);
      lcd.clear();
    }
    else if (key == '6' || x == 6 )   {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Time PH Start 3");
      lcd.setCursor(2, 2);
      lcd.print("Time PH End 3");
      setTimePHStart3(2, 1);
      setTimePHEnd3(2, 3);
      lcd.clear();
    }
    else if (key == '7' || x == 7 )   {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Set Start Moisture");
      lcd.setCursor(2, 2);
      lcd.print("Set End Moisture");
      SoilStartINT = read_num(100, 2, 1);
      SoilENDINT = read_num(100, 2, 3);
      lcd.clear();
    }
    else if (key == '8' || x == 8 )   {
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("                  ");
      lcd.setCursor(0, 3);
      lcd.print("                  ");
      lcd.setCursor(2, 0);
      lcd.print("Set Start PH");
      lcd.setCursor(2, 2);
      lcd.print("Set End PH");
      lcd.setCursor(2, 1);
      lcd.print("0.0");
      lcd.setCursor(2, 3);
      lcd.print("0.0");
      PHStartInt = read_num(9, 2, 1);
      PHStartfloat = read_num(9, 4, 1);
      String phstart  = (String)PHStartInt + "." + PHStartfloat;
      PHstart = phstart.toFloat();


      PHEndInt = read_num(9, 2, 3);
      PHEndfloat = read_num(9, 4, 3);
      String phend  = (String)PHEndInt + "." + PHEndfloat;
      PHstop = phend.toFloat();


    } 


  }

  else {
    lcd.setCursor(6, 0);
    read_time();
    show_time();


    if (RealTime.hour.toInt() == SetTimeEnd1.hour.toInt() && RealTime.min.toInt() == SetTimeEnd1.min.toInt()) {
      stateTime1 = 0;
      water_state = 0;
      Serial.println("stop 1");
      digitalWrite(pump1, LOW);
    } else if (RealTime.hour.toInt() == SetTimestart1.hour.toInt() && RealTime.min.toInt() == SetTimestart1.min.toInt() ) {
      stateTime1 = 1;
      water_state = 1;
      Serial.println("start 1");
      digitalWrite(pump1, HIGH);
    }
    if (RealTime.hour.toInt() == SetTimeEnd2.hour.toInt() && RealTime.min.toInt() == SetTimeEnd2.min.toInt() ) {
      stateTime2 = 0;
      water_state = 0;
      Serial.println("stop 2");
      digitalWrite(pump1, LOW);
    } else if (RealTime.hour.toInt() == SetTimestart2.hour.toInt() && RealTime.min.toInt() == SetTimestart2.min.toInt() ) {
      stateTime2 = 1;
      water_state = 1;
      Serial.println("start 2");
      digitalWrite(pump1, HIGH);
    }
    if (RealTime.hour.toInt() == SetTimeEnd3.hour.toInt() && RealTime.min.toInt() == SetTimeEnd3.min.toInt() ) {
      stateTime3 = 0;
      water_state = 0;
      Serial.println("stop 3");
      digitalWrite(pump1, LOW);
    } else if ( RealTime.hour.toInt() == SetTimestart3.hour.toInt() && RealTime.min.toInt() == SetTimestart3.min.toInt()) {
      stateTime3 = 1;
      water_state = 1;
      Serial.println("start 3");
      digitalWrite(pump1, HIGH);
    }
   

    if (RealTime.hour.toInt() == SetTimephEnd1.hour.toInt() && RealTime.min.toInt()  == SetTimephEnd1.min.toInt() ) {
      stateph1 = 0;
      Serial.println("stop PH 1");
      digitalWrite(pump3, LOW);
      digitalWrite(pump4, LOW);

    } else if (RealTime.hour.toInt()  == SetTimephstart1.hour.toInt() && RealTime.min.toInt()  == SetTimephstart1.min.toInt() ) {
      stateph1 = 1;
      Serial.println("start PH 1");
      digitalWrite(pump3, HIGH);
      digitalWrite(pump4, HIGH);
    }
    if (RealTime.hour.toInt() == SetTimephEnd2.hour.toInt() && RealTime.min.toInt() == SetTimephEnd2.min.toInt() ) {
      stateph2 = 0;
      Serial.println("stop PH 2");
      digitalWrite(pump3, LOW);
      digitalWrite(pump4, LOW);

    } else if (RealTime.hour.toInt() == SetTimephstart2.hour.toInt() && RealTime.min.toInt() == SetTimephstart2.min.toInt() ) {
      stateph2 = 1;
      Serial.println("start PH 2");
      digitalWrite(pump3, HIGH);
      digitalWrite(pump4, HIGH);

    }
    if (RealTime.hour.toInt() == SetTimephEnd3.hour.toInt() && RealTime.min.toInt() == SetTimephEnd3.min.toInt() ) {
      stateph3 = 0;
      Serial.println("stop PH 3");
      digitalWrite(pump3, LOW);
      digitalWrite(pump4, LOW);
    } else if (RealTime.hour.toInt() == SetTimephstart3.hour.toInt() && RealTime.min.toInt() == SetTimephstart3.min.toInt() ) {
      stateph3 = 1;
      Serial.println("start PH 3");
      digitalWrite(pump3, HIGH);
      digitalWrite(pump4, HIGH);
    }

    Set_Moisture();


    show_MoistureSensor();
    show_PH();
    Set_PH();
    setEProm();


  }
}