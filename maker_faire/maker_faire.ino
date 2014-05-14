int windFarm = A3; // pin for all the dc motors + fans in series on the grate
int val = 0; // variable to store value coming from motorPin
int spinPin = 11; // pin for the output speed of the dc motor for painting
int spinSpeed = 0;
float voltage = 0.0;
int pinX = 3; //pin to read in rocker switch state

void setup() {
  pinMode(windFarm, INPUT);
  pinMode(spinPin, OUTPUT);
  pinMode (pinX, INPUT_PULLUP); // use with button connected to pinX and to Gnd
  Serial.begin(9600);
}

void loop() {
 val = analogRead(windFarm);
 voltage = val * (5.0 / 1023.0);
 if(voltage > 0.0) { 
   Serial.println(voltage);
 }
 spinSpeed = val / 4;
 
 // THIS IS ADDED FOR DEMO PURPOSES
 if(digitalRead(pinX) == 1) { // this is "on"
   spinSpeed = 95;
 } else {
   spinSpeed = 0;
 }
 // END OF DEMO PART OF CODE
 
 analogWrite(spinPin, spinSpeed);
}
