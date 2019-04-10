	For the final project I would like to develop the game Tetris int C++ and Open Frameworks. Tetris is a video game made in 
1984 by a Soviet Russian game designer Alexey Pajitnov. The game utilizes tetrominoes which polynomials made up of 4 blocks. 
The objective of the game is to manipulate the tetrominoes by rotating and moving them while they fall to the bottom. If a 
whole row is filled with blocks, then the row is cleared. When a row is cleared a new level is also entered, causing the 
tetrominoes to fall fasters. The game ends when the blocks reach the top of the grid and the player then loses. 

	I would like my game to start of with some sort of a home page where the user will be given the choice to start a new game. 
I will be using ofxGui which is an Openframeworks library used to create a simple graphical user interfacee which can contain
panels, buttons, and sliders. I will use a button to start the game and also if possible have a slider to change the rate at
which the terominoes will fall. 

	For the external library I will be using the Open Graphics Library (OpenGl) which is an API for redering 2D and 3D vector 
graphics. This API usually interacts with the graphics processing unit to achiece hardware accelerated rendering. I will
be useing OpenGl to create the tetrominos and also the game board graphics for Tetris. While the game is running I want to create
a side panel with the current score and the time durration of the game. I would also like to add background music to the game 
using the OfBaseSoungPlayer library to play music. This library will make it a lot easier to load and play music. 

Resources that I have found and looked over:

Tetris algorithem overview:
http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

OpenGL tutorial:
https://www.youtube.com/watch?v=AwVVt9Ht5Q8

Creating shapes with OpenGL:
https://www.youtube.com/watch?v=EIpxcNl2WJU