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
buttons, and sliders. I will use a button to start the game and also if possible have a slider to change the rate at which the 
tetrominoes will fall, for adjusting the difficulty. the grid. 

The game will be a large loop that will keep on going until the grid is full of tetrominoes, this will cause the loop to end, ending 
the game. Some of the methods needed for Tetris to function would be move right, move left, move down, and rotate. These functions 
will be used to control the terminal as it falls. Also, a method to check if a row is filled is needed and also a method to delete
a row is trivial. A gravity simulator will also be needed to move the terminals down as if they were falling at a constant rate.

For the graphical components of Tetris I will be using of graphics library (of graphics) and this will allow me to create the 2D 
tetrominoes that will be needed in the game. The graphics library will also allow me to create the game board, which the tetrominoes
will be falling in. I will also be using Box2D which is a 2D physics engine for games, and it will allow me to drop the tetrominoes
according to gravity. I might also use this library to detect collisions. While the game is running I want to create a side panel 
with the current score and the time elapsed. I would also like to add background music to the game using the OfBaseSoungPlayer library

**Timeline**

Week 1: Read open frameworks documentation and get familiar with using it to create Tetris. Be able to use the graphics library to create 
the game board on which tetris will be played on and also the one unit square that will be the basis for the whole game. 

Week 2: Use the square made last week to create all the tetrominoes. Work on game logic and connecting that to the graphics of the tetrominoes.
Use physics libary to create the effect of the tetrominoes falling due to gravity. A goal for this week is to finish up the game loop to get it 
partly functioning. Create tests for the code that is written.

Week 3: Finish up game logic and overall game. Heavly test the project and fix any bugs that occur. If time permits I will want to add a score
board and also a time elapsed time. 

**Resources**

Tetris algorithem overview:
http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

Block2D documentation and tutorials:
https://box2d.org/about/

OpenFrameworks documentation:
https://openframeworks.cc/documentation/

