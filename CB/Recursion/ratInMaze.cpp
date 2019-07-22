#include <bits/stdc++.h>
using namespace std;

int numWays {0};

bool ratInMaze(char maze[][10], int sol[][10], int i, int j, int m, int n){
    if(i == m and j == n){
        sol[i][j] = 1;
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
        numWays++;
        return true;
    }

    //rat should always be inside maze(grid)
    if(i>m || j>n) return false;
    //if particular cell is blocked
    if(maze[i][j] == 'x') return false;

    sol[i][j] = 1;
    bool rightSuccess = ratInMaze(maze,sol,i,j+1,m,n);
    bool downSuccess = ratInMaze(maze,sol,i+1,j,m,n);

    //backtrac
    sol[i][j] = 0;

    if(rightSuccess or downSuccess) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char maze[10][10] = {"0000","00x0","000x","0x00"};
    int sol[10][10] {0};
    
    ratInMaze(maze,sol,0,0,3,3);
    cout<<"Total no of ways : "<<numWays<<'\n';
}