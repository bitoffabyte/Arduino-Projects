String in, out;
int total = 0;

void setup() {
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void show() {
  Serial.print(total);
    Serial.println(" people in room.");
}
void loop() {
  a:
  Serial.println(digitalRead(7));
  Serial.println(digitalRead(8));
  if(digitalRead(7)==0){
    int c=0;
    while(digitalRead(8)==0){
      c++;
      if(c>300) goto a;
    }
    total++;
    Serial.println(total);
  }
  if(digitalRead(8)==0){
    int c=0;
    while(digitalRead(7)==0){
      c++;
      if(c>300) goto a;
    }
    total--;
    Serial.println(total);
  }
  
}
