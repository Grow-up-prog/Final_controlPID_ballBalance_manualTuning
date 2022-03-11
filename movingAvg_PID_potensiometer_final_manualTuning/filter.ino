float filter(){//fungsi filtering
  //mengurangi pembacaan pada index terdahulu
  total = total-readings[readIndex];
//  Serial.print("read Index =   ");Serial.println(readIndex);
  readings[readIndex] = jarak(); //membaca nilai saat ini
  //penambahan nilai index saat ini ke variabel total
  total= total + readings[readIndex] ;
  //melakukan penambahan pada jumlah index
  readIndex=readIndex+1;
  if(readIndex>=numReadings){//apabila nilai index sudah mencapai 3 maka di reset ke 0
    readIndex=0;
  }
  //kalkulasi pada nilai rata rata 
  float average = total/5;
  return average;
}
