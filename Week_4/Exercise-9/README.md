# Outputing 8 LEDs with different on off duration

Hi everyone, this is a quick and simple tutorial on how to blink multiples LEDs with different durations at the same instants. 

Instead of using the cliche way to code the program, this code uses array and object oriented programming (OOP) format.

Guidances to be refered have been attached such as code, picture, video and schematic diagram of the experiment.

# Parts needed:

1x Arduino (NANO)

1x Breadboard

8x LED (any type)

8x Wires (min)

1x 100Ohm resistor (or any suitable resistance)

# Wiring the circuit:

Pin Assignments:

![8-led-schematic](https://user-images.githubusercontent.com/73819172/102447504-05ec9080-406b-11eb-81c9-c26e9859dec1.PNG)

D2  = LED 1's anode leg

D3  = LED 2's anode leg

D4  = LED 3's anode leg

D5  = LED 4's anode leg

D6  = LED 5's anode leg

D7  = LED 6's anode leg

D8  = LED 7's anode leg

D9  = LED 8's anode leg

GND = All LEDs' cathode legs 

The resistor shall be put in between the GND and LED's cathode legs

Note that this experiment can still be done with different type of Arduino, LEDs and resistors by modifying the pin assignment and value:

- If using other Arduino, the pins assign to the LEDs shall always be a digital or analog pin.
- Any type of LEDs that are suitable for the circuit is okay.
- The value of resistor used will determine the brightness of the LEDs

# Code the program

The code provided on the page has been commented with layman words to ease the understanding of the program flow

The results and simulation of the program have been attached.


# Thank You
