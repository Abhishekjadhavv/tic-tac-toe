#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Function Declaration Start From Here
void SmartComputer(char[]);
void withPlayer(char[]);
void displayMatrix(char[]);

int player1(char[]);
int player2(char[]);
int smartCom(char[], int[][3]);

int win(char[]);
void winMessage(int);
// Function Declaration End Here

// Function Definition Start from here

// Play with SmartComputer function here

void SmartComputer(char matrix[])
{
    int computerPlace[8][3] = {
         {0, 1, 2},{0, 4, 8},{0, 3, 6},{3, 4, 5},{2, 4, 6},{1, 4, 7},{2, 5, 8},{6, 7, 8}};

    int checktrue = 1;
    int winNumber;

    while (1)
    {

        printf("\n");
        displayMatrix(matrix);
        printf("\n\n#########################################\n");
        // win function call here
        winNumber = win(matrix);
        if (winNumber)
        {
            winMessage(winNumber);
        }

        if (checktrue)
        {
            checktrue = player1(matrix);
        }
        else
        {
            checktrue = smartCom(matrix, computerPlace);
        }
        system("cls");
    }
}

// play game with player function here
void withPlayer(char matrix[])
{
    int checktrue = 1;
    int winNumber;
    while (1)
    {
        printf("\n");
        displayMatrix(matrix);
        printf("\n\n#########################################\n");

        // win function call here
        winNumber = win(matrix);
        if (winNumber)
        {
            winMessage(winNumber);
        }

        if (checktrue)
        {
            checktrue = player1(matrix);
        }
        else
        {
            checktrue = player2(matrix);
        }

        system("cls");
    }
}

// ===== player1 function here ==
int player1(char matrix[])
{
    int position, checktrue;

    printf("\nPlayer 0, Enter Marking Place :\n");
    scanf("%d", &position);

    if (matrix[position - 1] == '0')
    {
        matrix[position - 1] = '0';
        return checktrue = 1;
    }
    else if (matrix[position - 1] == 'X')
    {
        matrix[position - 1] = 'X';
        return checktrue = 1;
    }
    else
    {
        matrix[position - 1] = '0';
        return checktrue = 0;
    }
}

// ===== player2 function here ==
int player2(char matrix[])
{
    int position, checktrue;
    printf("\nPlayer X, Enter Marking Place :\n");
    scanf("%d", &position);
    if (matrix[position - 1] == '0')
    {
        matrix[position - 1] = '0';
        return checktrue = 0;
    }
    else if (matrix[position - 1] == 'X')
    {
        matrix[position - 1] = 'X';
        return checktrue = 0;
    }
    else
    {
        matrix[position - 1] = 'X';
        return checktrue = 1;
    }
}

// smartCom function here

int smartCom(char matrix[], int computerPlace[8][3])
{
    int i, j;

    for (i = 0; i <= 7; i++)
    {

        if (matrix[computerPlace[i][0]] == '0' && matrix[computerPlace[i][1]] == '0')
        {

            if (matrix[computerPlace[i][2]] != 'X')
            {
                matrix[computerPlace[i][2]] = 'X';
                break;
            }
        }
        else if (matrix[computerPlace[i][0]] == '0' && matrix[computerPlace[i][2]] == '0')
        {
            if (matrix[computerPlace[i][1]] != 'X')
            {
                matrix[computerPlace[i][1]] = 'X';
                break;
            }
        }
        else if (matrix[computerPlace[i][1]] == '0' && matrix[computerPlace[i][2]] == '0')
        {
            if (matrix[computerPlace[i][0]] != 'X')
            {
                matrix[computerPlace[i][0]] = 'X';
                break;
            }
    
        }else if(matrix[computerPlace[i][0]] == '0'){
           if( matrix[computerPlace[i][1]] != 'X'){
             matrix[computerPlace[i][1]] = 'X';
             break;
           }
        }else if(matrix[computerPlace[i][1]] == '0'){
             if( matrix[computerPlace[i][0]] != 'X'){
             matrix[computerPlace[i][0]] = 'X';
             break;
           }
        }
        else if(matrix[computerPlace[i][2]] == '0'){
             if( matrix[computerPlace[i][0]] != 'X'){
             matrix[computerPlace[i][0]] = 'X';
             break;
           }
        }
    }

    return 1;
}

// win function here
int win(char matrix[])
{

    int winSituation[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    // === Win ===
    for (int i = 0; i <= 7; i++)
    {
        if (matrix[winSituation[i][0]] == '0' && matrix[winSituation[i][1]] == '0' && matrix[winSituation[i][2]] == '0')
        {
            return 1;
        }
        else if (matrix[winSituation[i][0]] == 'X' && matrix[winSituation[i][1]] == 'X' && matrix[winSituation[i][2]] == 'X')
        {
            return 2;
        }
    }

    // === Draw ===
    int check = 0;
    for (int i = 0; i <= 8; i++)
    {
        if (matrix[i] == '0' || matrix[i] == 'X')
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }

    if (check == 1)
        return 3;

    return 0;
}

// ==== void winMessage function ==

void winMessage(int winNumber)
{

    if (winNumber == 1)
    {
        printf("\nPlayer 0 Win The Game");
        printf("\nPress any key to exit");
        printf("\n\n#########################################\n");
        getch();
        exit(0);
    }
    else if (winNumber == 2)
    {
        printf("\nPlayer X Win The Game");
        printf("\nPress any key to exit");
        printf("\n\n#########################################\n");
        getch();
        exit(0);
    }
    else if (winNumber == 3)
    {
        printf("\nGame Drawn");
        printf("\nPress any key to exit");
        printf("\n\n#########################################\n");
        getch();
        exit(0);
    }
}

// displayMatrix function here
void displayMatrix(char matrix[])
{
    for (int i = 0; i <= 8; i++)
    {

        printf("   %-3c", matrix[i]);

        if (i == 2 || i == 5 || i == 8)
            printf("");
        else
            printf("|");

        if (i == 2 || i == 5)
        {
            printf("\n");
            printf("--------------------");
            printf("\n");
        }
    }
    printf("\n--------------------");
}

// Function Definition End here

// Main Function here
int main()
{
    char matrix[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int choice;

    while (1)
    {
        printf("Enter your choice:\n");
        printf("1. Want to play with Smart Computer\n");
        printf("2. Want to play with Player\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        printf("\n############## Tic Tac Toe ##############\n\n");
        printf("First  Player 0\n");
        printf("Second Player X\n\n");

        switch (choice)
        {
        case 1:
            SmartComputer(matrix);
            break;
        case 2:
            withPlayer(matrix);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid Choice Please Select Right Choice\n");
            printf("\n#########################################\n");
        }
        getch();
        system("cls");
    }
    return 0;
}