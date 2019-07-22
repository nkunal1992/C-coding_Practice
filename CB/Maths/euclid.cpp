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

int main(){
    //solve equation like aX+bY = gcd(a,b), a,b are constants. Find X and Y
    //18x+30y = 6 i.e gcd(18,30)
    euclid(18,30);
    cout<<"gcd(18,30) : "<<gcd<<endl;
    cout<<"x : "<<x<<" y: "<<y<<endl;
}