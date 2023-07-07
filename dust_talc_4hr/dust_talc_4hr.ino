/*
date: 7/6/2023 
fname: dust_talc_4hr.ino
notes: The regulator press was set at 60 psi
Description:(old) code modified by Steve Su to increase dust expelled by creating "stage 2" (starts at end of 4hours) which increased the time of air ejected 
and decreased the dwell time between each firing.
Description(new) only run the 1st stage for three hours ; disable stage 2 (use of variable called "total_cycle_2"); reduced TIME_ON from 6 to 5 to 4; increased
TIME_OFF from 120 to 180 to 240
*/
#define RELAY1 2 //Defining the pin 2 of the Arduino for the 1 relay module
#define RELAY2 3 //Defining the pin 3 of the Arduino for the 2 relay module
#define RELAY3 4 //Defining the pin 4 of the Arduino for the 3 relay module
#define RELAY4 5 //Defining the pin 5 of the Arduino for the 4 relay module
#define RELAY5 6 //Defining the pin 6 of the Arduino for the 5 relay module
#define RELAY6 7 //Defining the pin 7 of the Arduino for the 6 relay module
#define RELAY7 8 //Defining the pin 8 of the Arduino for the 7 relay module
#define RELAY8 9 //Defining the pin 9 of the Arduino for the 8 relay module

/* ------ Change ON, OFF and Total Test hours here ------ */
const int TIME_ON = 4; // On time in seconds per RELAY for stage 1
const int TIME_OFF = 240; // Off time in seconds AFTER all RELAYS ON cycles for stage 1
const int TIME_ON_2 = 10; // On time in seconds per RELAY for stage 2
const int TIME_OFF_2 = 180; // Off time in seconds AFTER all RELAYS ON cycles for stage 2

const int TOTAL_TEST_HOURS = 4; // Total test time in hours per stage (No decimal)


/* ------ !!!!! DO NOT CHANGE BELOW THIS LINE !!!!! ------ */
int total_cycle = 60/((float)((float)TIME_ON*3+(float)TIME_OFF)/60)*(float)TOTAL_TEST_HOURS; // Calculate total number of cycles: 60min/hr * total time per cycle (in mins) * total target test hours
//int total_cycle_2 = 60/((float)((float)TIME_ON_2 * 3+(float)TIME_OFF_2)/60)*(float)TOTAL_TEST_HOURS;
int total_cycle_2 = -1; //change this to -1 to only run one stage

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
    Serial.print("Beginning cycle stage 1 : ");
    Serial.print(i);
    Serial.print(" of ");
    Serial.print(total_cycle);
    Serial.println("...");
    digitalWrite(RELAY1,LOW); // This will Turn ON the relay 1
    delay((TIME_ON-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY1,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time

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
        
    delay((long) TIME_OFF*1000); // This is OFF time
 
    Serial.print("End of step1");
    Serial.print(i);
    Serial.println(" cycles.");
    delay(50);
    }
    
   
   for  (int i = 1; i <= total_cycle_2+1; i++) {
    Serial.print("Beginning cycle stage 2: ");
    Serial.print(i);
    Serial.print(" of ");
    Serial.print(total_cycle_2);
    Serial.println("...");
    digitalWrite(RELAY1,LOW); // This will Turn ON the relay 1
    delay((TIME_ON_2-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY1,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time

    digitalWrite(RELAY2,LOW); // This will Turn ON the relay 2
    delay((TIME_ON_2-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY2,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time

    digitalWrite(RELAY3,LOW); // This will Turn ON the relay 3
    delay((TIME_ON_2-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY3,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY4,LOW); // This will Turn ON the relay 4
    delay((TIME_ON_2-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY4,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY5,LOW); // This will Turn ON the relay 5
    delay((TIME_ON_2-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY5,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY6,LOW); // This will Turn ON the relay 6
    delay((TIME_ON_2-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY6,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY7,LOW); // This will Turn ON the relay 7
    delay((TIME_ON_2-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY7,HIGH); // This will Turn the Relay Off
    delay(100); // This is pause time
    
    digitalWrite(RELAY8,LOW); // This will Turn ON the relay 8
    delay((TIME_ON_2-1)*1000); // Wait for (X) seconds
    digitalWrite(RELAY8,HIGH); // This will Turn the Relay Off
        
    delay((long) TIME_OFF_2*1000); // This is OFF time
 
    Serial.print("End of step2");
    Serial.print(i);
    Serial.println(" cycles.");
    delay(50);
    } 

  Serial.println("Test Completed. Program terminated");  
  delay(50);
  exit (0);
 }
