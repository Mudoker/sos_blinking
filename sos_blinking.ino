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
        case 'A':
            short_blink();
            long_blink();
            break;
        case 'B':
            long_blink();
            short_blink();
            short_blink();
            short_blink();
            break;
        case 'C':
            long_blink();
            short_blink();
            long_blink();
            short_blink();
            break;
        case 'D':
            long_blink();
            short_blink();
            short_blink();
            break;
        case 'E':
            short_blink();
            break;
        case 'F':
            short_blink();
            short_blink();
            long_blink();
            short_blink();
            break;
        case 'G':
            long_blink();
            long_blink();
            short_blink();
            break;
        case 'H':
            short_blink();
            short_blink();
            short_blink();
            short_blink();
            break;
        case 'I':
            short_blink();
            short_blink();
            break;
        case 'J':
            short_blink();
            long_blink();
            long_blink();
            long_blink();
            break;
        case 'K':
            long_blink();
            short_blink();
            long_blink();
            break;
        case 'L':
            short_blink();
            long_blink();
            short_blink();
            short_blink();
            break;
        case 'M':
            long_blink();
            long_blink();
            break;
        case 'N':
            long_blink();
            short_blink();
            break;
        case 'O':
            long_blink();
            long_blink();
            long_blink();
            break;
        case 'P':
            short_blink();
            long_blink();
            long_blink();
            short_blink();
            break;
        case 'Q':
            long_blink();
            long_blink();
            short_blink();
            long_blink();
            break;
        case 'R':
            short_blink();
            long_blink();
            short_blink();
            break;
        case 'S':
            short_blink();
            short_blink();
            short_blink();
            break;
        case 'T':
            long_blink();
            break;
        case 'U':
            short_blink();
            short_blink();
            long_blink();
            break;
        case 'V':
            short_blink();
            short_blink();
            short_blink();
            long_blink();
            break;
        case 'W':
            short_blink();
            long_blink();
            long_blink();
            break;
        case 'X':
            long_blink();
            short_blink();
            short_blink();
            long_blink();
            break;
        case 'Y':
            long_blink();
            short_blink();
            long_blink();
            long_blink();
            break;
        case 'Z':
            long_blink();
            long_blink();
            short_blink();
            short_blink();
            break;
        case '1':
            short_blink();
            long_blink();
            long_blink();
            long_blink();
            long_blink();
            break;
        case '2':
            short_blink();
            short_blink();
            long_blink();
            long_blink();
            long_blink();
            break;
        case '3':
            short_blink();
            short_blink();
            short_blink();
            long_blink();
            long_blink();
            break;
        case '4':
            short_blink();
            short_blink();
            short_blink();
            short_blink();
            long_blink();
            break;
        case '5':
            short_blink();
            short_blink();
            short_blink();
            short_blink();
            short_blink();
            break;
        case '6':
            long_blink();
            short_blink();
            short_blink();
            short_blink();
            short_blink();
            break;
        case '7':
            long_blink();
            long_blink();
            short_blink();
            short_blink();
            short_blink();
            break;
        case '8':
            long_blink();
            long_blink();
            long_blink();
            short_blink();
            short_blink();
            break;
        case '9':
            long_blink();
            long_blink();
            long_blink();
            long_blink();
            short_blink();
            break;
        case '0':
            long_blink();
            long_blink();
            long_blink();
            long_blink();
            long_blink();
            break;
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
