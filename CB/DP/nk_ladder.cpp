#include <bits/stdc++.h>
using namespace std;

int N[1000] = {};
// int res = 0;
// int numWays(int n, int k, int &res){
//     if(N.count(n)) return N[n];

//     for(int i=1; i<=k; i++)
//         res += numWays(n-i,k,res);

//     N[n] = res;
//     return N[n];
// }

int main(){
    int n,k;
    cin>>n>>k;
    N[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=k; j++)
            N[i] += N[i-j];
    }

    cout<<N[n];
}