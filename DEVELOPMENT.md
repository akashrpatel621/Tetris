#Development Log

##Progress - April 9th, 2019
- Created the project proposal and noted down a couple of libraries that can be used to to create Tetris.
- Set up a sample project and opened a blank window with out crashing using OpenGL with GLFW.
- Read the documentation for OpenFrameworks. 

**Plane for next week:**
- Finalize the libraries that will be used in the project.
- Create a game block that will be used throughout the implemtation of Tetris.
- Create a game board.

##Progress - April 16th, 2019
- loaded background for the tetris game and scaled the size for it to be seen in the window.
- Created the GameBlock class.
  - 40 by 40 square.
  - fill and outline color.
  - can be drawn at a point.
  - bases of all other components.
- Created the GameBoard class which is used to generate the game board.
  - wrote functions to initialize the game board which is a 2D vector of game blocks. 
  - implemented the draw method for the game board. 

**Plane for next week:**
- Use the game blocks to create all seven tetrominoes.
- Get the tetrominoes to generate on the screen.
- Be able to control the terominoes on the game board by moving them right, left, and down. 

##Progress - April 23rd, 2019
- Created tetrominoshape class
  - contains methods that generate all seven game blocks and then returns a random one.
- Created tetromino class.
  - class contains fuctions that:
    - generate tetrominoes with random colors.
    - translate the tetrominoes left, right, and down.
    - Bug: the generated tetromino would automaticly clear once a new one is generated.
- Added two fuctions to the GameBoard class that slidess down the game board and removes a while row if it is filled.
- Used the arrow keys to controll the tetrominoes on the game board. 
- Added boundaries so that the tetromines could not be moved off the game board.

**Plane for next week:**
- Create a better way to detect and handle collisions so that blocks will not overlap.
- Implement two rotate functions to rotate the tetrominoes.
- Fix the bug to make the tetrominoes stay on the board after there is a collision.
- Create a loop to generate new tetromines at a set time interval automatically.
- Test all fuctions that can be tested
 
 ##Progress - April 25th, 2019
 - Able to make the tetrominoes stay on the game board.
   - created a collision handler which changed the color of the game board to the color of the tetromino. 
   - Collision handeling was only implemented when the tetromino hit the bottom of the grid. 
 - If statement was created in the ofApp::update() methode to generate a tetromino every second and make it look like it is dropping/
 - Implemeted rotate funtions to rotate tetrominoes clockwise and counter clockwise.
 
**Plane for next week:**
- Add to the collision handling function to handle collision between tetrominoes.
- Add a level system to speed up the rate at which the tetrominoes fall as the level increases.
- Utilize the ofSound library to add music to the background that speeds up as the levels increase.
- Play a sound effect when a tetromino is set and also play a sound effect when a row is cleared. 
- Focus of fixing the bug that crashing the game if the tetromino is rotate at the right edge of the board.
- Add testing for all testable functions. 
 
