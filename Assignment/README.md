![block diagram](https://user-images.githubusercontent.com/73819172/103340336-be302500-4abe-11eb-9e20-78afc8df7959.PNG)

There will be four inputs for the project. There will be count and total instructions to calculate the amount of ball have been taken for each player and for the whole game respectively.

Initially, the controller will only receive input given by Button 1. Upon receiving the signal from Button 1, the controller will instruct the servo to move the ball. Accordingly, count and total for ball will change from 0 to 1 and the LED indicator for ‘1 ball’ will turn on. 

The controller will wait for another from Input A, but this time it can either be from Button 1 or Button 2. If the controller receives signal from Button 1, then the servo will again move the ball, the count increase from 1 to 2 and the led indicator for ‘2 ball will turn on.

However, if the controller receive signal from Button 2, the count will be reset to 0 yet the total ball will remain.

Upon receiving signal from Button 2, the controller will neglect any signals from Input 1 afterwards, only welcoming signal from Input B. The same process occurs where the controller will only receive signal from Button 3 to move the ball. Only for the next play, the controller can receive the signal from Button B. 

The signals from Input A and Input B will determine the winner of the game. Once the total number is equal to the set amount in the controller will check the winner of the game. 

The one who take the final count will be the winner and will be displayed on the LCD as the winner. The reset button can be pushed to reset the game. The count and total will be back to 0.

