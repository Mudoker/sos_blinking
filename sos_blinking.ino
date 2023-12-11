#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PORTB0
#define BUTTON_PIN PIND2

#define TIME_UNIT 1000

void short_blink() {
    PORTB |= (1 << LED_PIN);
    _delay_ms(TIME_UNIT);
    PORTB &= ~(1 << LED_PIN);
    _delay_ms(TIME_UNIT);
}

void long_blink() {
    PORTB |= (1 << LED_PIN);
    _delay_ms(TIME_UNIT * 3);
    PORTB &= ~(1 << LED_PIN);
    _delay_ms(TIME_UNIT);
}

void startMorseCode() {
    long_blink();
    short_blink();
    long_blink();
    short_blink();
    long_blink();

    // Delay 2 more time units before starting message sequence
    _delay_ms(TIME_UNIT * 2);
}

void endMorseCode() {
    short_blink();
    long_blink();
    short_blink();
    long_blink();
    short_blink();
}

char toUpperCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }

    return c;
}

void translateToMorse(char c) {
    switch (toUpperCase(c)) {
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

void translateToMorse(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ')
            _delay_ms(TIME_UNIT * 6);
        else {
            translateToMorse(str[i]);
            _delay_ms(TIME_UNIT * 2);
        }

        i++;
    }
}

int main() {
    // Set LED pin as output
    DDRB |= (1 << LED_PIN);

    // Set button pin as input with pull-up resistor (1 means no press)
    PORTD |= (1 << BUTTON_PIN);

    while (1) {
        if (!(PIND & (1 << BUTTON_PIN))) {
            startMorseCode();
            translateToMorse("SOS SOS");
            endMorseCode();
        }
    }

    return 0;
}