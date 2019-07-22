#include <bits/stdc++.h>
using namespace std;

void tower_of_hanoi(char src, char helper, char dest, int n){
    if(n == 1){
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<'\n';
        return;
    }

    //move n-1 disk from src(A) to helper(B)
    tower_of_hanoi(src,dest,helper,n-1);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<'\n';
    //move n-1 disk from helper(B) to dest(C)
    tower_of_hanoi(helper,src,dest,n-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    tower_of_hanoi('A','B','C',3);

    return 0;
}