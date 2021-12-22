#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "my_headers.h"

/*int isExist(int number,int size)
{
    for(int i=0;i<size;i++)
    {
        if(number==i){return 1;}
    }
    return 0;
}
*/
void setToZero(int size, int arr[size][size])
{

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            arr[i][j]=0;
        }
    }
}


int checkScore(int score, int row, int col ,int size, int array[size][size],int *turn)
{
    int change=0;
    if(row%2==0 && col%2==1)
    {
        if(row==0)
        {
            if(array[row+2][col]==1&&array[row+1][col-1]==1&&array[row+1][col+1]==1)
            {
                score++;
                change=1;
            }
        }
        else
        {
            if(row==size-1)
            {
                if(array[row-2][col]==1&&array[row-1][col-1]==1&&array[row-1][col+1]==1)
                {
                    score++;
                    change=1;
                }
            }
            else
            {
                if(array[row-2][col]==1&&array[row-1][col-1]==1&&array[row-1][col+1]==1)
                {
                    score++;
                    change=1;
                }
                if(array[row+2][col]==1&&array[row+1][col-1]==1&&array[row+1][col+1]==1)
                {
                    score++;
                    change=1;
                }
            }
        }

    }
    if(row%2==1 && col%2==0)
    {
        if(col==0)
        {
            if(array[row][col+2]==1&&array[row-1][col+1]==1&&array[row+1][col+1]==1)
            {
                score++;
                change=1;
            }
        }
        else
        {
            if(col==size-1)
            {
                if(array[row][col-2]==1&&array[row-1][col-1]==1&&array[row+1][col-1]==1)
                {
                    score++;
                    change=1;
                }
            }
            else
            {
                if(array[row][col-2]==1&&array[row-1][col-1]==1&&array[row+1][col-1]==1)
                {
                    score++;
                    change=1;
                }
                if(array[row][col+2]==1&&array[row-1][col+1]==1&&array[row+1][col+1]==1)
                {
                    score++;
                    change=1;
                }
            }
               
        }

    }
    if(change==1){*turn=!*turn;}
    return score;
}


void startNewGame()
{
    //for new game
    int numOfPlayers;
    char playerOne[10],playerTwo[10],str[10];
    int diff,size;
    system("cls");
    printf("For begginer press 1\nFor expert press 2\n");
    label:
    fflush(stdin);
    scanf("%d",&diff);
    if(diff!=1 && diff!=2)
    {
        printf("Please enter a valid number: ");
        goto label;
    }

    //choose number of players
    system("cls");
    printf("One player:(Press 1)\nTwo players:(press 2)\n\n\n");
    label2:
    fflush(stdin);
    scanf("%d",&numOfPlayers);

    if(numOfPlayers==1)
    {
        printf("Please enter your name\n\n");
        scanf("%s",playerOne);
        //gets(playerOne);
        strcpy(str, "Computer");
        strcpy(playerTwo, str);
        system("cls");
    }
    else if(numOfPlayers==2)
    {
        printf("Please enter the name of the first player:\n");
        scanf("%s",playerOne);
        /*int i=0;
        while(playerOne[i]!='\n')
            {gets(playerOne);i++;}*/
        printf("Please enter the name of the second player:\n");
        scanf("%s",playerTwo);

        system("cls");
    }
    else
    {
        printf("Please enter a valid number: ");
        goto label2;
    }

    system("cls");
    //displaying the names of the players
    printf("Player 1: %s\t\t\t\t\t", playerOne);printf("Player 2: %s", playerTwo);

    //dispaying the board
    if(diff==1)
    {
        size=5;
    }
    else{size=11;}

    int noMoves;
    if(size==5){noMoves=12;}
    else{noMoves=60;}

    //passive game board

    char passive[size][size],h=205,v=186;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i%2==0 && j%2!=0)
            {
                passive[i][j]=h;
            }
            if(i%2!=0 && j%2==0)
            {
                passive[i][j]=v;
            }
        }
    }
    if(numOfPlayers==2){twoPlayers(noMoves,size, passive, playerOne, playerTwo);}
    if(numOfPlayers==0){onePlayer(noMoves,size, passive, playerOne, playerTwo);}
}

//two players

