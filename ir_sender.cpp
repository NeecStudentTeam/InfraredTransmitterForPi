// Include header file
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

// Define GPIO18 number
#define GPIO 18

// test mode
int isTestMode;

int initializeWiringPi();
void finalizeWiringPi();
void digitalWriteWrap(int, int);
int countBitFor32bit(unsigned int);
int getMsbFor32bit(unsigned int);

// Main function
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("arg count not 2 error\n");
    return 1;
  }
  
  // test mode
  isTestMode = atoi(argv[2]) == 1;
  if(isTestMode) printf("is test mode\n");

  // get ir data
  unsigned int data = atoi(argv[1]);
  
  // Initialize WiringPi
  if(initializeWiringPi() == 1) return 1;
  
  // get msg
  int msb = getMsbFor32bit(data);
  
  // send ir
  for(int i = msb; i >= 0; i--) { 
    int bit = data >> i & (uint)1; 
    if(bit) { 
      digitalWriteWrap(GPIO, 1);
    } else {
      digitalWriteWrap(GPIO, 0);
    }
    // sleep 500 ms
    delay(500);
  }
  
  // Finalize WiringPi
  finalizeWiringPi()
  
  printf("end\n");
  
  return 0;
}

int initializeWiringPi() {
  if(isTestMode) return 0;
  
  // Initialize WiringPi
  if(wiringPiSetupGpio() == -1) return 1;
  
  // Set GPIO pin to output mode
  pinMode(GPIO, OUTPUT);
  
  return 0;
}

int finalizeWiringPi() {
  if(isTestMode) return 0;
  
  // Turn off
  digitalWrite(GPIO,0);
  
  return 0;
}

void digitalWriteWrap(int pin, int value) {
  if(isTestMode) {
    printf("GPIO WRITE pin : %d, value: %d\n", pin, value);
  }
  else {
    digitalWrite(pin,value);
  }
}

int countBitFor32bit(unsigned int v) {
  int count = (v & 0x55555555) + ((v >> 1) & 0x55555555);
  count = (count & 0x33333333) + ((count >> 2) & 0x33333333);
  count = (count & 0x0f0f0f0f) + ((count >> 4) & 0x0f0f0f0f);
  count = (count & 0x00ff00ff) + ((count >> 8) & 0x00ff00ff);
  return (count & 0x0000ffff) + ((count >> 16) & 0x0000ffff);
}

int getMsbFor32bit(unsigned int v) {
  if (v == 0) return 0;
  v |= (v >> 1);
  v |= (v >> 2);
  v |= (v >> 4);
  v |= (v >> 8);
  v |= (v >> 16);
  return countBitFor32bit(v) - 1;
}
