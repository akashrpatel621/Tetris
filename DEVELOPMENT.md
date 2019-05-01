# Development Log

## Progress - April 9th, 2019
- Created the project proposal and noted down a couple of libraries that can be used to to create Tetris.
- Set up a sample project and opened a blank window without crashing using OpenGL with GLFW.
- Read the documentation for OpenFrameworks.  

**Plane for next week:**
- Finalize the libraries that will be used in the project.
- Create a game block that will be used throughout the implementation of Tetris.
- Create a game board.

## Progress - April 16th, 2019
- Finalized that OpenFrameworks graphics library will be used and the sound library as an outside library.
- Loaded background and scaled the size of it to fit in the window properly.
- Created the GameBlock class.
  - 40 by 40 square.
  - fill and outline color.
  - can be drawn at a point.
  - bases of all other components.
- Created the GameBoard class which is used to generate the game board.
  - wrote functions to initialize the game board which is a 2D vector of GameBlocks. 
  - implemented the draw method for the game board.
  - now able to see a Tetris board when the program is run.

**Plane for next week:**
- Use the game blocks to create all seven tetrominoes.
- Get the tetrominoes to generate on the screen.
- Be able to control the tetrominoes on the game board by moving them right, left, and down. 

## Progress - April 23rd, 2019
- Created Shape class
  - contains a method that generates all seven game blocks and then returns a random one.
- Created Tetromino class.
   - class contains functions that:
   - generate tetrominoes with random colors.
   - translate the tetrominoes left, right, and down.
   - Bug: the generated tetromino would automatically clear once a new one is generated.
- Added two functions to the GameBoard class to remove a filled row and then slide the other blocks down.
- Implemented switch cases in the ofApp.cpp.
  - able to use the arrow keys to control the tetrominoes on the game board. 
- Added boundaries so that the tetrominoes could not be moved off the game board.

**Plane for next week:**
- Implement two rotate functions to rotate the tetrominoes.
- Create a better way to detect and handle collisions so that blocks will not overlap.
- Find a way to make the tetrominoes stay on the board after there is a collision.
- Create a conditional statement in the ofApp::update() to generate random tetrominoes and make them fall.
- Test all testable functions.
 
 
 ## Progress - April 25th, 2019
 - Able to make the tetrominoes stay on the game board.
   - created a collision handler which changed the color of the game board to the color of the tetromino. 
   - collision handling was only implemented when the tetromino hit the bottom of the grid. 
 - If statement was created in the ofApp:: update() method to generate a tetromino every second and make it look like it is dropping.
   - added condition in if statement so that the game can be paused and started. 
 - Implemented rotate functions to turn the tetrominoes clockwise and counterclockwise.
 - Used Sound library to load the background music.
   - can be paused and played. 
 
**Plane for the next 5 days:**
- Add to the collision handling function to handle collision between tetrominoes.
- Add a level system to speed up the rate at which the tetrominoes fall as the level increases.
- Utilize the sound library to make the background music speed up as more levels are passed.
- Play a sound effect when a tetromino is set and also play a sound effect when a row is cleared. 
- Fix the bug that crashing the game if the tetromino is rotated at the right edge of the board.
- Add testing for all testable functions. 

 ## Progress - May 1st, 2019
- Fixed bug that crashed the game when a tetromino was rotated at the right end.
  - used std::cout to print the x coordinates of the tetromino as it was rotated.
  - fixed issue by making sure that all x values were less than the number of columns. 
- Added a condition to the collision handling method to stop the tetromino from moving once it hits another tetromino. 
- Added counters to the GameBoard:: RemoveRow() method to:
 - count the score.
 - count the current level which is incremented every time a row is cleared. 
 - increment the music speed variable.
 - trigger the "row cleared" sound effect.
- Using the music speed variable, the music speeds up every time a row is cleared.
- Added a sound effect when a collision is detected to mock the sound of something being dropped. 
- Created a scoreboard.
  - loaded font in .ttf file for the score board. 
  - used score counter to update the score.
  - create a time elapsed counter using ofGetElapsedTimef() 
    - stop the time when the game is paused or when the game is over.
  - use the current level to display while the game is running.
- Added testing for all testable functions.
- Put a cap on the max speed for which the tetrominoes can be dropped at. 
- Added a sound effect to be played once the game has ended. 
- Added final adjustments and commented for better readability.
 
