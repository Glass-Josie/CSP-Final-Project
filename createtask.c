#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//1) tile structs
typedef struct
{
    int face;
    char back;
    bool matched;
}
tile;

//2)creating array from structs
tile tiles[16];

//3) function prototypes
void init(void);
int print(void);
int index_1(char tile1);
int index_2(char tile2);
bool matched(int index1, int index2);
bool won(void);


//main code
int main(void)
{
    //4) welcomes player and explains the game
    printf("Welcome to Tile Match Memory game!\nEach tile is represented by a letter, pick two letters to flip two tiles.\nIf they're a match they will stay flipped and if not, they'll turnover so remember what numbers you were shown!\nKeep guessing tiles until you've matched all tiles and won the game. Lets play!\n");
    init();

    //5) loops the rounds of the game until its won
    while (!won())
    {
        print();
        //getting guess one and answer
        char tile1 = get_char("Which first tile would you like to reveal?\n");
        int index1 = index_1(tile1);
        //getting guess two and answer
        char tile2 = get_char("Which second tile would you like to reveal?\n");
        int index2 = index_2(tile2);
        matched(index1, index2);
    }
    printf("Congrats! You matched them all and won the game!\n");
    return 0;
}




//functions

//6) Initializes the game's board with "dimensions" number of pairs
void init(void)
{
    //array banks
    char alpha[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
    int num[16] = {2,4,1,6,3,3,4,5,1,5,2,6,7,8,7,8};

    //initializing card matched?
    for (int i = 0; i < 16; i++)
    {
        tiles[i].matched = false;
    }
    //intitializing card backs (letters)
    for (int i = 0; i < 16; i++)
    {
        tiles[i].back = alpha[i];
    }
    //initializing card faces (numbers)
    for (int i = 0; i < 16; i++)
    {
        tiles[i].face = num[i];
    }
    return;
}


//7) prints the tile board
int print(void)
{
    int r = 0;
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            //flip the tile over
            if (tiles[r].matched == true)
            {
                 printf("%i ", tiles[r].face);
            }
            //don't flip the tile over
            else
            {
                 printf("%c ", tiles[r].back);
            }
            r = r + 1;
        }
        printf("\n");
    }

    return 0;
}

//8) finds the index of their first tile guess
int index_1(char tile1)
{
    int index1;
    //looping through tiles array
    for (int i = 0; i < 16; i++)
    {
        if (tiles[i].back == tile1)
        {
            index1 = i;
        }
    }
    printf("= %i\n", tiles[index1].face);
    return index1;
}

//9) finds the index of their second tile guess
int index_2(char tile2)
{
    int index2;
    //looping through tiles array
    for (int i = 0; i < 16; i++)
    {
        if (tiles[i].back == tile2)
        {
            index2 = i;
        }
    }
    printf("= %i\n", tiles[index2].face);
    return index2;
}

//10) checks if their guesses are a match and updates tiles array accordingly
bool matched(int index1, int index2)
{
    do
    {
        //are the faces of the tiles they guessed the same?
        if (tiles[index1].face == tiles[index2].face)
        {
            printf("You got a match!\n");
            tiles[index1].matched = true;
            tiles[index2].matched = true;
            return true;
        }
        else
        {
            printf("Not a match :(\n");
            return false;
        }
    }
    while (index1 == index2);
}



//11) Checks if are all the tiles matched and game is won
bool won(void)
{
    for (int i = 0; i < 16; i++)
    {
        if (tiles[i].matched == false)
        {
            return false;
        }
    }
    return true;
}

for (int i = 0; i < 16; i++)
{
    for (int i = 0; i < 16; i++)
    {
        print("I'm a CS god");
        return true;

        
    }
}