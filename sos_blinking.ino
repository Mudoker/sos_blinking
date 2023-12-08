#include <avr/io.h>
#include <util/delay.h>

#define PORT13 100000

#define TIME_UNIT 200

void short_blink() {
  PORTB |= (1 << PB1);
  _delay_ms(TIME_UNIT);
  PORTB &= ~(1 << PB1);
}

void long_blink() {
  PORTB |= (1 << PB1);
  _delay_ms(TIME_UNIT * 3);
  PORTB &= ~(1 << PB1);
}

void startMorseCode() {
  long_blink();
  short_blink();
  long_blink();
  short_blink();
  long_blink();
}

void endMorseCode() {
  short_blink();
  long_blink();
  short_blink();
  long_blink();
  short_blink();
}

void translateToMorse(char c) {
  switch (c) {
    case 'a':
      
  }
}

void translateToMorse(char[] str) {
  for (int i = 0; i < str.size(); i++)
    translateToMorse(str[i]);
}

int main() {
  DDRB |= (1 << PB1);

  while (1) {
    startMorseCode();
    translateToMorse("SOS");
    endMorseCode();

    // Delay next start
    _delay_ms(TIME_UNIT * 5);
  }

  return 0;
}
