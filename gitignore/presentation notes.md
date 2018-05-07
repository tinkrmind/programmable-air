# Programmable Air

### Presentation Demos:

* Universal gripper
* SMD pick and place
* Rube Goldberg
* Irregular impact sensor
*
* Exhalation


### Timeline:
* 1.5 min- inspiration & current solutions
* 0.5 min- common pressure ranges
* 1 min-

### Experts:
* Ben- look at similar industries -aquariums,
* Eric- get cheap second hand industrial stuff
* Tom- make a kick ass tutorial
* Sebastian- Don't reinvent the software, make a great library
* Yuli- Give full control of the air channel

### How does Programmable Air work?
* Components:
  - Pump board
    - Arduino nano
    - Two vacuum/air pressure pumps
    - Connections to accomodate up to three valve boards
    - Some LEDs and buttons
  - Valve board
    - +- 0.5 atm pressure sensor
    - Three normally closed valves

* Air channels for full control of pressure-

### Limitations
* Pressure range -0.5atm to +0.5 atm
  - Lots of interesting things happen outside this range
    - Solution
* Flow rate 2lpm
  - Not suitable for fast applications

### The journey
* Reading up on pneumatics
* Hours of searching for Components
* Ordering Components
* Designing PCBs
* Manufacturing PCBs
  - curves
  
### Mistakes made:
* Cheaping out on the ADC for pressure sensor - taring is annoying. Multi sensor support is still iffy
  - Solution: Move to an instrumentation amp with constant current driver. Haven't found one yet.
* Cheaping out on the air valves. They leak at high pressure and have high resistance to flow.
  - Solution: Evaluate the more valves. Haven't found a replacement yet.

#### Special thanks for lending equipment
* Kemi
* Keerthana and Azalea
* Sebastian
