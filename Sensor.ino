// C++ code
//
void setup()
{
 pinMode ( 13, OUTPUT);
  pinMode(5, INPUT);
  Serial.begin(9600);
}

void loop()
{
 int value;
  value = digitalRead(5);
  if(value == HIGH){
    digitalWrite(13, HIGH);
  Serial.println("MOTION DETECTED");
} 
else{ 
  digitalWrite(13, LOW);
  Serial.println("NO MOTION DETECTED");
}
 delay(500);
}