**Final Project**

*Description*

For the final project, I would like to develop the game Tetris. Tetris is a video game made in 1984 by a Soviet
Russian game designer Alexey Pajitnov. The game utilizes tetrominoes which polynomials made up of 4 blocks. The
objective of the game is to manipulate the tetrominoes by rotating and moving them while they fall to the bottom.
If a row is filled with blocks, it is cleared. Every time a row is cleared the game moves to a new level, causing
the tetrominoes to fall fasters. The game ends when the blocks reach the top of
the grid. 

*Overview/Approach*

I would like my game to start off with some sort of a home page where the user will be given the choice to start 
a new game. I will be using ofxGui which is an Openframeworks library used to create a simple graphical user 
interface which contains panels, buttons, and sliders. I will use a button to start the game and also if possible 
have a slider to change the rate at which the tetrominoes will fall, for adjusting difficulty. 

The game will be a large loop that will keep on going until the grid is full of tetrominoes, this will cause the 
loop to end, ending the game. Some of the methods needed for Tetris to function would be move right, move left, 
move down, and rotate. These functions will be used to control the terminal as it falls. Also, a method to check 
if a row is filled is needed and also a method to delete a row is trivial. A gravity simulator will also be needed
to move the terminals down as if they were falling at a constant rate.

For the external library, I will be using the Open Graphics Library (OpenGL) which is an API for rendering 2D and 
3D vector graphics. This API usually interacts with the graphics processing unit to achieve hardware accelerated
rendering. I will be using OpenGL to create the tetrominoes and also the game board graphics for Tetris. I will 
also use OpenGL to manipulate the tetrominoes while they are falling. While the game is running I want to create 
a side panel with the current score and the time elapsed. I would also like to add background music to the game 
using the OfBaseSoungPlayer library to play music.  

**Resources**

Tetris algorithem overview:
http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

OpenGL tutorial:
https://www.youtube.com/watch?v=AwVVt9Ht5Q8

Creating shapes with OpenGL:
https://www.youtube.com/watch?v=EIpxcNl2WJU