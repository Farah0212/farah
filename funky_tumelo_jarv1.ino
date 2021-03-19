int baselineTemp = 0; // Set temperature to activate LED
int celsius = 0; // Read in celcius 
int fahrenheit = 0; // Read in fahrenhit

void setup()
{
  pinMode(A0, INPUT); //digital pin A0 as INPUT
  Serial.begin(9600); //Start the serial port at 9600

  pinMode(5, OUTPUT); // digital pin 5 as OUTPUT
  pinMode(6, OUTPUT); // digital pin 6 as OUTPUT
  pinMode(7, OUTPUT); // digital pin 7 as OUTPUT
}

void loop()
{
  baselineTemp = 40; //set threshold temperature to activate LEDs
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); //measure temperature in Celsius
  fahrenheit = ((celsius * 9) / 5 + 32); //convert to Fahrenheit
  Serial.print(celsius);  //Serial print read as celcius
  Serial.print(" C, "); //Serial print C
  Serial.print(fahrenheit); //Serial print read as fahrenheit
  Serial.println(" F"); //Serial print F
 
  if (celsius >= baselineTemp && celsius < baselineTemp + 10) { //if Temperature between 40 to 50 
    digitalWrite(5, HIGH); // Turn on LED
    digitalWrite(6, LOW); // Turn off LED
    digitalWrite(7, LOW); // Turn off LED
  }
  if (celsius >= baselineTemp + 10 && celsius < baselineTemp + 20) { //if Temperature between 50 to 60 
    digitalWrite(5, HIGH); // Turn on LED
    digitalWrite(6, HIGH); // Turn on LED
    digitalWrite(7, LOW); // Turn off LED
  }
  if (celsius >= baselineTemp + 20 && celsius < baselineTemp + 30) { //if Temperature between 60 to 70 
    digitalWrite(5, HIGH); // Turn on LED
    digitalWrite(6, HIGH); // Turn on LED
    digitalWrite(7, HIGH); // Turn on LED
  }
  if (celsius >= baselineTemp + 30) {  //if Temperature above 70
    digitalWrite(5, HIGH); // Turn on LED
    digitalWrite(6, HIGH); // Turn on LED
    digitalWrite(7, HIGH); // Turn on LED
  }
  delay(500); // Wait for 500 millisecond(s)
}