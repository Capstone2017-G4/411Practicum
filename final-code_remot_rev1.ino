int acc_x;
int acc_y;
/*
int D0=10;
int D1=11;
int D2=12;
int D3=13;
int led=5;
*/
int x,y,x_val,y_val,last_val,val,stability;
void setup()
{
  //pinMode(accx,INPUT);
 // pinMode(accy,INPUT);
/*
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(led,OUTPUT);
 */ 
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(led,OUTPUT);
  
  digitalWrite(led,LOW);
  Serial.begin(9600);
  x_val=checkstabiliy(A0);
  y_val=checkstabiliy(A1);
  digitalWrite(led,HIGH);
  
}
void loop()
{
   acc_x=analogRead(A0);
   x=acc_x-x_val;
   acc_y=analogRead(A1);
   y=acc_y-y_val;
    Serial.print( "x=");
    
    Serial.println(x);
    Serial.print( "y=");
    
    Serial.println(y);

if(x<-30)
 {
/*  
  Serial.println( "right");
  digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D3, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
 */
   digitalWrite(13,HIGH);
   digitalWrite(12,LOW);
   digitalWrite(11,LOW);
   digitalWrite(10,HIGH);
 }

else if(x>30)
 {
  /*
  Serial.println( "left");
  digitalWrite(D0, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D3, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
 */
   digitalWrite(13,LOW);
   digitalWrite(12,HIGH);
   digitalWrite(11,HIGH);
   digitalWrite(10,LOW);
 }

else if(y<-30)
{
 /*
  Serial.println( "frwd");
  digitalWrite(D0, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D3, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
 */
   digitalWrite(13,LOW);
   digitalWrite(12,HIGH);
   digitalWrite(11,LOW);
   digitalWrite(10,HIGH);
 }
else if(y>30)
 {
 /*
  Serial.println( "back");
  digitalWrite(D0, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
 */
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
 }
else 
{
  /*
  Serial.println( "stop");  
  digitalWrite(D0, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(D1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(D2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(D3, LOW);    // turn the LED off by making the voltage LOW
  delay(200);
*/
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
}
}
int checkstabiliy(int pinNo)
{
 last_val = 0,stability=0;
 val=analogRead(pinNo);
  last_val = val;
  while(stability<4)
  {
     val=analogRead(pinNo);
     Serial.println(val);
     delay(100);
     stability++;
     if(((val - last_val) < -5) || ((val - last_val) > 5))
     {
       stability=0;
       last_val = val; 
     }   
  }
  Serial.print(pinNo);
  Serial.print(" stability=");
  Serial.println(val);
  
 stability = 0;
 return val;
}

