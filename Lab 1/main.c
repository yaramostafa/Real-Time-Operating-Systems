#include "DIO.h"

int main()
{
  uint32_t volatile run = 0;
  Systick_init();
  DIO_init();
  while(1){
    if(run){
      blinky1();}
    else{
      blinky2();}
  }
  return 0;
}
