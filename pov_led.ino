#include <stdarg.h> // Library for the variable argument functions 
#include <string.h>

#define led11On digitalWrite(11, HIGH) // Quick reference commands for most common animation LEDs
#define led11Off digitalWrite(11, LOW)
#define led12On digitalWrite(12, HIGH)
#define led12Off digitalWrite(12, LOW)
#define led13On digitalWrite(13, HIGH)
#define led13Off digitalWrite(13, LOW)
#define led14On digitalWrite(14, HIGH)
#define led14Off digitalWrite(14, LOW)
#define led15On digitalWrite(15, HIGH)
#define led15Off digitalWrite(15, LOW)
#define led16On digitalWrite(16, HIGH)
#define led16Off digitalWrite(16, LOW)
#define led17On digitalWrite(17, HIGH)
#define led17Off digitalWrite(17, LOW)

int delayrpm;
float timestart = 0, timeCycle, looptime, pasttime=0;
unsigned short counter=0;
bool previous;

void ledOn(int pin) { // Simplification of the digitalWrite command
  digitalWrite(pin, HIGH);
}

void wait(float factor) {
  delayMicroseconds(factor*(2000/delayrpm*250)); // Ratio for calculating delay between pulses: 1500us/250rpm = x/currentRPM
}

void ledControl(int pin,...) { // Special function with variable number of arguments. Syntax: ledControl(factor of delay, # of arguments, n1,n2,n3,n...);
  va_list valist;
  int i, wait, pinNumber[pin];
  va_start(valist, pin);

  for(i=0;i<pin-1;i++) {
    pinNumber[i] = va_arg(valist, int);
    digitalWrite(pinNumber[i], HIGH);
  }
  delayMicroseconds(va_arg(valist, int)*(2000/delayrpm*250));
  for(i=0;i<pin-1;i++) {
    digitalWrite(pinNumber[i], LOW);
  }
  
  va_end(valist);

}

void ledOff(int pin) { // Simplification of the digitalWrite command
  digitalWrite(pin, LOW);
}

void allOff() { // Quick function to shut off all LEDs but the final two reds
  ledOff(0);
  ledOff(1);
  for(int n=3;n<18;n++) {
    ledOff(n);
  }
  space();
}

// -------------------------- END OF COMMAND SECTION - - - BEGINNING OF ANIMATIONS -----------------------------//

void test() {

  ledOn(0);
  ledOn(2);
  delay(100);
  ledOff(0);
  ledOff(2);

  ledOn(1);
  ledOn(18);
  delay(100);
  ledOff(1);
  ledOff(18);

  for(int n=3;n<9;n++) {
    ledOn(n);
    ledOn(19-n);
    delay(100);
    ledOff(n);
    ledOff(19-n);
  }
  
  ledOn(9);
  ledOn(10);
  delay(100);
  ledOff(9);
  ledOff(10);
  
  for(int n=8;n>=3;n--) {
    ledOn(n);
    ledOn(19-n);
    delay(100);
    ledOff(n);
    ledOff(19-n);  
  }

  ledOn(1);
  ledOn(18);
  delay(100);
  ledOff(1);
  ledOff(18);

  ledOn(0);
  ledOn(2);
  delay(100);
  ledOff(0);
  ledOff(2);
}

void letterA() {
  ledOn(11);
  wait(1);
  ledOff(11);
  for(int n=12;n<17;n++) {
    ledOn(n);
    wait(1);
    ledOff(n);
    if(n>=15)
      ledOn(15);
  }
  ledOn(17);
  wait(1);
  ledOff(17);
  for(int n=16;n>=12;n--) {
    ledOn(n);
    wait(1);
    ledOff(n);
    if(n<15)
      ledOff(15);
  }
  allOff();
}

void letterB() {

  ledControl(5, 12,13,15,16, 1);
  ledControl(4, 11,14,17, 2);
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
   
}

void letterC() {
  
  ledControl(3, 11,17, 2);
  ledControl(3, 12,16, 2);
  ledControl(4, 13,14,15, 1);

  allOff();

}

