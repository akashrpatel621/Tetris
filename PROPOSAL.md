**Final Project**

*Description*

For the final project, I would like to develop the game Tetris. Tetris is a video game made in 1984 by a Soviet
Russian game designer Alexey Pajitnov. The game utilizes tetrominoes which polynomials made up of 4 blocks. The
objective of the game is to manipulate the tetrominoes by rotating and moving them while they fall to the bottom.
If a row is filled with blocks, it is cleared. Every time a row is cleared the game moves to a new level, causing
the tetrominoes to fall fasters. The game ends when the blocks reach the top of
the grid.

*Overview/Approach*

I would like my game to start off with some sort of a home page where the user will be given the choice to start a new game. 
I will be using ofxGui which is an Openframeworks library used to create a simple graphical user interface which contains panels,
buttons, and sliders. I will use a button to start the game and also if possible have a slider to change the rate at which the tetrominoes will fall, for adjusting the difficulty. I would like to get to this at the end of the project if the game is fully functional. 

The game will be a large loop that will keep on going until the grid is full of tetrominoes, this will cause the loop to end, ending the game. Some of the methods needed for Tetris to function would be move right, move left, move down, and rotate. These functions will be used to control the terminal as it falls. Also, a method to check if a row is filled is needed and also a method to delete
a row is trivial. A gravity simulator will also be needed to move the terminals down as if they were falling at a constant rate.

For the graphical components of Tetris, I will be using of graphics library (of graphics) and this will allow me to create the 2D 
tetrominoes that will be needed in the game. The graphics library will also allow me to create the game board, which the tetrominoes
will be falling in. Initially, I was thinking about using the physics library, Box 2d to create the effect of the tetrominoes falling and colliding, however, this was not needed. Instead, I will detect collisions myself. I will also be using the sound library to create sounds when the tetrominoes reach the floor, when a row is deleted, and when the game ends. I plan to have a scoreboard on the side panel and also the time elapsed in the current game. If time permits I would also like to implement a way to preview the next tetromino that will be generated.  

**Timeline**

Week 1: Read open frameworks documentation and get familiar with using it to create Tetris. Be able to use the graphics library to create the game board on which Tetris will be played on and also the one unit square that will be the basis for the whole game. Explore the sound library and be able to make a sound when a key is pressed. 

Week 2: Use the squares made last week to create all the tetrominoes. Implement a way to control the tetrominoes to rotate and move through user inputs. Create tests for the code that is written. 

Week 3: Finish up game logic and overall game. Heavily test the project and fix any bugs that occur. Add sounds for specific events in the game. If time permits I will want to add a scoreboard and also a time elapsed time. 

**Resources**

Tetris algorithm overview:
http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

Of Sound documentation and tutorials:
https://openframeworks.cc/ofBook/chapters/sound.html

OpenFrameworks documentation:
https://openframeworks.cc/documentation/
