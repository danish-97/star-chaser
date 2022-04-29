Star-Chaser
----------------------------------------------------------------------------------------------------------------
*"The darkness arrives, and the boy closes his eyes. As his consciousness slowly fades away, he knows he can no longer see tommorrow’s light. Before his mind collapses, once again he sees that starry night.  No more despair and desolution, he shakes off the weight and starts flying. Higher and higher he ascends, till he forgets all the pain and scars, till he reaches those flickering stars."*

ENCE260 embedded system assignment, Semester 2 2021, University of Canterbury.
Code written by Kaishun Yang and Danish Khursheed, group number 511.
Designed specifically for the UC Fun Kit 4.

Game Instruction - How to Play
---------------------------------------------------------------------------------------------------------------

* Star chaser has three phases it transitions to : intro phase - game phase - game-over phase. 
      
* The goal of the game is to collect as many stars (the blinking dots) as possible without running into the borders of the matrix.
    
* Press the push button on the micro-controller to start the game, you'll see the chaser dot appear from the left corner of the matrix. 
      
* Players can use the navswitch to control the chaser dot to consume randomly generated *"stars"*, which are the flashing dots simutaneously shown on the led matrix with the chaser dot. Every time the chaser consumes a star, another star will randomly spawn on the led matrix. 
      
* Each time the chaser collects a certain amount of stars, its speed will increase. As the game goes on, chaser will move faster and faster, but after it reaches a certain speed (maximum speed), it won't increase anymore.  
      
* The game will transition to game-over phase if the chaser crashes into the four boundaries of the led matrix, we call these boundaries *"Walls"*.   
      
* In the game-over sceen, a game over message and the mark of player are shown. The player mark indicates how many stars the player collected in the game.
      
* To reset the game, player need to press S3 button while holding S2 button. 
     
Complier Instruction
----------------------------------------------------------------------------------------------------------------

* You can download the game onto your selected folder by using the command git clone https://eng-git.canterbury.ac.nz/ence260-2021/group_511.git from the
terminal or by downloading it as a zip file from the address https://eng-git.canterbury.ac.nz/ence260-2021/group_511.

* If using the terminal to clone, make sure to initialise your chosen folder to clone the game into as a git repository using the command *"git init"*.
    
* To compile the game, open the terminal and navigate to the destination where the make file of the game folder is present.

* Use the command *"make program"* to run the game.
