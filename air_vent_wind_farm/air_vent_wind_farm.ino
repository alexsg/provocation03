int windFarm = A3; // pin for all the dc motors + fans in series on the grate
int val = 0; // variable to store value coming from motorPin
int spinPin = 11; // pin for the output speed of the dc motor for painting
int spinSpeed = 0;
float voltage = 0.0;

void setup() {
  pinMode(windFarm, INPUT);
  pinMode(spinPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 val = analogRead(windFarm);
 voltage = val * (5.0 / 1023.0);
 if(voltage > 0.0) { 
   Serial.println(voltage);
 }
 spinSpeed = val / 4;
 analogWrite(spinPin, spinSpeed);
}
