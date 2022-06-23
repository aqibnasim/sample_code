#include "mbed.h"
#include "rtos.h"

DigitalOut led1(PB_7);
// initializing the GPIO asnd configuring it as output.
DigitalIn button(PC_13, PullDown);
// initializing the GPIO asnd configuring it as input with pull down configuration
Queue<int, 1> queue;
// queue made to hold the message
static int message = 1;
Thread thread1;
// thread 1 created for the button state
Thread thread2;
// thread 2 created for the led state on\off

/**
 * @brief 
 * 
 */
void led1_thread()
{
    while (true)
    {
        osEvent evt = queue.get();
        // message getting from queue
        if (evt.status == osEventMessage)
        {
            // if message matches then this loop will operate
            printf("led on\n");
            led1 = 1;
            ThisThread::sleep_for(500);
            // delay added for the led to be visible to the observer
            led1 = 0;
            // led turned off
        }
        printf("Led\n");
        ThisThread::sleep_for(1000);
    }
}
/**
 * @brief 
 * 
 */
void button_thread()
{
    while (true)
    {
        if (button == 1)
        {
            // if button is presssed then message will be transfered
            queue.put(&message);
        }
        printf("Button\n");
        ThisThread::sleep_for(1000);
    }
}

int main()
{
    thread1.start(button_thread);
    thread2.start(led1_thread);
}