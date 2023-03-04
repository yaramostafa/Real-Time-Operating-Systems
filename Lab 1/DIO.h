
#ifndef DIO_H
#define DIO_H
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"

void DIO_init(void);
void Systick_init(void);
void SystickHandler(void);
void blinky1(void);
void blinky2(void);
void toggle(uint8_t pin);
#endif