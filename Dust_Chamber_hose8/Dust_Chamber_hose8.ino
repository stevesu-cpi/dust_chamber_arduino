#define RELAY1 2 //Defining the pin 2 of the Arduino for the 1 relay module
#define RELAY2 3 //Defining the pin 3 of the Arduino for the 2 relay module
#define RELAY3 4 //Defining the pin 4 of the Arduino for the 3 relay module
#define RELAY4 5 //Defining the pin 5 of the Arduino for the 4 relay module
#define RELAY5 6 //Defining the pin 6 of the Arduino for the 5 relay module
#define RELAY6 7 //Defining the pin 7 of the Arduino for the 6 relay module
#define RELAY7 8 //Defining the pin 8 of the Arduino for the 7 relay module
#define RELAY8 9 //Defining the pin 9 of the Arduino for the 8 relay module

/* ------ Change ON, OFF and Total Test hours here ------ */
const int TIME_ON = 2; // On time in seconds per RELAY
const int TIME_OFF = 300; // Off time in seconds AFTER all RELAYS ON cycles
const int TOTAL_TEST_HOURS = 8; // Total test time in hours (No decimal)


/* ------ !!!!! DO NOT CHANGE BELOW THIS LINE !!!!! ------ */
int total_cycle = 60 / ((float)((float)TIME_ON * 1 + (float)TIME_OFF)/60) * (float)TOTAL_TEST_HOURS; // Calculate total number of cycles: 60min/hr * total time per cycle (cyc/mins) * total target test hours


void setup()
 {
    Serial.begin(9600);
    pinMode(RELAY1, OUTPUT); //Defining the pin 2 of the Arduino as output
    pinMode(RELAY2, OUTPUT); //Defining the pin 3 of the Arduino as output
    pinMode(RELAY3, OUTPUT); //Defining the pin 4 of the Arduino as output
    pinMode(RELAY4, OUTPUT); //Defining the pin 5 of the Arduino as output
    pinMode(RELAY5, OUTPUT); //Defining the pin 6 of the Arduino as output
    pinMode(RELAY6, OUTPUT); //Defining the pin 7 of the Arduino as output
    pinMode(RELAY7, OUTPUT); //Defining the pin 8 of the Arduino as output
    pinMode(RELAY8, OUTPUT); //Defining the pin 9 of the Arduino as output
    delay(100);
 }

void loop()
 {


  delay(100); //initial delay
  digitalWrite(RELAY1,HIGH); // This will Turn the Relay Off
  delay(50); //initial delay
  digitalWrite(RELAY2,HIGH); // This will Turn the Relay Off
  delay(50); //initial delay
  digitalWrite(RELAY3,HIGH); // This will Turn the Relay Off
  delay(50); //initial delay
  digitalWrite(RELAY4,HIGH); // This will Turn the Relay Off
  delay(50); //initial delay
  digitalWrite(RELAY5,HIGH); // This will Turn the Relay Off
  delay(50); //initial delay
  digitalWrite(RELAY6,HIGH); // This will Turn the Relay Off
  delay(50); //initial delay
  digitalWrite(RELAY7,HIGH); // This will Turn the Relay Off
  delay(50); //initial delay
  digitalWrite(RELAY8,HIGH); // This will Turn the Relay Off
  delay(50); //initial delay
  
  for  (int i = 1; i <= total_cycle+1; i++) {
    Serial.print("Beginning cycle : ");
    Serial.print(i);
    Serial.print(" of ");
    Serial.print(total_cycle);
    Serial.println("...");
    digitalWrite(RELAY1,LOW); // This will Turn ON the relay 1
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY1,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
/*
    digitalWrite(RELAY2,LOW); // This will Turn ON the relay 2
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY2,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time

    digitalWrite(RELAY3,LOW); // This will Turn ON the relay 3
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY3,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY4,LOW); // This will Turn ON the relay 4
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY4,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY5,LOW); // This will Turn ON the relay 5
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY5,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY6,LOW); // This will Turn ON the relay 6
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY6,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY7,LOW); // This will Turn ON the relay 7
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY7,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY8,LOW); // This will Turn ON the relay 8
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY8,HIGH); // This will Turn the Relay Off
 */       
    delay((long) TIME_OFF*1000); // This is OFF time
 
    Serial.print("End of ");
    Serial.print(i);
    Serial.println(" cycles.");
    delay(50);
    }
  Serial.println("Test Completed. Program terminated");  
  delay(50);
  exit (0);
 }
