/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
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

//e = empty space
int e = 0;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

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
    FILE* file = fopen("log.txt", "w");
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
        int tile = GetInt();

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
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
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
    usleep(1000000);
}

/**  INIT
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 * 0:49 - 2:32
 * 2D Arrays (where d = 3)
 * init grid [3][3]
 * grid [0][0] = 8;
 * grid [0][1] = 7;
 * grid [0][2] = 6;
 * grid [1][0] = 5;
 * grid [1][1] = 4;
 * grid [1][2] = 3;
 * grid [2][0] = 2;
 * grid [2][1] = 1;
 * grid [2][2] = ???
 * 
 * uses global variable board
 * choose 0 to represent blank space
 * initialize using loop structures for starting state of the board
 * board should contain starting state | board[i][j] represents row i and col j
 * starts in descending order
 * if number of tiles is odd, swap 2 and 1
 */
void init(void)
{
    // TODO
    
    int tiles = d * d - 1;
    
    if (tiles % 2 == 1)
    {
        //odd: switch 2 and 1
        for (int row = 0; row <= tiles; row++)
        {
            for (int col = 0; col < d; col++)
            {
                if (tiles == 2)
                {
                    board[row][col] = 1;
                    tiles--;
                }
                else if (tiles == 1)
                {
                    board[row][col] = 2;
                    tiles--;
                }
                else
                {
                    board[row][col] = tiles;
                    tiles--;              
                }
            }
        }
    }
    else 
    {
        //even: keep in order
        for (int row = 0; row <= tiles; row++)
        {
            for (int col = 0; col < d; col++)
            {
                board[row][col] = tiles;
                tiles--;
            }
        }
    }
}

/**  DRAW
 * Prints the board in its current state.
 * 2:32 - 3:49
 * Print a blank space before single-digit #s | printf("%2d",board[i][j]);
 * nested for loops
 * 
 * for each row
 *   for each value in row
 *   print value and space
 * print new line
 * 
 * order for echo function must mirror order of initialize function
 */
void draw(void)
{
    // TODO
    for (int row = 0; row < d; row++)
    {
        printf("\n");
        for (int col = 0; col < d; col++)
        {
            if (board[row][col] == 0)
            {
                printf("  _");
            }
            else
            {
            printf(" %2d",board[row][col]); 
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**  MOVE
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 * 3:50 - 5:00
 * passes in the number of the tile and not its position
 * only allow user to make a move if it's legal (only adjacent tiles)
 * don't search for the blank tile every time
 * remember where the blank tile is with well named variables
 */
bool move(int tile)
{
    // TODO

    /*
    find position of empty
        r = row of tile
        c = column of tile
    */ 
    int r;
    int c;
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            // printf("board[row][col]: %d | e: %d\n",board[row][col],e);
            if (e == board[row][col])
            {
                r = row;
                c = col;
            }
        }
    }
    // printf("e/r: %d | e/c: %d \n",r,c);
     
    /*
    list valid moves from position of tile
        iu = int at up position
        ir = int at right position
        id = int at down position
        il = int at left position
    */ 

    int iu = board[r-1][c];
    int ir = board[r][c+1];
    int id = board[r+1][c];
    int il = board[r][c-1];
    // printf(" iu: %d | ir: %d | id: %d | il: %d | e: %d",iu,ir,id,il,e);
    
    
    /*
    validate move request
    */

    if (tile == iu || tile == ir || tile == id || tile == il)
    {
        /*
        valid move
        */
        //swap e for tile in board
        if (tile == iu)
        {
            // printf("\nlets move up\n");
            board[r][c] = iu;
            board[r-1][c] = 0;
        }
        else if (tile == ir)
        {
            // printf("\nlets move right\n");
            board[r][c] = ir;
            board[r][c+1] = 0;
        }
        else if (tile == id)
        {
            // printf("\nlets move down\n");
            board[r][c] = id;
            board[r+1][c] = 0;
        }
        else if (tile == il)
        {
            // printf("\nlets move left\n");
            //shift tile to blank
            board[r][c] = il;
            
            // shift blank to tile
            board[r][c-1] = 0;
        }
        else
        {
            // printf("\ninvalid\n");
        }
        
        return true;
    }
    else
    {
        //invalid move
        return false;   
    }
}

/**  WON
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 * 5:00 - 6:05
 * game is won when tiles are in increasing order
 * check values by iterating over board with nested for loops
 */
bool won(void)
{
    // TODO
    int sequence[d*d];
    int counter = 0;
    // printf("\nboard[row][col]: ");
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col ++)
        {
            sequence[counter] = board[row][col];
            counter++;
            // printf("%d, ",board[row][col]);
        }
    }
    
    // x = previous integer in sequence
    int x = 0;
    // printf("\nsequence: ");
    for (int i = 0; i < (d*d); i++)
    {
        // printf("\n sequence[i]: %d, x: %d, i: %d ",sequence[i],x,i);
        if (x < sequence[i])
        {
            // printf("yes");
        }
        else
        {
            // printf("no");
            break;
        }
        // wins if all elements (minus blank) have been sequenced
        if (i == (d*d-2))
        {
            return true;    
        }
        
        // set previous number
        x = sequence[i];
    }
    printf("\n");
    return false;
}