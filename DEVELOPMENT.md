**April 9th, 2019:**

Up until this date, the final project was finalized and an external library was selected. Tetris will be using the Open Graphics Library
(OpenGL). A project in Visual Studios was configured with OpenGL to open a window without having any errors. This will allow for an already
set up library to further develop Tetris' graphics. Needed to download OpenGL with GLFW and set up the project according to a tutorial.

*The plan for next week:*
Get familiar with ofxGui to create a user interface to start a game of Tetris. Mainly focus on writting code for the algorithms to run Tetrus.

**April 16th, 2019:**

Up until this date, I have familiarized myself with OpenFrameworks and the already integrated graphics librarie. This week I loaded a background
image to be applied to the window that pops up. After this, I created the base of my game, which will be a square referenced in terms of Tetris,
as the game block. An individuale game block represents one unit and the game board is made up up X by Y game blocks. Game blocks will also be used
later on to create the Tetromino pieces. I have initialized a game board and also the graphics that go along with it so that the game board is visible
when the program is run. 

*The plan for next week:*
Create all the different teromino pieces with the game block which have already been created. Create a method to randomly generate one of the
tetrominoes every time interval. I also want to get familiar with using the physics libary to greate the gravitional effect when the tetromino falls. 

**April 23rd, 2019:**

Up until this date, I utilized the game blocks created before to construct the 7 basic tetromino shapes. First I created vectors of points for each of the 7 tetrominoes and then I called Gameblock.draw() on them so that it would create a graphical shape with color. I was able to generate random tetrominoes and make them appear on the game board. I was also able to control them using the arrow keys and also made sure that they did not leave the game board. 

*The plan for next week:* Create a better collision detection system that can detect when a tetronimo hits another tetronimo that is sitting at the bottom of the game board. Implement two functions that rotate the tetromino clockwise and counterclockwise. Make the tetromino stay on the gride when a new one is generated so that Teris can be played. Create a game loop so that the blocks move down automatically. Test all testable functions and wrap up.  


**April 25th, 2019:**
Up until this date, I was able to make the generated tetrominoes stay on the board and not reset every time a new one was made. This was done by changing the color of the gride to the color of the tetromino so that it would appear that the tetromino is still there. I also utilized this to detected collisions. I let the tetromino fall until the next space it was going to move to would be filled with a color other than black. Collision detection methods were written for collisions that can happen at the bottom, right, and left of the tetromino block.

*The plan for next 4 days:* Create a way to handle the collision and make the block stay when it hits another tetromino. Have a game loop that keeps generating and moving tetrominoes down and faster as the level increases. Use the ofsound library to add music to the game that will go faster as the levels increase. Make a sound effect when the tetromino collides, and also add a sound effect to when a row is cleared and a level is passed. The next few days will be used to finish up the game implementation and focusing on final details and testing if possible. 
 
