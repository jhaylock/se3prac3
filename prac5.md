Prac 5 - Test Plans

2048 Game Test Plan
===================

1. Introduction
---------------

This document outlines a test plan for testing the 2048 game program. Included are the types of testing strategies that will need to be conducted, as well as the game functionality that needs testing. The main type of defects likely to be encountered in this program are syntax faults and algorithmic faults, so these areas are where the tests are focused.

2. Test Strategies
---------------

* Developer Testing - throughout development test cases are to be written before implementation. 
* Unit Testing - functionality is broken into manageable pieces that are tested individually. 
* Black Box tests - sufficient sample inputs and expected outputs for various board tilting configurations are to be created. 
* White Box tests - boundary tests will be used to help ensure the tilting algorithm works as intended.

3. Functionality to be Tested
---------------

* Game detects keyboard inputs as expected.
* Tilting board up, tiles slide up to fill topmost empty tiles.
* Tilting board down, tiles slide down to fill bottommost empty tiles.
* Tilting board left, tiles slide left to fill leftmost empty slots.
* Tilting board right, tiles slide right to fill rightmost empty slots.
* Same number tiles combine after tilting to produce correct resulting number tile.
* A tile generated from combining cannot combine again in the same instance of tilting.
* After tilting, one new tile is spawned in a random empty spot on the board.
* If every tile is filled, game detects when no more moves can be made and declares 'game over'.
* Display shows correct tile values after tilts. 
* Score updates with correct values for each combination made.
* 'New Game' command resets tile values, display, and score.

4. Not to be Tested
---------------

This plan tests functionality and excludes areas like performance and compatibility. Initially the display is to be text based, making these types of tests unnecessary. If the game was updated in the future, further test areas would be required such as performance, usability, configuration, installation, and documentation testing.

5. Conclusion
---------------

The most crucial part of the game is the tilting and combining of tiles on the board, this needs to work without fault or the game itself is broken. The test strategies outlined above will help ensure defects are eliminated from the program. 
