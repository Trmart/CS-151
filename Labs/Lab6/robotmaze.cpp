

// robotmaze.cpp
// Description: Using recursion to navigate a maze represented by
//   two-dimensional array of characters.
// Name(s): Taylor Martin, Dan Blanchette, Aaron Agostinelli
// Date: 2/20/20
//Use the code below as the starter code.
#include <iostream>
#include <windows.h>
using namespace std;

const int MAZE_ROW_SIZE = 6;
const int MAZE_COL_SIZE = 6;

void displayMaze(char maze[][MAZE_COL_SIZE], int rowSize, int colSize);
bool findPath(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int row, int col);

int main()
{   
    char maze1[][MAZE_COL_SIZE] = {{'S', '#', '#', '#', '#', '#'},
                                   {'.', '.', '.', '.', '.', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'.', '.', '.', '#', '.', 'G'},
                                   {'#', '#', '.', '.', '.', '#'}};
    
    char maze2[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '.', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

    char maze3[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '#', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

     char maze4[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '.', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

    // STEP 1: Implement the recursive function findPath

    // STEP 2: Uncomment next line of code and compile/execute.
    // It should correctly find a path from start position to
    // goal position. If not, then your code has a logic error.
    //findPath(maze1, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0);

    // STEP 3: Uncomment next line of code and test with maze2. 
    //findPath(maze2, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0);

    // STEP 4: Uncomment next line of code and test with maze3.
    //findPath(maze3, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0);

    // STEP 5: Create a 4th maze and test your function and
    // see if it still works correctly.
    findPath(maze4, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0);
    return 0;
}

bool findPath(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int row, int col)
{
    
    // STEP 1A: There are three base cases. One of the base case also needs
    // needs to consider the wrong solution path. Only one of three
    // base cases returns true, otherwise it returns false.
    if (row >= rowSize || col >= colSize || row < 0 || col < 0)  // Base 3
    {
        return false; 
    }
    
    if (maze[row][col]=='#' || maze[row][col]=='+')// Base 1
    {
        return false; 
    }
    if (maze[row][col]=='G')// Base 2
    {
        return true; 
    }

    maze[row][col] = '+';// STEP 1B: Mark (row, col) as part of solution path

    displayMaze(maze, rowSize, colSize);
    // STEP 1C: There are four recursive calls here for every direction,
    // West, East, North, South. For each of the recursive call,
    // if the return is true, then it must return true.
    
    if(findPath(maze, MAZE_COL_SIZE, MAZE_ROW_SIZE, row, col-1)) // West
    {
        return true; 
    }
    
    if(findPath(maze, MAZE_COL_SIZE, MAZE_ROW_SIZE, row, col+1)) // East
    {
        return true; 
    }
    
    if(findPath(maze, MAZE_COL_SIZE, MAZE_ROW_SIZE, row-1, col)) // North
    {
        return true; 
    }
    
    if(findPath(maze, MAZE_COL_SIZE, MAZE_ROW_SIZE, row+1, col)) // South
    {
        return true; 
    }
    

    maze[row][col] = '.';// STEP 1D: Unmark (row, col) as as not part of solution

    displayMaze(maze, rowSize, colSize);
    return false;
}

void displayMaze(char maze[][MAZE_COL_SIZE], int rowSize, int colSize)
{
    system("cls");
    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            cout << maze[row][col];
        }
        cout << '\n';
    }
    Sleep(500);
}
