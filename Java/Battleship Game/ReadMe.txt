// Jack Carson
// CPSC 1060
// 22 March 2021
// Project 1

    To whom it may concern,

        Included in this zip file are two programs named Tricks.java, and Battleship.java respectively.
    These program were created over a week long development cycle, and despite being very good work in my
    opinion, they are nowhere near perfect. Beginning with the Tricks.java program, this program is designed
    to loop through three possible tasks, with a fourth option being given to exit the program. these tasks are
    modularized into four distinct methods. In order for these methods to be called continuously, a while loop with
    a counter variable is used, with the variable only being changed in the loop if the integer 0 is inputted. The first
    method involves a scanner with a calculation performed on the scanner input. The second method uses a switch statement
    that acts on another scanner input to print a corresponding response to the five accepted scanner inputs. The third
    method creates a random lowercase letter utilizing unicode and typecasting, and prompts the user to guess
    this letter. While the user's scanner input is != to the random letter, the program prints hints, and takes a
    count of how many guesses have accumulated. After the letter is guessed, the program prints the amount of guesses
    taken, and returns to the initial while loop. I quite enjoyed this program, and felt it was a refreshing review of
    many concepts covered so far. However, I do believe there is room for improvement in the method used to enter into
    the first while loop (Just an int variable), and I also believe an improvement could be made to the switch statement
    in the second method, as any value not included in the switch statement will send the user back to the initial while
    loop. Overall, I feel this program is solid and fulfills its purpose wonderfully.

        The second program included in this zip file is Battleship.java, and proved to be a very challenging, entertaining,
    and very addictive program to work on for me. This program includes many methods, and many of which are not included
    in the final program that hours were spent on (Checking if battleships were sunk) (Many variations of methods ending
    the game) (Manipulating the 2D arrays). While many aspects of this program proved to be challenging, some of the larger
    problems included the formatting of both grids (Solved through rigorous for loop experimentation), the issue of
    hiding the computer's battleships (Solved by creating 2 grids, and reading contents of one while editing the other),
    and determining if the game was ended (Solved by creating a global counting variable and counting down after each hit on
    an opposing battleship (Every game has 18 possible ship locations)). Overall, I feel that the use of methods, recursion,
    and global variables and 2D arrays made this program much easier and streamlined than it could have been. Additionally,
    I feel that this program could have been even easier had I had more knowledge of object oriented programming in terms of
    battleships as objects on the 2D array. While I am satisfied with the overall program, I feel that there are some
    distinct changes made in my iteration, and some further possible improvements. For starters, the player's grid is
    printed with the battleships always showing, while the method displayShips determines if the computer's battleships
    are displayed or hidden. This change was made to reflect the actual game, where your ships are always visible to you,
    with the option to include the computer's ships for debugging purposes. Some possible changes and improvements that I
    wish could be implemented into the program include the ability to place your ships (Objects would have been super
    useful with this method), The ability of the computer to randomly place ships (Tried to implement this using vector
    addition, backfired horribly with bugs and had to be removed), and lastly the ability of the computer to learn to play
    the game of battleship (Machine learning and reinforcement learning are beyond the scope of this class, but they are
    very interesting to me and I could help but wish I could implement this procedure instead of using random values for
    each computer attack, for example I tried to create a method in which if the computer got a hit it would then start
    attacking the rows/columns +/- 1 from where the initial hit was as a human would do, however this proved to be very
    buggy with lots of out of bounds array errors.). While I am not certain of any bugs contained in these programs, I am
    sure they exist, especially within the battleship program. Despite this, I am very happy with this project, and super
    satisfied with the programs that I created :).