void letterD() {

  ledControl(4, 13,14,15, 1);
  ledControl(3, 12,16, 1);
  ledControl(3, 11,17, 2);
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterE() {

  ledControl(4, 11,14,17, 3);
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterF() {

  ledControl(3, 14,17, 3);
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterG() {
  
  ledControl(6, 11,12,13,14,17, 1);
  ledControl(4, 11,14,17, 2);
  ledControl(6, 12,16, 2);
  ledControl(4, 13,14,15, 1);

  allOff();  
}

void letterH() {

  ledControl(8, 11,12,13,14,15,16,17, 1);

  led14On;
  wait(3);
  led14Off;
  
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterI() {

  ledControl(3, 11,17, 2);
  ledControl(8, 11,12,13,14,15,16,17, 1);
  ledControl(3, 11,17, 2);

  allOff();
}

void letterJ() {

  ledControl(7, 12,13,14,15,16,17, 1);

  led11On; wait(3); led11Off;
  led12On; wait(1); led12Off;

  allOff();
}

void letterK() {

  ledControl(3, 11,17, 1);
  ledControl(3, 12,16, 1);
  ledControl(3, 13,15, 1);
  ledControl(2, 14, 1);
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterL() {

  ledControl(2, 11, 4);
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterM() {

  for(int i=11;i<18;i++) {
    ledOn(i);
    wait(.25);
    ledOff(i);
  }
  for(int i=17;i>10;i--) {
    ledOn(i);
    wait(.25);
    ledOff(i);
  }
  for(int i=11;i<18;i++) {
    ledOn(i);
    wait(.25);
    ledOff(i);
  }
  for(int i=17;i>10;i--) {
    ledOn(i);
    wait(.25);
    ledOff(i);
  }

  allOff();
}

void letterN() {

  ledControl(8, 11,12,13,14,15,16,17, 1);
  for(int i=11;i<18;i++) {
    ledOn(i);
    wait(.5);
    ledOff(i);
  }
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterO() {

  ledControl(6, 12,13,14,15,16, 1);
  ledControl(3, 11,17, 5);
  ledControl(6, 12,13,14,15,16, 1);

  allOff();
}

void letterP() {

  ledControl(3, 15,16, 1);
  ledControl(3, 14,17, 3);
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterQ() {

  ledControl(7, 10,12,13,14,15,16, 1);
  ledControl(4, 10,11,17, 1);
  ledControl(3, 11,17, 1);
  ledControl(4, 11,12,17, 1);
  ledControl(3, 11,17, 2);
  ledControl(6, 12,13,14,15,16, 1);

  allOff();
}

void letterR() {

  ledControl(4, 11,15,16, 1);
  ledControl(4, 12,14,17, 1);
  ledControl(4, 13,14,17, 1);
  ledControl(3, 14,17, 1);
  ledControl(8, 11,12,13,14,15,16,17, 1);

  allOff();
}

void letterS() {

  ledControl(4, 12,13,16, 1);
  ledControl(4, 11,14,17, 1);
  ledControl(4, 11,15,17, 1);
  ledControl(4, 12,15,16, 1);

  allOff();
}

void letterT() {

  ledControl(2, 17, 2);
  ledControl(8, 11,12,13,14,15,16,17, 1);
  ledControl(2, 17, 2);

  allOff();
}

void letterU() {

  ledControl(7, 12,13,14,15,16,17, 1);
  ledControl(2, 11, 4);
  ledControl(7, 12,13,14,15,16,17, 1);

  allOff();
}

void letterV() {

  for(int i=17;i>10;i--) {
    ledOn(i);
    wait(.5);
    ledOff(i);
  }
  for(int i=11;i<18;i++) {
    ledOn(i);
    wait(.5);
    ledOff(i);
  }

  allOff();
}

void letterW() {

  for(int i=17;i>10;i--) {
    ledOn(i);
    wait(.25);
    ledOff(i);
  }
  for(int i=11;i<15;i++) {
    ledOn(i);
    wait(.25);
    ledOff(i);
  }
  for(int i=14;i>10;i--) {
    ledOn(i);
    wait(.25);
    ledOff(i);
  }
  for(int i=11;i<17;i++) {
    ledOn(i);
    wait(.25);
    ledOff(i);
  }

  allOff();
}
void letterX() {
  ledOn(11);
  ledOn(17);
  wait(1);
  ledOff(11);
  ledOff(17);
  for(int n=12;n<14;n++) {
    ledOn(n);
    ledOn(28-n);
    wait(1);
    ledOff(n);
    ledOff(28-n);
  }
  ledOn(14);
  wait(1);
  ledOff(14);
  for(int n=13;n>10;n--) {
    ledOn(n);
    ledOn(28-n);
    wait(1);
    ledOff(n);
    ledOff(28-n);
  }
  allOff();
}

void letterY() {

  for(int i=17;i>14;i--) {
    ledOn(i);
    wait(.5);
    ledOff(i);
  }
  ledControl(5, 11,12,13,14,1);
  for(int i=15;i<18;i++) {
    ledOn(i);
    wait(.5);
    ledOff(i);
  }

  allOff();
}

void letterZ() {

  ledControl(4, 11,16,17, 1);
  ledControl(4, 11,15,17, 1);
  ledControl(4, 11,14,17, 1);
  ledControl(4, 11,13,17, 1);
  ledControl(4, 11,12,17, 1);

  allOff();
}

void Zero() {
  
  ledControl(6, 12,13,14,15,16, 1);
  ledControl(4, 11,15,17, 1);
  ledControl(4, 11,14,17, 1);
  ledControl(4, 11,13,17, 1);
  ledControl(6, 12,13,14,15,16, 1);

  allOff();
  }
void One() {

  space();
  
  ledControl(8, 11,12,13,14,15,16,17, 1);

  for(int n=16;n<14;n--) {
    ledOn(n);
    wait(1);
    ledOff(n);
  }

  space();
  allOff();
  }
  
void Two() {
  
  ledControl(3, 11,16, 1);
  ledControl(4, 11,15,17, 1);
  ledControl(4, 11,14,17, 1);
  ledControl(4, 11,13,17, 1);
  ledControl(4, 11,12,17, 1);
  ledControl(4, 11,15,16, 1);

  allOff();
  }
  
void Three() {

  ledControl(5, 12,13,15,16, 1);
  ledControl(4, 11,14,17, 4);
 
  allOff();
  }
  
void Four() {
  
  led14On;
  wait(1);
  led14Off;

  ledControl(8, 11,12,13,14,15,16,17, 1);

  led14On;
  wait(2);
  led14Off;

  ledControl(5, 14,15,16,17, 1);

  allOff();
  }
  
void Five() {

  ledControl(5, 12,13,14,17, 1);
  ledControl(4, 11,15,17, 2);
  ledControl(5, 11,15,16,17, 1);

  allOff();
  }
  
void Six() {
  
  ledControl(3, 12,13, 1);
  ledControl(4, 11,14,17, 1);
  ledControl(4, 11,14,17, 1);
  ledControl(4, 11,14,17, 1);
  ledControl(6, 12,13,14,15,16, 1);

  allOff();
  }
  
void Seven() {
  
  ledControl(4, 15,16,17, 1);

  for(int n=14;n>=11;n--) {
    ledControl(3, n,17, 1);
  }

  allOff();
  }
  
void Eight() {
  
  ledControl(5, 12,13,15,16, 1);
  ledControl(4, 11,14,17, 3);
  ledControl(5, 12,13,15,16, 1);

  allOff();
  }
  
void Nine() {
  
  ledControl(6, 12,13,14,15,16, 1);
  ledControl(4, 11,14,17, 3);
  ledControl(4, 12,15,16, 1);

  allOff();
  }

void Comma() {

  ledControl(2, 11, 1);
  ledControl(2, 10, 2);

  allOff();
  
}

void Colon() {

  ledControl(3, 13,15, 1);

  allOff();
  
}

void semiColon() {

  ledControl(3, 11,13, 1);
  ledControl(2, 10, 2);

  allOff();
  
}

void Period() {

  ledControl(2, 11, 1);

  allOff();
  
}

void Exclamation() {

 ledControl(7, 11,13,14,15,16,17, 1); 

 allOff();
 
}

void Question() {

  ledControl(3, 15,16, 1);
  ledControl(3, 14,17, 2);
  ledControl(4, 11,13,17, 1);
  ledControl(2, 16, 1);

  allOff();
  
}

void space() {

  wait(2);
  
}

// ---------------------------- END OF ANIMATIONS - - - BEGINNING OF PROGRAM LOOPS --------------------------- //

void setup() {
  
  for(int n=0;n<19;n++) {
    pinMode(n, OUTPUT);
  }

  //Intialize & Test LEDs

 ledOn(0); delay(100); ledOff(0);
 ledOn(1); delay(100); ledOff(1);
 for(int n=3;n<19;n++) {
    ledOn(n);
    delay(100);
    ledOff(n);
  }
  ledOn(2); delay(100); ledOff(2);
  
  test();
  
  for(int n=0;n<5;n++) {
    ledOn(10);
    ledOn(9);
    delay(100);
    ledOff(10);
    ledOff(9);
    delay(100);
  }

  timestart = 0;
  ledOn(2);

}

void loop() {

  int rpm=1/(timeCycle/1000)*60, rpmDigit;
  delayrpm = 1/(timeCycle/1000)*60;
  int half = delayrpm/2;

  if(counter<=90) ledOn(18);
  else ledOff(18);
  
  if(analogRead(5)<950) {

    if(previous == false) {
      timeCycle = millis()-timestart;
      timestart = millis();
    }


// ****--------------------------------------------------------------------------------------------------------**** //


    char MESSAGE[] = "Hello";  //------------Enter Message Here-----------//

    
// ****-------------------------------------------------------------------------------------------------------**** //

    int len = strlen(MESSAGE);
    strupr(MESSAGE);

    if(strcmp(MESSAGE,"RPM") != 0) {
      
      if(len <= 10) {

        for(int n=len-1;n>=0;n--) {

          switch(MESSAGE[n]) {

            case ' ' :
              space(); space(); space();
              break;
            case 'A' :
              letterA();
              break;
            case 'B' :
              letterB();
              break;
            case 'C' :
              letterC();
              break;
            case 'D' :
              letterD();
              break;
            case 'E' :
              letterE();
              break;
            case 'F' :
              letterF();
              break;
            case 'G' :
              letterG();
              break;
            case 'H' :
              letterH();
              break;
            case 'I' : 
              letterI();
              break;
            case 'J' :
              letterJ();
              break;
            case 'K' :
              letterK();
              break;
            case 'L' :
              letterL();
              break;
            case 'M' :
              letterM();
              break;
            case 'N' :
              letterN();
              break;
            case 'O' :
              letterO();
              break;
            case 'P' :
              letterP();
              break;
            case 'Q' :
              letterQ();
              break;
            case 'R' : 
              letterR();
              break;
            case 'S' :
              letterS();
              break;
            case 'T' :
              letterT();
               break;
            case 'U' : 
              letterU();
              break;
            case 'V' :
              letterV();
              break;
            case 'W' :
              letterW();
              break;
            case 'X' : 
              letterX();
              break;
            case 'Y' :
              letterY();
              break;
            case 'Z' : 
              letterZ();
              break;
            case '0' :
              Zero();
              break;
            case '1' : 
              One();
              break;
            case '2' : 
              Two();
              break;
            case '3' :
              Three();
              break;
            case '4' :
              Four();
              break;
            case '5' : 
              Five();
              break;
            case '6' :
              Six();
              break;
            case '7' :
              Seven();
              break;
            case '8' : 
              Eight();
              break;
            case '9' : 
              Nine();
              break;
            case ',' :
              Comma();
              break;
            case '.' : 
              Period();
              break;
            case ';' :
              semiColon();
              break;
            case ':' :
              Colon();
              break;
            case '?' :
              Question();
              break;
            case '!' :
              Exclamation();
              break; 
              
          }
        
        }
      }

      else {

        // slider function here //---------------------------------
        
      }
    }

    else {

      while(rpm!=0) {
        rpmDigit = rpm % 10;
        rpm = rpm / 10;
  
        if(rpmDigit==0) { Zero(); }
        else if(rpmDigit==1) { One(); }
        else if(rpmDigit==2) { Two(); }
        else if(rpmDigit==3) { Three(); }
        else if(rpmDigit==4) { Four(); }
        else if(rpmDigit==5) { Five(); }
        else if(rpmDigit==6) { Six(); }
        else if(rpmDigit==7) { Seven(); }
        else if(rpmDigit==8) { Eight(); }
        else if(rpmDigit==9) { Nine(); }
      }

      space(); space(); space();
      letterM();
      letterP();
      letterR();
    }

    previous = true;

  }
  
  else previous = false;
  
  if(counter>=300) counter=0;
  counter++;
  
}
