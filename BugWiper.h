// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _BugWiper_H_
#define _BugWiper_H_

//add your includes for the project BugWiper here

//EEPROM declarations:
#define EE_DIRECTION	1

// Time declarations:
// Times for Button.h in milliseconds
#define DEBOUNCE_T		70
#define LONG_PRESS_T		800
// Time for Timer1
#define EVERY_X_MILLIS		10
// LED
#define LED_BLINK_WIPE		300	// 0,3 seconds

// Pin declaration:
//L298
#define PIN_OUT_1		11
#define PIN_OUT_2		10
#define PIN_ENABLE		9	//must a PWM-Pin
//Buttons with Buttons.h
#define PIN_TIE_UP		6
#define PIN_WIPE		5
//Keys without debounce
#define KEY_TIGHT		A1
#define KEY_LOCK		4
#define UNLOCK_STATE		LOW
//LED
#define PIN_LED_1		13

//Wiping declaration:
//full_wiping
#define W_P_START		130
#define W_T_MIN			2
#define W_T_MAX			35
#define W_P_DELAY		60
//tieing_up
#define TU_P_START		250
#define TU_T_MIN		1
#define TU_T_MAX		15
#define TU_P_DELAY		10

#include "src/L298.h"
#include "src/LED.h"
#include "src/Wiping.h"

#ifdef __cplusplus
extern "C"
{
#endif
  void
  loop ();
  void
  setup ();
#ifdef __cplusplus
} // extern "C"
#endif

extern L298 motor;
extern Led led1;
extern Wiping full_wiping;
extern Wiping tieing_up;

#endif /* _BugWiper_H_ */
