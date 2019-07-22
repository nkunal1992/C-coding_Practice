#include <bits/stdc++.h>
using namespace std;

int gcd,x,y;
void euclid(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        gcd = a;
        return;
    }
    euclid(b,a%b);
    int cx = y;
    int cy = x-(a/b)*y;

    x = cx;
    y = cy;
}

int InverseModulo(int a, int m){
    euclid(a,m);
    return (x+m)%m; //if x is -ve adding m will make it +ve 
}

//muliplicative modulo of a w.r.t m exist iff gcd(a,m) = 1;

int main(){
    //find b such that (6*b)%13 = 1; here a = 6, m = 13
    
    cout<<"Multiplicative Inverse of 6 w.r.t 13 is "<<InverseModulo(6,13)<<endl;
}