
int Sprite = 2;
int OrangeJuice = 3;
int PineappleJuice = 4;
int CranberryJuice = 5;

int  state = 0;
// how much time there is between switching to the next pump.
int  TimeBetweenPours = 500;

void setup()
{
 
  Serial.begin(9600);  
  Serial.println("The bluetooth gates are open. Connect to HC-05 from any other bluetooth device with 1234 as pairing key!");

  // Set pin 2-9 to  output pins to drive the relay board
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 


//  My relayboard is a "low true" board. So setting the output to low energize the relay's. You don't want that they all switch on when powering on the cocktailmaker...

  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  
}
 
void loop()

{
if(Serial.available()  > 0){ // Checks whether data is comming from the serial port
    state = Serial.read();  // Reads the data from the serial port
    Serial.println(state);
}

//  Cocktails:

//Sprite with Orange Juice
if (state == 'a') {
  Serial.println("Orange Juice with Sprite in the making.");
  Mix(5000,7000,0,0); 
 }

//  Mixed Fruit Juice (with Sprite)
if (state == 'b') {
  Serial.println("Mixed Fruit Juice (with Sprite) in the making.");
  Mix(4000,3000,3000,3000); 
 }
  

// Sprite with Cranberry juice
if (state == 'c') {
  Serial.println("Cranberry Juice with Sprite in the making.");
  Mix(7000,0,0,5000);  
 }

// Sprite with Pineapple Juice
if (state == 'd') {
  Serial.println("Pineapple Juice with Sprite in the making.");
  Mix(7000,0,5000,0); 
 }

//  Sprite
if (state == 'e') {
  Serial.println("Sprite in the making.");
  Mix(12000,0,0,0); 
 }

// Orange Juice
if (state == 'f') {
  Serial.println("Orange Juice in the making.");
  Mix(0,12000,0,0);  
 }

// Pineapple Juice
if (state == 'i') {
  Serial.println("Pineapple Juice in the making.");
  Mix(0,0,12000,0); 
 }

// Cranberry Juice
if (state == 'h') {
  Serial.println("Cranberry Juice in the making.");
  Mix(0,0,0,12000); 
 }

// Orange and Pineapple Juice
if  (state == 'g') {
  Serial.println("Orange and Pineapple Juice in the making.");
  Mix(0,6000,6000,0);  
 }

// Orange and Cranberry Juice
if (state == 'j') {
  Serial.println("Orange and Cranberry Juice in the making.");
  Mix(0,6000,0,6000); 
 }
    

// Pineapple and Cranberry Juice
if (state == 'k') {
  Serial.println("Pineapple and Cranberry Juice in the making.");
  Mix(0,0,6000,6000); 
 }

//  Sprite with Pineapple and Cranberry  
if (state == 'l') {
  Serial.println("Sprite with Pineapple + Cranberry Juice in the making.");
  Mix(4000,0,4000,4000); 
 }

 //  Sprite with Orange and Cranberry  
if (state == 'l') {
  Serial.println("Sprite with Orange + Cranberry Juice in the making.");
  Mix(4000,4000,0,4000); 
 }

 //  Sprite with Orange and Pineapple  
if (state == 'l') {
  Serial.println("Sprite with Orange + Pineapple Juice in the making.");
  Mix(4000,4000,4000,0); 
 }

 //  Mixed fruit Juice (No Sprite)
if (state == 'l') {
  Serial.println("Mixed Fruit Juice (No Sprite) in the making.");
  Mix(0,4000,4000,4000); 
 }
    
}

void  Mix(int DelayTimeSprite, int DelayTimeOrange_Juice, int DelayTimeCranberry_Juice, int DelayTimePineapple_Juice) {
  
  state = 0;
  delay(800);
  digitalWrite(Sprite,  LOW);   
  delay(DelayTimeSprite);            
  digitalWrite(Sprite, HIGH);  
  delay(TimeBetweenPours);    

  digitalWrite(OrangeJuice, LOW);   
  delay(DelayTimeOrange_Juice);            
  digitalWrite(OrangeJuice, HIGH); 
  delay(TimeBetweenPours); 

  digitalWrite(CranberryJuice, LOW);   
  delay(DelayTimeCranberry_Juice);            
  digitalWrite(CranberryJuice, HIGH); 
  delay(TimeBetweenPours);

  digitalWrite(PineappleJuice, LOW);   
  delay(DelayTimePineapple_Juice);            
  digitalWrite(PineappleJuice,  HIGH); 
  delay(TimeBetweenPours);
  

  Serial.println("We have finished making your drink. Enjoy!"); 
  state = 0;
}

}

