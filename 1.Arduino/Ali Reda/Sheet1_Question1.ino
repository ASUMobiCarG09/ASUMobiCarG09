/*
 * Code Submitted on Thursday 22 Feb 2018
 * Name: Ali Reda Ahmed Sadek
 * Section: 7
 * Seat No.: 23360
 * Assignment 1
 * Question 1
 */
void setup() {
  pinMode(10, OUTPUT); //Chosen Pin is number 10 on the board
}

void loop() {
  digitalWrite(10, HIGH);   //Triggers the pin HIGH
  delay(500);          //Keeps triggering the pin HIGH for 0.5 seconds             
  digitalWrite(10, LOW);   //Triggers the pin LOW 
  delay(1500);      //Keeps triggering the pin LOW for 1.5 seconds
}        
