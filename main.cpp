#include "mbed.h"

DigitalIn button(PC_13);
DigitalOut led(PB_7);
 
 int main() {
     while(1) {
         if(button) {
              led = !led;
          }
          ThisThread::sleep_for(250);
      }
 }
 