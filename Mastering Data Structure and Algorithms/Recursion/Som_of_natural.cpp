#include <bits/stdc++.h>

int sum(int n){
    if(n == 0)
        return 0;
    else 
        return sum(n-1)+n;
}

int main(){
    std::cout<<"Sum of 5 natural number : "<<sum(5)<<'\n';
}