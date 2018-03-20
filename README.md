# Programmable Air

## Elevator Pitch

[Slideshow](https://docs.google.com/presentation/d/1pUnGk4v_wuCpisjBpNWZSJUyDwAFb4v1xceV4rX-Uv4/edit?usp=sharing)

I started out making in earnest at IISc where I saw niche markets being exploited by hardware manufacturers. Sub-par equipment is often lauded as the best solution only because it's the only solution. As a result I worked directly with researchers making equipment for measuring elephant height, insect wing- beat frequency, underwater gates for fishes.. I see the same issue with soft robotics today.

The field of inflatable robotics is still in it's infancy. So there are a lot of low hanging fruit up for grabs. As such, the more people involved in active experimentation, the faster the field will mature.

Experimenting with inflatables involves a lot of experimentation as a part of the design process. To do any repeatable experiments with inflatables, a programmable air source is required.

I feel there isn't any affordable and easy to use programmable air source available for makers right now. This is a barrier to entry. I want create the bottom line programmable air source, for under 100$ and easier to setup and use than anything available right now.

### What's wrong with the current solutions?

#### Pneuduino: [link](http://pneuduino.org/)

Not available for purchase. Potentially fallen out of development(last commit on github was about two years and the primary engineer has graduated out of the program.)

#### Fluidic control system: [link](https://softroboticstoolkit.com/book/control-board)

Truly designed by researchers for reserchers. Ugly. Complicated to setup. Needlessly expensive. [BOM](https://softroboticstoolkit.com/book/controlboard-bom)

Methods of potentially reducing cost:

- __Cheaper pump__: The [current pump](http://ph.parker.com/us/12051/en/btc-iis-and-ttc-iis-miniature-diaphragm-pump) at ~288$ is overpriced if not necessarily overspec'ed. I'm confident a replacement would be available for one tenth the cost.
- __Cheaper valves__: High switching rate is not necessary for most applications. The current valves cost ~175$. An acceptable replacement would be [this](https://www.elecrow.com/dc12v-four-way-valve-independent-control-solenoid-valve.html) at ~10$. Since pressure is controlled by PWM of the valves, this may lead to some issues if these actuators can't be driven fast enough. Some slack can be made up for by adding a "capacitor" after the valve. But, if the actuation time is of the order of hundreds of milliseconds, I may need a different approach. One such approach can be servo driven drip knobs. Another approach could be a linear actuator driving a plate covering a slit
- __Get rid of the power boards__: There's no need for a 24V in which then gets converted to 12V and 5V on board. It adds bulk and points of failure. Separate 12V and 5V wall warts will be much more reliable and cheaper. Cost saving ~20$
- Get rid of mosfets: A ULN2803 would be just as well suited to the task at a fraction of the price. It would also be much more reliable against electrostatic shock.
- __Cheaper air pressure sensors__: The same vendor makes [pressure sensors](https://www.digikey.com/product-detail/en/honeywell-sensing-and-productivity-solutions/NBPLANN100PAUNV/480-5540-ND/3475899) at a forth the price, which only need minimal external circuit to become nearly as accurate. This would add complexity to the first design of the build but bulm manufacture would benefit from the cost saving.
- __Cheaper arduino alternative__: An arduino mega is overkill for this. Any atmega324 based boards is sufficient

The __weakest link__ in this setup however is the __mess of jumper cable__ connections. There is no justifiable reason for a beginners kit to be this complicated to setup especially when the cost can be reduced simultaneously by making the setup into a PCB.

Pressure profiles editable on the browser.
Wifi board host server, no programming.
