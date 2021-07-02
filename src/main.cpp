#include <Arduino.h>

#define SERIAL2_RXPIN 32 //Connect to the TX pin of the HC-12
#define SERIAL2_TXPIN 33 //Connect to the RX pin of the HC-12
const int LINE_BUFFER_SIZE = 5; // max line length is one less than this

void setup() 
{
  Serial2.begin(9600, SERIAL_8N1, SERIAL2_RXPIN, SERIAL2_TXPIN);     // Open serial port to HC12
  Serial.begin(9600);                       // Open serial port to computer
  while(!Serial);
  Serial.println("Input AT commands");
  
}

void read_line(char* buffer, int bufsize)
{
  Serial2.flush();
  for (int index = 0; index < bufsize; index++) 
    {
      while (Serial2.available() == 0) { }
      char ch = Serial2.read(); // read next character
      if (ch == '1') { break; } 
      if (ch == ' ') { }  else { buffer[index] = ch; }// Append character to buffer
    }
}
                                                 
void loop()
{
  char line[LINE_BUFFER_SIZE];
  read_line(line, sizeof(line));
  if (strcmp(line, "S") == 0) 
    {
      Serial.print("comando S recebido --> ");
      Serial.println(line);
    } 
}
