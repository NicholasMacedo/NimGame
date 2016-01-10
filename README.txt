/*************************README.txt****************************
Student Name: Nicholas Macedo - Van Horne    Student Number:  0889469
Date: November 7th 2014                        Course Name: CIS1500
****************************************************************************/
           
                    ======Source Code File Name======
    The Source code for the game can be found in the Nim foulder.
    The name of the file is "nimGame.c". The source code can be opened
    using a text editor (Eg. Sublime).
    
                    ======Running the Program======
    The program can be run using the command "./nimGame" on the command line
    in the LXTerminal. The file was named after using the command
    "gcc nimGame.c -std=c99 -Wall -pedantic -o nimGame".
    
                    ======Known Program Limitations======
    There are three known program limitations. They are:
    1)Letters & Strings: The input of a letter when asked for a number causes the
                         program to enter an infinant loop thus breaking the program.
                         
    2)Punctuation & Symbols: Other symbols when entered instead of a number
                             cause the program to enter in an infinant loop.
                             The exception to this is the "-" and "+" for they
                             will be an incorrect value but the program will
                             not crash.