void twoPlayers(int noMoves,int size, char passive[size][size],char playerOne[10], char playerTwo[10])
{
    system("color 07");
    int array[size][size], array1[size][size], array2[size][size], score1=0, score2=0;
    setToZero(size,array);
    setToZero(size,array1);
    setToZero(size,array2);
    char active[size][size];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i%2==0&&j%2==0)
            {
                active[i][j]=254;
            }
            else
            {
                if(i%2==1 && j%2==0){active[i][j]='\0';}
                else{active[i][j]='\t';}
            }

        }
    }
    int  row, col;
    int turn=0;
    while(noMoves>=0)
    {
        system("cls");
        printf("\e[0;34mPlayer 1 : %s \t\t\t\t\t\t\t\t\t\t\e[0;31mPlayer 2: %s", playerOne, playerTwo );
        printf("\n");
        printf("\e[0;34mPlayer 1 score : %d \t\t\t\t\t\t\t\t\t\e[0;31mPlayer 2 score : %d",score1,score2);
        printf("\n");
        printf("\t\t\t\t\t\t\e[0;32mMoves left: %d",noMoves);
        printf("\n\n");
        for(int i=0;i<size;i++){printf("\e[0;32m%d   ",i);}
        printf("\n");
        for(int i=0;i<size;i++)
        {

            printf("\t\t\t\t\e[0;32m%d",i);
            printf("\t");
            for (int j=0;j<size;j++)
            {
                if(array1[i][j]==1)
                {
                    if(i%2==0 && j%2==1)
                    {
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                    }
                    else
                    {

                        printf("\e[0;34m%c" ,active[i][j]);

                    }
                }
                else
                {
                    if(array2[i][j]==1)
                    {
                        if(i%2==0 && j%2==1)
                        {
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                        }
                        else
                        {
                            printf("\e[0;31m%c" ,active[i][j]);
                        }
                    }
                    else
                    {
                        printf("\e[0;32m%c" ,active[i][j]);
                    }
                }

            }
            printf("\n");
        }

        reread:
        fflush(stdin);
        if(noMoves>0)
        {
            if(turn==0)
            {
                printf("\e[0;34mPlayer one turn\n");
                printf("\e[0;34mEnter number of row: \n");
                scanf("%d",&row);
                printf("\e[0;34mEnter number of column: \n");
                scanf("%d",&col);
                if( (row>size || col>size) || (row<0 || col<0) || (row%2==0 && col%2==0) ||(row%2==1 && col%2==1) || array[row][col]==1 )
                {
                    printf("Please enter valid numbers\n");
                    goto reread;
                }
                score1=checkScore(score1,row,col,size,array,&turn);
                array1[row][col]=1;
                array[row][col]=1;
                active[row][col]=passive[row][col];
                noMoves--;
                turn=!turn;
            }
            else
            {
                printf("\e[0;31mPlayer two turn\n");
                printf("\e[0;31mEnter number of row: ");
                scanf("%d",&row);
                printf("\e[0;31mEnter number of column: ");
                scanf("%d",&col);
                if( (row>size || col>size) || (row<0 || col<0) || (row%2==0 && col%2==0) ||(row%2==1 && col%2==1) || array[row][col]==1 )
                {
                    printf("Please enter valid numbers\n");
                    goto reread;
                }
                score2=checkScore(score2,row,col,size,array,&turn);
                array2[row][col]=1;
                array[row][col]=1;
                active[row][col]=passive[row][col];
                noMoves--;
                turn=!turn;
            }
        }
        else{break;}
    }
    if(score1>score2)
    {
        printf("END GAME \e[0;34m%S WON!",playerOne);
    }
    else
    {
        printf("END GAME \e[0;31m%S WON!",playerTwo);
    }
}

void onePlayer(int noMoves,int size, char passive[size][size],char playerOne[10], char playerTwo[10])
{
    system("color 07");
    int array[size][size], array1[size][size], array2[size][size], score1=0, score2=0;
    setToZero(size,array);
    setToZero(size,array1);
    setToZero(size,array2);
    char active[size][size];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i%2==0&&j%2==0)
            {
                active[i][j]=254;
            }
            else
            {
                if(i%2==1 && j%2==0){active[i][j]='\0';}
                else{active[i][j]='\t';}
            }

        }
    }
    int  row, col;
    int turn=0;
    while(noMoves>=0)
    {
        system("cls");
        printf("\e[0;34mPlayer 1 : %s \t\t\t\t\t\t\t\t\t\t\e[0;31mPlayer 2: %s", playerOne, playerTwo );
        printf("\n");
        printf("\e[0;34mPlayer 1 score : %d \t\t\t\t\t\t\t\t\t\e[0;31mPlayer 2 score : %d",score1,score2);
        printf("\n");
        printf("\t\t\t\t\t\t\e[0;32mMoves left: %d",noMoves);
        printf("\n\n");
        printf("\t\t\t\t\t\e[0;32m0   1   2   3   4   5   6   7   8   9   10");
        printf("\n");
        for(int i=0;i<size;i++)
        {

            printf("\t\t\t\t\e[0;32m%d",i);
            printf("\t");
            for (int j=0;j<size;j++)
            {
                if(array1[i][j]==1)
                {
                    if(i%2==0 && j%2==1)
                    {
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                        printf("\e[0;34m%c" ,active[i][j]);
                    }
                    else
                    {

                        printf("\e[0;34m%c" ,active[i][j]);

                    }
                }
                else
                {
                    if(array2[i][j]==1)
                    {
                        if(i%2==0 && j%2==1)
                        {
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                            printf("\e[0;31m%c" ,active[i][j]);
                        }
                        else
                        {
                            printf("\e[0;31m%c" ,active[i][j]);
                        }
                    }
                    else
                    {
                        printf("\e[0;32m%c" ,active[i][j]);
                    }
                }

            }
            printf("\n");
        }

        reread:
        fflush(stdin);
        if(turn==0)
        {   //player one turn
            printf("\e[0;34mPlayer one turn\n");
            printf("\e[0;34mEnter number of row: \n");
            scanf("%d",&row);
            printf("\e[0;34mEnter number of column: \n");
            scanf("%d",&col);
            if( (row>size || col>size) || (row<0 || col<0) || (row%2==0 && col%2==0) ||(row%2==1 && col%2==1) || array[row][col]==1 )
            {
                printf("Please enter valid numbers\n");
                goto reread;
            }
            score1=checkScore(score1,row,col,size,array,&turn);
            array1[row][col]=1;
            array[row][col]=1;
            active[row][col]=passive[row][col];
            noMoves--;
            turn=!turn;
        }
        else
        {   //computers turn

            AI(size, array, &row, &col);


            score2=checkScore(score2,row,col,size,array,&turn);
            array2[row][col]=1;
            array[row][col]=1;
            active[row][col]=passive[row][col];
            noMoves--;
            turn=!turn;}}}







