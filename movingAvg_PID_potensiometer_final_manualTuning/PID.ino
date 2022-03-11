
void PID() {
  b = filter();
  Serial.print(b);Serial.println(""); 
  float setP = 17;
  float error = setP - b;

  //Serial.print("nilai P + I + D  ");
  float Pvalue = error * n1; 
  float Ivalue = toError * n2;
  float Dvalue = (error - priError) * n3;
  //Serial.print(Pvalue);Serial.print(" ");Serial.print(Ivalue);Serial.print(" ");Serial.println(Dvalue);
  float PIDvalue = Pvalue + Ivalue + Dvalue;
  priError = error;
  toError += error;
  //pembatasan nilai total error
  if(toError>=200){
    toError=200;
  } else if(toError<=-200){
    toError=-200;
  }
  //Serial.print("total error = ");Serial.println(toError);
  //min 60....84.....98  
  //Serial.println(PIDvalue);
  if (PIDvalue>=24){
    PIDvalue=24;
  }else if(PIDvalue<=-14){
    PIDvalue=-14;
  }
  float Fvalue = 84 - PIDvalue;  
  Serial.print("nilai Fvalue = ");Serial.println(Fvalue);
  servo.write(Fvalue);
} 
