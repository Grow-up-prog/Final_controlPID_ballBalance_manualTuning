  float KP(){
    sensorValueA = analogRead(A0);
    A =  map(sensorValueA, 0, 1023, 0, 500);
    outputA= A/100;   
    return outputA;
  }
  float KI(){
    sensorValueB = analogRead(A1);
    B =  map(sensorValueB, 0, 1023, 0, 30);
    outputB= B/100;
    return outputB;
  }
  float KD(){
    sensorValueC = analogRead(A2);
    C =  map(sensorValueC, 0, 1023, 0, 600);
    outputC= C/100;    
    return outputC;
  }
  
  
