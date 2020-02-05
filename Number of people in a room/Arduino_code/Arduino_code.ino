int total = 0;
int k=8,l=7;
int led=11;
void setup() {
  pinMode(k, INPUT);
  pinMode(l, INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  analogWrite(led,0);
}
void loop() {
  if(digitalRead(l)==LOW){
    while(digitalRead(k)==HIGH){
    }
    total++;
    delay(1000);
  }
  if(digitalRead(k)==LOW){
    while(digitalRead(l)==HIGH){
    }
    Serial.println("DOWN");
    total--;
    delay(1000);
   
  }
  if(total>5){
    Serial.println("Room Full");
  }
  else if(total<0){
    total=0;
  }
  else{
  analogWrite(led,total*51);
  }
   Serial.println(total);
}
