#include <bits/stdc++.h>
using namespace std;

//top-down approach
map<int, int> N;
int numWays(int n, int k){
    if(N.count(n)) return N[n];

    int res = 0;
    for(int i=1; i<=k && (n-i)>=0; i++)
        res += numWays(n-i,k);

    N[n] = res;
    return N[n];
}

//recursive
int nk(int n, int k){
    if(n==0) return 1;

    int res = 0;
    for(int i=1; i<=k && (n-i)>=0; i++){
        res += nk(n-i, k);
    }
    return res;
}

int main(){
    N[0] = 1;
    //cout<<nk(4,3)<<'\n';
    cout<<numWays(4,3)<<'\n';
}