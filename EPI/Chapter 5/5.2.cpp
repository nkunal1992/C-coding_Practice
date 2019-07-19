//swap ith and jth bit of number n

#include <bits/stdc++.h>

long swapbits(long x, int i, int j){
    //extracts ith bit: (x>>i)&1
    if( ((x>>i)&1) != ((x>>j)&1) ){//if ith and jth bit differ
        //set bit mask at ith and jth bit
        unsigned long bit_mask = (1L<<i) | (1L<<j);
        x = x^bit_mask; //it will flip the bit
    }
    return x;
}

int main(){
    long x {10};
    std::cout<<"Before swap, x : "<<x<<'\n';
    std::cout<<"After swap, x : "<<swapbits(x,1,2)<<'\n';
}