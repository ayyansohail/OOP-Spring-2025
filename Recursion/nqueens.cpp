#include<iostream>
#include<vector>
using namespace std;

//Place N queens on an N×N chessboard such that no two queens attack each other.

bool isSafe(vector<string>& board, int row, int col, int n){
    //Check Column Above
    for(int i = 0; i<row; i++){
        if(board[i][col] == 'Q' ){
            return false;
        }
    }
    //Check Upper Left Diagonal 
    for(int i = row - 1, j = col - 1; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    //Check upper right diagonal
    for(int i = row - 1, j = col + 1; i>=0 && j<n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<string>& board, int row, int n){
    if(row == n){
        for (string line : board){
            cout<<line<<endl;
        }
        cout<<endl;
        return;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(board,row,col,n)){
            board[row][col] = 'Q';  //make a choice
            solveNQueens(board, row + 1, n);
            board[row][col] = '.'; //Undo (Backtrack)
        }
    }
}

int main(){
    int n = 4;
    vector<string> board(n, string(n,'.')); //Empty Board
    solveNQueens(board, 0 , n);
    return 0;
}