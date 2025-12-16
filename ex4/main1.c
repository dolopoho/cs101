#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

class TicTacToe {
private:
    std::vector<char> board;
    int currentPlayer;
    bool gameOver;
    int movesCount;
    
public:
    TicTacToe() {
        
        board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        currentPlayer = 1; 
        gameOver = false;
        movesCount = 0;
    }
    
    void displayBoard() {
        std::cout << "  " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
        std::cout << "---+---+---\n";
        std::cout << "  " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
        std::cout << "---+---+---\n";
        std::cout << "  " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
    }
    
    bool makeMove(int position) {
        
        if (position < 1 || position > 9) {
            return false;
        }
        
        
        if (board[position - 1] == 'X' || board[position - 1] == 'O') {
            return false;
        }
        
        
        if (currentPlayer == 1) {
            board[position - 1] = 'X';
        } else {
            board[position - 1] = 'O';
        }
        
        movesCount++;
        return true;
    }
    
    bool checkWin() {
        
        for (int i = 0; i < 9; i += 3) {
            if (board[i] == board[i+1] && board[i] == board[i+2]) {
                return true;
            }
        }
        
        
        for (int i = 0; i < 3; i++) {
            if (board[i] == board[i+3] && board[i] == board[i+6]) {
                return true;
            }
        }
        
        
        if (board[0] == board[4] && board[0] == board[8]) {
            return true;
        }
        if (board[2] == board[4] && board[2] == board[6]) {
            return true;
        }
        
        return false;
    }
    
    bool checkDraw() {
        return (movesCount == 9) && !checkWin();
    }
    
    void switchPlayer() {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    
    void playGame() {
        
        std::cout << "-- Tic Tac Toe -- CSIE@CGU\n";
        std::cout << "Player 1 (X) - Player 2 (O)\n";
        displayBoard();
        
        
        while (!gameOver) {
            int position;
            
            
            while (true) {
                if (currentPlayer == 1) {
                    std::cout << "==> Player 1 (X), enter a number: ";
                } else {
                    std::cout << "==> Player 2 (O), enter a number: ";
                }
                
                if (std::cin >> position) {
                    if (makeMove(position)) {
                        break; 
                    } else {
                        std::cout << "==> Invalid value, please enter again\n";
                        std::cin.clear(); 
                        std::cin.ignore(10000, '\n'); 
                    }
                } else {
                    std::cout << "==> Invalid value, please enter again\n";
                    std::cin.clear(); 
                    std::cin.ignore(10000, '\n'); 
                }
            }
            
            
            displayBoard();
            
            
            if (checkWin()) {
                gameOver = true;
                if (currentPlayer == 1) {
                    std::cout << "==> Player 1 wins!\n";
                } else {
                    std::cout << "==> Player 2 wins!\n";
                }
                break;
            }
            
            
            if (checkDraw()) {
                gameOver = true;
                std::cout << "==> Game draw\n";
                break;
            }
            
            
            switchPlayer();
        }
    }
    
    
    int getCurrentPlayer() const { return currentPlayer; }
    bool isGameOver() const { return gameOver; }
    char getBoardPosition(int pos) const { 
        if (pos >= 1 && pos <= 9) 
            return board[pos - 1]; 
        return ' ';
    }
};

int main() {
    
    TicTacToe game;
    game.playGame();
    
    return 0;
}
