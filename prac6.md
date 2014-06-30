Prac 6 - In-Car GPS Software Test Plan
==========

Introduction
------------
This document presents a test plan for the design and testing of software for an in-car GPS navigation system. In order to break this system down into manageable pieces we first look at the steps involved in using it. The software is then decomposed into pieces and each piece is to be subjected to testing before being assembled into the final product. 

Steps
-----
This is an outline of the steps involved in using the GPS navigation software.
 
1. User access the GPS navigation system
2. User specifies target destination
3. Software calculates optimal route to destination
4. User follows route and software updates as it goes
5. User reaches destination

Decomposition
-------
The software is broken down into components. 

* Software interface with car
* User interface
  * GUI display
  * Touch input controls
  * Button input controls
* Route calculation
  * Determining current location
  * Determining destination location
  * Calculating optimal route using digital maps and user criteria
  * Estimating travel time / arrival time

Risks
------

* The area of most risk is the route calculation subsystem. The algorithm for determining the best route is still the most complex component of the software. It has to take into account the user's specified criteria for best route and factors such as distance, road speeds, and fuel consumption. This component will likely require the most rigorous testing. 
* Inaccurate maps are another big risk though this is not an area that can be easily worked around in the software. Frequent map updates would be necessary.
* Losing or being unable to find the location of the car is a big risk. Without this information a route to the destination cannot be generated. One solution could be letting the user specify their location on a map in the event of this failure. 


Most Important Types of Tests
-----------------
These types of tests are the most important for this project.

* Unit Tests: Because the software can be easily broken down into different units of code, unit testing is easy to implement and is important as it helps catch faults early, at a point where they are easier and cheaper to fix. Unit testing also makes it easier to integrate these separate components. 
* White-box Tests: While complex, this testing method would be useful in thoroughly testing the route calculation algorithms. Branch and condition coverage ensures the algorithm is efficient and working as intended.
* Usability Tests: for the user interface part of this software user and usability tests are very important. Involving users in testing is necessary to ensure the software can be understood and operated by the target users, especially for commercial software.
Other important types of tests are: performance, configuration, documentation.

Less Important Types of Tests
----------------
These tests are not relevant to this project.

* Black Box Tests: the large number of possible locations, destinations, and optimal routes make this type of testing difficult. The number of input and output cases necessary to sufficiently test the software this way may be prohibitive. 
* Security Tests: less important than the above test types since the software will be on a fairly isolated device, communicating only with GPS satellites, and the information it stores is not very sensitive. 
* Stress Tests: less important as the program is unlikely to encounter large loads that need to be handled quickly. 


