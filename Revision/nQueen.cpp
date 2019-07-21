#include <bits/stdc++.h>
using namespace std;

int board[100][100] {0};
int n,DONE;

//return position of 1st set bit
int getPos(int n){
    int pos = 0;
    while(n>0){
        pos++;
        n = n>>1;
    }
    return pos-1;
}

void solveNQueen(int rowMask, int ld, int rd, int row){
    if(row == n){
        cout<<'\n';
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1)
                    cout<<" Q ";
                else 
                    cout<<" * ";
            }
            cout<<endl;
        }

        cout<<"\n\n";
        return;
    }
    int safe = DONE & (~(rowMask | ld | rd));

    //keep placing Quuen at safe position
    while(safe){
        int pos = safe & (-safe); //extract 1st set bit
        int col = getPos(pos);

        safe = safe - pos;
        board[row][col] = 1;
        solveNQueen(rowMask | pos, (ld|pos)<<1, (rd|pos)>>1, row+1);
        board[row][col] = 0;
        
    }
}

int main(){
    cout<<"n : ";
    cin>>n;

    DONE = (1<<n)-1;
    solveNQueen(0,0,0,0);
}