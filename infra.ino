const int ProxSensor=A0;
float sensorValue = 0;

void setup() 
{                
  pinMode(13, OUTPUT);          // Pin 13 has an built-in LED 
  pinMode(ProxSensor,INPUT);    //Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
}

void loop() 
{
  if(digitalRead(ProxSensor)==HIGH)      //Check the sensor output
  {
    digitalWrite(13, HIGH);   // set the LED on
  }
  else
  {
    digitalWrite(13, LOW);    // set the LED off
  }

sensorValue = analogRead(ProxSensor);
sensorValue = map(sensorValue, 0, 1023, 0, 1023);
float voltage = sensorValue * (3.3/1024);

Serial.println(voltage);

delay(100);              // wait for a second
}
