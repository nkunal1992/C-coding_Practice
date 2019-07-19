#include <bits/stdc++.h>
using namespace std;

int f[1000];
int fib(int n){
    if(n==0 || n==1){
        f[n] = n;
        return n;
    }
    if(f[n]!=-1) return f[n];

    f[n] = fib(n-1)+fib(n-2);
    return f[n];
}

int main(){
    memset(f,-1,sizeof(f));
    cout<<fib(45)<<'\n';
}