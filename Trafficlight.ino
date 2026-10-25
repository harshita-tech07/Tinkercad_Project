// C++ code
// Traffic light code 
int red = 2;
  int yellow = 3;
  int green= 4;
void setup()
{
  
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(red, LOW);

  // Wait for 1000 millisecond(s)
  
  
  	for(int i=0; i<=10;i++){
    	if(i % 2 == 0){
      		digitalWrite(yellow,HIGH);
      		delay(500);
    	}else{
       		digitalWrite(yellow,LOW);
      		delay(500);
    }
  }
  digitalWrite(yellow,LOW);
  
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW);
  delay(100);  
}