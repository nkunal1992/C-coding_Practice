#include <bits/stdc++.h>
using namespace std;

//(a^b)%10
long long fastModExp(long long a, long long b, long long m){
    long long res = 1;

    while(b>0){
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return res%m;
}

int main(){
    cout<<fastModExp(2,10,1000000000)<<endl;
}