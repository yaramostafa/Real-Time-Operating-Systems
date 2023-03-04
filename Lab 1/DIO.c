#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "DIO.h"

void DIO_init(void){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
  GPIOUnlockPin(GPIO_PORTF_BASE,(GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4));
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2);
}
void Systick_init(){
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
  SysTickPeriodSet(SysCtlClockGet()/2 -1);
  SysTickIntEnable();
  SysTickEnable();
  SysTickIntRegister(SystickHandler); // ADDS IT TO VECTOR TABLE
}

static uint32_t volatile counter = 0;
void SystickHandler(){  
  counter++;  
}
void blinky1(void){
  while(1){
    if(counter %5 == 0){
      toggle(GPIO_PIN_1);}
  }
}

void blinky2(void){
  while(1){
    if(counter %10 == 0){
    
      toggle(GPIO_PIN_2);}
  }
}

void toggle(uint8_t pin){
  uint32_t value = GPIOPinRead(GPIO_PORTF_BASE,pin);
  if(value == 0){
   GPIOPinWrite(GPIO_PORTF_BASE,pin, pin);
   }else if(value == pin){
     GPIOPinWrite(GPIO_PORTF_BASE,pin, 0);
   }
}
