int led[]={3,4,5,6,7};
void setup() {
  Serial.begin(9600);
  for(int i=0;i<5;i++){
    pinMode(led[i],OUTPUT);
  }
}
void loop() {
  int i,j;
  Serial.println("Enter a number (0-31) or Enter 1024 to start a sequence");
  while(Serial.available()==0){}
    int k=Serial.parseInt();
  if (k==1024){
      for(int n=0;n<32;n++){
        for(int i=0;i<5;i++){
        digitalWrite(led[i],LOW);
        }
        Serial.print(n);
        Serial.print(" ");
        for(int i=4;i>-1;i--){
          byte st=bitRead(n,i);
          Serial.print(st);
          if(st==1) digitalWrite(led[i],HIGH);
        }
      Serial.println();
      delay(1000);
    }
  }
  else{
    a:
      for(int i=0;i<5;i++){
        digitalWrite(led[i],LOW);
      }
      int n=k;
      if (n>=32 || n<0){
        Serial.println("Enter a Valid number (0 - 31)");
        goto a;
      }
      for(int i=4;i>-1;i--){
      byte st=bitRead(n,i);
      Serial.print(st);
      if(st==1) digitalWrite(led[i],HIGH);
    }
    Serial.println();
    delay(1000);
  }
}
