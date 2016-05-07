# Bus Stop Blinkers

The goal of this project is to create a lightweight but durable _field_ indicator that can be installed at bus stops, to indicate how many minutes away a bus is from the current field sensor.

This concept was presented to me by Adam from [Civilla Detroit](http://www.civilla.com/) inspired by their project [_Reimagining the public transit experience in the city of Detroit_](http://www.civilla.com/work/).

I intend to fully open source the hardware files and the software so that other municipalities may adjust it and use it based on their needs.

This project is dependant on the [DDOT Real Time Data API](http://ddot-beta.herokuapp.com/api/api/where/vehicles-for-agency/DDOT.json?key=LIVEMAP) provided. Check out the [live map](http://hampelm.github.io/bus-map/) as well. 

### Project Roadmap

1. Hard coded single implementation. Customer feedback from bus riders. Battery powered + WiFi.
2. GPS single implementation. 3G connectivity. Battery + Solar.
3. GPS multiple implementation. Large display + additional information. 3G connectivity. Battery + Solar. iOS configuration App.
4. Everything finalized from 3. + PCB & smaller, embedded chipset.

### Parts List

- [Particle Photon](https://www.particle.io/prototype)
- [Aluminum Enclosure](https://www.sparkfun.com/products/11351)
- [Super Bright 10mm LED](https://www.sparkfun.com/products/8860)
- [Some Cables]()
