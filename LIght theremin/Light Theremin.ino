int sensor1 = A0;
int buzzer = 8;
String msg1 = "Enter your pitch (High/Medium/Low) : ";
String msg2 = "Byee!!";
String msg3 = "Invalid input. Please try again";
bool running = true;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(sensor1, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int calc = analogRead(sensor1);
  //Serial.println(calc);
  
  if(running){
    int calc = analogRead(sensor1);
    Serial.println(calc);
  }
  if (!running){
    return;
  }
  
   if (calc > 100){
      Serial.println(msg1);
    }
  
  while (Serial.available() == 0){
    Serial.println(msg1);
    int calc = analogRead(sensor1);
    Serial.println(calc);
  }
      
  String choice = Serial.readStringUntil('\n');
  
  if(choice == "High"){
      tone(buzzer, 700);
      noTone(buzzer);
      delay(1000);
      }       
  else if(choice == "Medium"){
      tone(buzzer, 1000);
      delay(1000);
      }       
  else if(choice == "Low"){
      tone(buzzer, 1500);
      delay(1000);
      }       
  else if(choice == "Off"){
      tone(buzzer, false);
      delay(1000);
      noTone(buzzer);
      Serial.println(msg2);
      } 
  else{
        Serial.println(msg3);
        noTone(buzzer);
      }
               
  delay(1000);
}

