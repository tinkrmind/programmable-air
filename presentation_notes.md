# Programmable Air

I started making in earnest when I was at Indian Institute of Science. I found my niche there as the engineering advisor for the Center of Ecological Sciences. I'd often see sub par equipment being lauded as the best solution simply because it was the only solution. In my battle against overpriced equipment I made a height sensor for elephants, a wind tunnel, sensor for measuring insect wing beat frequency amongst other things.

So when I looked at the Harvard soft robotics kit, I was in familiar terrain. The kit is obviously designed by researchers for researchers. It is expensive, ugly and bulky. Kinda the worst of all worlds. Programmable Air is a project born out of pure hatred.

### The journey
* Reading up on pneumatics
  - Guage pressure, absolute pressure, differential pressure
  - Who uses hectopascals and dLpms?
* Dozens of hours searching for Components
  - dozens of websites
  - hundreds of Components
  - figuring out components that are not only compatible electrically and have the same pressure range and flow rate but also use the same size connectors
* Ordering Components
  - the bane of every fabrication project - the wait-time
* Evaluating components
  - evaluated five motors
  - few different valve types
* Designing PCBs
  - Eagle vs KiCAD
  - obscure components had to design the component libraries
* Manufacturing PCBs
  - Curves! - annoying to get right, but a treat for eyes and ears
* Getting it wrong
  - Redesign, remake
  - *Throw PCBs* It's safe to say that I've made a few mistakes

### How does Programmable Air work?
* Components:
  - Pump board
    - Arduino nano
    - Two vacuum/air pressure pumps
    - Connections to accommodate up to three valve boards
    - Some LEDs and buttons
  - Valve board
    - +- 0.5 atm pressure sensor
    - Three normally closed valves

* Air channels for full control of pressure-

### Limitations
* Pressure range -0.5atm to +0.5 atm
  - Lots of interesting things happen outside this range
    - Caveat: higher pressure range will need better, costlier connectors
* Flow rate 2lpm
  - Not suitable for fast applications
    - Caveat: faster pumps and valves will increase size and power requirement

### Experts:
* Ben- look at similar industries -aquariums,
* Eric- get cheap second hand industrial stuff
* Tom- make a kick ass tutorial
* Sebastian- Don't reinvent the software, make a great library
* Yuli- Give full control of the air channel

### Special thanks for lending equipment
* Kemi
* Keerthana and Azalea
* Sebastian
* Lola

### Mistakes made:

* Cheaping-out on the ADC for pressure sensor - taring is annoying. Multi sensor support is still iffy
  - Solution: Move to an instrumentation amp with constant current driver. Haven't found one yet.
* Cheaping-out on the air valves. They leak at high pressure and have high resistance to flow.
  - Solution: Evaluate the more valves. Haven't found a replacement yet.

### Presentation Demos:

* Universal jamming gripper
* SMD pick and place
* Rube Goldberg
* Irregular impact sensor
  - leave room for serendipity
* Balloon pressure
* Exhalation

### What else can you make?
* Bubbles!
* Wind instruments!

### Timeline:
* 1.5 min- inspiration & current solutions
* 0.5 min- common pressure ranges
* 1 min-

### What I want from you!
* How do you see programmable air?
  - (a) A kit like makey makey?
  - (b) Little bits or grove modules
  - (c) Standalone Arduino compatible modules
  - (d)

Audience: ITP first year student

### BOM

For production of 10 units.

|Item|Cost|
|---|---|
|Pumps|8$|
|Valves|9$|
|Pressure sensor|12$|
|Arduino Nano| 4$|
|TIP120|2$|
|Passives| 2$|
|LEDs|1$|
|Electrical connectors|1$|
|PCBs|2$|
|Tubes|2$|
|Pneumatic connectors|2$|
|Power supply|3$|
|USB Cable|2$|
|Total|50$|
