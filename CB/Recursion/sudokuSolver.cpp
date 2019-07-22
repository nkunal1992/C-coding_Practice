#include <bits/stdc++.h>
using namespace std;

bool canPlace(int board[100][100],int i, int j, int n, int number){
    //row check
    for(int k=0; k<n; k++)
        if(board[i][k] == number or board[k][j] == number)
            return false;
    
    //subgrid check
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x=sx; x<sx+rn; x++){
        for(int y=sy; y<sy+rn; y++){
            if(board[x][y] == number)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(int board[100][100],int i, int j, int n){
    //base case
    if(i == n){
        //print board
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
        return true;
    }

    //row end
    if(j == n)
        return sudokuSolver(board,i+1,0,n);

    //already filled position
    if(board[i][j] != 0)
        return sudokuSolver(board,i,j+1,n);

    //try to fill current position
    for(int num = 1; num<=9; num++){
        if(canPlace(board,i,j,n,num)){
            board[i][j] = num;
            if(sudokuSolver(board,i,j+1,n))
                return true;

        }
    }

    //backtrack
    board[i][j] = 0; //remove filled value

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int board[100][100] = {{0,4,0,2,0,0,8,0,0},
                           {0,0,0,0,1,0,0,0,0},
                           {1,0,3,4,0,0,0,0,9},
                           {0,6,1,0,0,7,2,9,0},
                           {9,0,0,0,6,0,0,0,8},
                           {0,8,4,9,0,0,1,6,0},
                           {5,0,0,0,0,2,3,0,4},
                           {0,0,0,0,7,0,0,0,0},
                           {0,0,6,0,0,8,0,2,0}};

    sudokuSolver(board,0,0,9);
    return 0;
}