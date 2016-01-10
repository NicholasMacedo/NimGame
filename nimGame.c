/*
	This program was written by Nicholas Macedo - Van Horne for 	SoCS UoG Software Engineering Program in first year 	university.
*/
#include <stdio.h>
//Function Prototypes
void drawNim(int rowOne, int rowTwo, int rowThree);
int playNim (int rowOne, int rowTwo, int rowThree);

int main (void)
{
    //Variable Declaration
    int rowOne;
    int rowTwo;
    int rowThree;
    int winner;

    //Variable Initialization
    rowOne = 0;
    rowTwo = 0;
    rowThree = 0;
    winner = 0;

    //Welcome and how many rocks in each row. Wrong input (not between 1 and 20) causes default (10) value.
    printf("Welcome! This program is designed to play the game Nim.\n");
    printf("The Rules to the game are as follows:\n(1)Each player must choose a row and determine how many rocks they would like to remove from set row.\n");
    printf("(2)You are unable to add rocks to the rows using negative numbers.\n(3)The player that removes the last rock wins.\n");
    printf("Please enter how many rocks you would like in row one between 1 and 20.\n");
    scanf("%d", &rowOne);
    if ((rowOne < 0) || (rowOne > 20))
    {
        printf("**Invalid Choice:%d**The default value (10) has been set due to  incorrect input.\n",rowOne);
        rowOne = 10;
    }
    printf("Please enter how many rocks would you like in row two between 1 and 20.\n");
    scanf("%d", &rowTwo);
    if ((rowTwo < 0) || (rowTwo > 20))
    {
        printf("**Invalid Choice:%d**The default value (10) has been set due to  incorrect input.\n",rowTwo);
        rowTwo = 10;
    }
    printf("Please enter how many rocks you would like in row three between 1 and 20.\n");
    scanf("%d", &rowThree);
    if ((rowThree < 0) || (rowThree > 20))
    {
        printf("**Invalid Choice: %d**The default value (10) has been set due to  incorrect input.\n",rowThree);
        rowThree = 10;
    }

    //Printing of the Initial game board.
    printf("\nThe Initial Nim Board.");
    drawNim(rowOne,rowTwo,rowThree);
    printf("\n");

    //Call on the playNim function to play game and determine winner.
    winner = playNim(rowOne,rowTwo,rowThree);
    if(winner == 1)
    {
        printf("Congrats! Player 1 has won!\n");
    }
    else
    {
        printf("Congrats! Player 2 has won!\n");
    }

    return(0);
}
//Function Definitions
/******
 drawNim: Draws the game board.
 In: Int values for rowOne, rowTwo and rowThree
 Out:VOID
 What it does: Takes the row value and loops it to draw the "O"'s needed to creat the visual game board.
******/
void drawNim(int rowOne, int rowTwo, int rowThree)
{
    //Variable Declaration for drawNim
    int i;
    //Variable Initialization for drawNim
    i = 0;
    //Row 1 Draw Loop
    printf("\nRow 1:");
    for(i = 1; i <= rowOne; i = i + 1)
    {
        printf("O");
    }
    printf("\n");
    //Row 2 Draw Loop
    printf("Row 2:");
    for(i = 1; i <= rowTwo; i = i + 1)
    {
        printf("O");
    }
    printf("\n");
    //Row 3 Draw Loop
    printf("Row 3:");
    for(i = 1; i <= rowThree; i = i + 1)
    {
        printf("O");
    }
    printf("\n");
    return;
}
/******
playNim: Where the game logic is housed.
In:Int values for rowOne, rowTwo and rowThree
Out:Int value of either 1 or 2.
What it does: Selects row and removes desired number of rocks. Loops until game is won by removal of last rock. Returns value declairing winner.
******/
int playNim (int rowOne, int rowTwo,int rowThree)
{
    //Variable Declaration
    int pOneRow;
    int pOneRemove;
    int pTwoRow;
    int pTwoRemove;
    //Variable Initialization
    pOneRow = 0;
    pOneRemove = 0;
    pTwoRow = 0;
    pTwoRemove = 0;

    //Game loop while there are stones in each row.
    while ((rowOne > 0) || (rowTwo > 0) || (rowThree > 0))
    {
        //Start of player one's turn
        printf("**********Player 1's Turn**********\n");
        printf("Player 1: Please pick a row in which you would like to remove the rocks from.\n");
        scanf("%d", &pOneRow);
        if ((rowOne == 0) || (rowTwo == 0) || (rowThree == 0))
        {
            while (((rowOne == 0) && (pOneRow == 1)) || ((rowTwo == 0) && (pOneRow == 2)) || ((rowThree == 0) && (pOneRow == 3)))
            {
                printf("This row (%d) is empty. Please choose another row.\n",pOneRow);
                scanf("%d", &pOneRow);
                while ((pOneRow < 1) || (pOneRow > 3))
                {
                    printf("Player 1:**Invalid Choice: %d** Please pick a row in which you would like to remove the rocks from.\n",pOneRow);
                    scanf("%d", &pOneRow);
                }
            }
        }
        while ((pOneRow < 1) || (pOneRow > 3))
        {
            printf("Player 1:**Invalid Choice: %d** Please pick a row in which you would like to remove the rocks from.\n",pOneRow);
            scanf("%d", &pOneRow);
        }
        //Player One's Row choice has been determined. Number of rocks from this row w/ error checking and calculation to achieve new row total.
        switch (pOneRow)
        {
            case 1:
                printf("Player 1:How many rocks would you like to remove from row one?\n");
                scanf("%d", &pOneRemove);
                while ((pOneRemove < 1) || (pOneRemove > rowOne))
                {
                    printf("Player 1:**Invalid Choice: %d**How many rocks would you like to remove from row one?\n",pOneRemove);
                    scanf("%d", &pOneRemove);
                }
                rowOne = rowOne - pOneRemove;
                break;
            case 2:
                printf("Player 1:How many rocks would you like to remove from row two?\n");
                scanf("%d", &pOneRemove);
                while ((pOneRemove < 1) || (pOneRemove > rowTwo))
                {
                    printf("Player 1:**Invalid Choice: %d**How many rocks would you like to remove from row Two?\n",pOneRemove);
                    scanf("%d", &pOneRemove);
                }
                rowTwo = rowTwo - pOneRemove;
                 break;
            case 3:
                printf("Player 1:How many rocks would you like to remove from row three?\n");
                scanf("%d", &pOneRemove);
                while ((pOneRemove < 1) || (pOneRemove > rowThree))
                {
                    printf("Player 1:**Invalid Choice: %d**How many rocks would you like to remove from row Three?\n",pOneRemove);
                    scanf("%d", &pOneRemove);
                }
                rowThree = rowThree - pOneRemove;
                break;
        }
        //Drawing of the board after player one's turn
        drawNim(rowOne,rowTwo,rowThree);

        //Determining if player one has won before proceding to player two's turn.
        if((rowOne == 0) && (rowTwo == 0) && (rowThree == 0))
        {
            return(1);
        }
        //Start of Player One's turn w/ row choice.
        printf("**********Player 2's Turn**********\n");
        printf("Player 2: Please pick the row in which you would like to remove the rocks from.\n");
        scanf("%d", &pTwoRow);
        if ((rowOne == 0) || (rowTwo == 0) || (rowThree == 0))
        {
            while (((rowOne == 0) && (pTwoRow == 1)) || ((rowTwo == 0) && (pTwoRow == 2)) || ((rowThree == 0) && (pTwoRow == 3)))
            {
                printf("Player 2:This row (%d) is empty. Please choose another row.\n",pTwoRow);
                scanf("%d", &pTwoRow);
                while ((pTwoRow < 1) || (pTwoRow > 3))
                {
                    printf("Player 2:**Invalid Choice: %d** Please pick a row in which you would like to remove the rocks from.\n",pTwoRow);
                    scanf("%d", &pTwoRow);
                }
            }
        }
        while ((pTwoRow < 1) || (pTwoRow > 3))
        {
            printf("Player 1:**Invalid Choice: %d** Please pick a row in which you would like to remove the rocks from.\n",pOneRow);
            scanf("%d", &pTwoRow);
        }
        //Row chosen and number of rocks is to be selected. Math to determine amount of rocks in each row is done  below.
        switch (pTwoRow)
        {
            case 1:
                printf("Player 2:How many rocks would you like to remove from row one?\n");
                scanf("%d", &pTwoRemove);
                while ((pTwoRemove < 1) || (pTwoRemove > rowOne))
                {
                    printf("Player 2:**Invalid Choice: %d**How many rocks would you like to remove from row one?\n",pTwoRemove);
                    scanf("%d", &pTwoRemove);
                }
                rowOne = rowOne - pTwoRemove;
                break;
            case 2:
                printf("Player 2:How many rocks would you like to remove from row two?\n");
                scanf("%d", &pTwoRemove);
                while ((pTwoRemove < 1) || (pTwoRemove > rowTwo))
                {
                    printf("Player 2:**Invalid Choice: %d**How many rocks would you like to remove from row two?\n",pTwoRemove);
                    scanf("%d", &pTwoRemove);
                }
                rowTwo = rowTwo - pTwoRemove;
                break;
            case 3:
                printf("Player 2:How many rocks would you like to remove from row three?\n");
                scanf("%d", &pTwoRemove);
                while ((pTwoRemove < 1) || (pTwoRemove > rowThree))
                {
                    printf("Player 2:**Invalid Choice: %d**How many rocks would you like to remove from row three?\n",pTwoRemove);
                    scanf("%d", &pTwoRemove);
                }
                rowThree = rowThree - pTwoRemove;
                break;
        }
    //Drawing of the board after player two's turn.
    drawNim(rowOne,rowTwo,rowThree);
    }
    return(2);
}