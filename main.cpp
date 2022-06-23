#include "mbed.h"
#include "rtos.h"
DigitalOut led1(PB_7);
DigitalIn button(PC_13, PullDown);
static unsigned int button_stat=0;
Thread thread1;
Thread thread2;
 
void led1_thread() {
    while (true) {
		printf("%u is the button stat\n",button_stat);
		while(button_stat==1)
		{
        led1 = 1;
		printf("led on\n");
		}
		led1=0;
		printf("Led\n");
        ThisThread::sleep_for(1000);
    }
}
 
void button_thread() {
    while (true) {
        while(button == 1)
		{
			button_stat=1;
			printf("Button pressed\n");
		}
		button_stat=0;
		printf("Button\n");
        ThisThread::sleep_for(1000);
    }
}
 
int main() {
    thread1.start(button_thread);
    thread2.start(led1_thread);
}