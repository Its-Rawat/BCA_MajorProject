// defines pins numbers
//const int trigPin = 10; // Using const as we dont need to change it.
//const int echoPin = 9;

#define trigPin 10  // #define is a type of macro 
#define echoPin 9   // everytime a macro is called it is replaced by the value of macro.


// defines variables

long duration;
int distance;
int safetyDistance;


void setup() {

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output

pinMode(echoPin, INPUT); // Sets the echoPin as an Input

Serial.begin(9600); //Initializes the serial communication at a baud rate of 9600 bps.
}


void loop() {

  delay(1500);

// Clears the trigPin

digitalWrite(trigPin, LOW); //The digitalWrite function is used to set a digital pin to a specific state (either HIGH or LOW).

delayMicroseconds(2); //The delayMicroseconds(2); function in Arduino programming is used to pause the execution of the program for a specific number of microseconds.

// Sets the trigPin on HIGH state for 10 micro seconds

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
//This function reads the duration of the pulse received on the echo pin, which corresponds to the time taken for the ultrasonic pulse to travel to an object and back.

duration = pulseIn(echoPin, HIGH);

// Calculating the distance
//Since sound travels at approximately 343 meters per second (in air at room temperature), and we want the distance to and from the object, we use the formula: Distance = (Time * Speed of Sound) / 2.
//we divide the time by 2 (because the pulse travels to the object and back) and multiply by the speed of sound in cm/microsecond.
//The speed of sound in air at room temperature is approximately 343 meters per second or 0.0343 centimeters per microsecond. Rounding it to 0.034 provides a simple and close approximation.

distance= duration*0.034/2;

// increase the range of Sensor Accordingly

safetyDistance = distance;

// Prints the distance on the Serial Monitor

Serial.print("distance: ");
Serial.print(distance);
Serial.print("cm");
Serial.println("");
}
