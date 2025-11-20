7-Segment Display Interface – ATmega16 🔢
Introduction

This project shows how to interface a common cathode 7-segment display with the ATmega16 microcontroller.
The program displays digits 0 to 9, each staying for one second.
This is a basic experiment to understand how segment codes work and how to send them through a port.

Requirements ⚙️

ATmega16

Atmel Studio 7

Proteus 8 Professional

Common Cathode 7-Segment Display

330Ω resistors (optional but recommended)

Jumper wires / simulation setup

Circuit Explanation 💡

All 7 segments (a–g) and the decimal point are connected to PORTD (PD0–PD7).
Since it is a common cathode type, writing a HIGH (1) lights up the corresponding segment.
The MCU outputs the correct hex values to form each digit.

Circuit Layout (Text Format)
ATmega16
PORTD (PD0–PD7) → a,b,c,d,e,f,g,dp pins of 7-segment
VCC → +5V
GND → Ground

Program Code (main.c) 🧑‍💻
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 0xFF;  // Configure PORTD as output

    int segment[10] = {
        0x3F, 0x06, 0x5B, 0x4F, 0x66,
        0x6D, 0x7C, 0x07, 0x7F, 0x6F
    };
    int i;

    while (1)
    {
        for (i = 0; i < 10; i++)
        {
            PORTD = segment[i];
            _delay_ms(1000);
        }
    }
}

How to Run in Atmel Studio ▶️

Create a new GCC project

Select ATmega16

Paste the above code into main.c

Build the project → HEX file generated

Proteus Simulation Steps 🖥️

Place ATmega16 and a 7-segment display

Connect PORTD pins (PD0–PD7) to the display

Load the HEX file into the MCU

Set clock to 8 MHz (internal)

Run simulation — digits 0 to 9 will display one by one

Output ✔️

The 7-segment display shows digits from 0 to 9 with a delay of 1 second between each.
