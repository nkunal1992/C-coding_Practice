#include <bits/stdc++.h>

int fact(int n){
    if(n == 0)
        return 1;
    else 
        return fact(n-1)*n;
}

int main(){
    std::cout<<"factorial(5) : "<<fact(6)<<'\n';
}