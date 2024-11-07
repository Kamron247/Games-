// External libraries
#include <iostream> 
#include <vector>
#include <string>

#define  BOARD_SIZE  9 //size of the board

using namespace std;

/*
References: 
1. https://www.geeksforgeeks.org/sudoku-in-cpp/
2. https://www.geeksforgeeks.org/c-plus-plus/
3. https://www.w3schools.com/cpp/
4. https://onecompiler.com/cpp/42xez9u4h
*/

class Sodoku{
    // Variables
    static <vector<int>> board(BOARD_SIZE, vector<int> (BOARD_SIZE, 0));

    // Create a random board
    void RandomizeBoard()
    {
        for (int row_idx : board)
        {
            for (int col_idx : board.at(row_idx))
            {
                int rand_num = rand() % 10 + 1;
                board.at(row_idx).at(col_idx) = rand_num;
            }
        }
    }

    // Check if board is valid: solved via bitmap
    bool BoardIsValid(){
        // Checks for a valid board:
        // 1. board is a 9x9 matrix
        // 2. board is filled with numbers from 1 to 9
        // 3. no number occurs more than once in a row
        // 4. no number occurs more than once in a column
        // 5. no number occurs more than once in a 3x3 box


    }

    // Check if its safe to place a number in a cell
    bool MoveIsSafe(int row, int col, int num)
    {
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            if (   board[row][x] == num 
                || board[x][col] == num 
                || board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num)
            {
                return false;
            }
        }
        return true;
    }


    public:
        // Generate a new board
        Sodoku()
        {
            do{RandomizeBoard();} while( !isValidBoard() );
        }

        // Display the board
        string toString()
        {
            string boardString;
            for (int row_idx : board)
            {
                for (int col_idx : board.at(row_idx))
                {
                    boardString += to_string(board[row_idx][col_idx]) + " ";
                }
                boardString += "\n";
            }
            return boardString;
        }

        void move(int row, int col, int num)
        {
            if (MoveIsSafe(row, col, num))
            {
                board[row][col] = num;
            }
        }
};