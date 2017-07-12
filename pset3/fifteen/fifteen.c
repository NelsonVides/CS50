/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// black tile position
int Bi,Bj;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int* a, int* b);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(50000);
        }

        // sleep thread for animation's sake
        usleep(5000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}



/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}



/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(200000);
}



/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void) //
{   // TODO
    // initialize by brute
    int count = d*d - 1;
    for (int i = 0 ; i < d ; i++)
    {
        for (int j = 0 ; j < d ; j++)
        {
            board[i][j] = count;
            count = count - 1;
        }
    }
    // fix for unsolvable parities
    if ((d & 1) == 0)
    {
        swap( &board[d-1][d-2] , &board[d-1][d-3] );
    }
    Bi = d - 1;
    Bj = d - 1;
}



/**
 * Prints the board in its current state.
 */
void draw(void)
{   // TODO
    // print delimiter lines
    printf("| ");
    for (int k = 0; k < d; k++)
        {    printf("--\t");   }
    printf(" |\n");

    // print the actual table
    for (int i = 0; i < d; i++)
    {
        printf("| ");
        for (int j = 0; j < d; j++)
            {
                if (board[i][j] == 0)
                {
                    printf("_\t");
                }
                else
                {
                    printf("%2i\t", board[i][j]);
                }
            }
        printf(" |\n");
    }
    // print delimiter lines
    printf("| ");
    for (int k = 0; k < d; k++)
        {    printf("--\t");   }
    printf(" |\n");
}



/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{   // TODO
    // sanity check for unexistent tile
    if(tile > d*d || tile < 0)
        {return false;}
    // find the address of the given tile
    int Xi, Xj;
    for (int i = 0; i < d; i++)
    {   for (int j = 0; j < d; j++)
        {   if (board[i][j] == tile)
            {   Xi=i; Xj=j; 
                if(i - 1 > -1 && board[i - 1][j] == 0)
                {
                    swap( &board[Xi][Xj] , &board[Bi][Bj] );
                    Bi=Xi; Bj=Xj; return true;
                }
                else if(i + 1 < d && board[i + 1][j] == 0)
                {
                   swap( &board[Xi][Xj] , &board[Bi][Bj] );
                   Bi=Xi; Bj=Xj; return true;
                }
                else if(j - 1 > -1 && board[i][j - 1] == 0)
                {
                    swap( &board[Xi][Xj] , &board[Bi][Bj] );
                    Bi=Xi; Bj=Xj; return true;
                }
                else if(j + 1 < d && board[i][j + 1] == 0)
                {
                    swap( &board[Xi][Xj] , &board[Bi][Bj] );
                    Bi=Xi; Bj=Xj; return true;
                }
            }
        }
    }
    return false;
}



/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{   // TODO
    int check = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (check==d*d)
                {
                    check=0;
                }
            if (board[i][j] != check)
                {
                    return false;
                }
            check++;
        }
    }
    return true;
}


/**
 * Swaps two given values
 * call by swap(&a,&b)
 */
void swap(int* a, int* b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}