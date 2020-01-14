int total = 0;
int k=8,l=9;
int led;
void setup() {
  pinMode(k, INPUT);
  pinMode(l, INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  analogWrite(led,0);
}
void loop() {
  a:
  if(digitalRead(l)==0){
    int c=0;
    while(digitalRead(k)==0){
      c++;
      if(c>1000) goto a;
    }
    total++;
    Serial.println(total);
  }
  if(digitalRead(k)==0){
    int c=0;
    while(digitalRead(l)==0){
      c++;
      if(c>1000) goto a;
    }
    Serial.println("DOWN");
    total--;
   
  }
  analogWrite(led,total*51);
   Serial.println(total);
   delay(500);
}
