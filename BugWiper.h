// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _BugWiper_H_
#define _BugWiper_H_

//add your includes for the project BugWiper here

// Time declarations:
// Times for Button.h in milliseconds
#define DEBOUNCE_T		70
#define LONG_PRESS_T	800
// Time for Timer1
#define EVERY_X_MILLIS	10

// Pin declaration:
//L298
#define PIN_OUT_1		7
#define PIN_OUT_2		8
#define PIN_ENABLE		9	//must a PWM-Pin
//Buttons
#define PIN_TIE_UP		10
#define PIN_WIPE		11



//end of add your includes here

#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project BugWiper here




//Do not add code below this line
#endif /* _BugWiper_H_ */
