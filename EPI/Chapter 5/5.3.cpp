//reverse bits of number. x = 10 i.e 1010 then output should be 0101 i.e 5

#include<bits/stdc++.h>

long reversebits(long x){
    bool sign {x>=0};
    for(int i {0}, j {63}; i<j; i++,j--){
        if(((x>>i)&1) != ((x>>j)&1)){
            unsigned long bit_mask =(1L<<i) | (1L<<j);
            x = x^bit_mask;
        }
    }
    if(sign)
        return x>=0?x:-x;
    else 
        return x>=0?-x:x;
}

int main(){
    long x {14};
    std::cout<<"Before reverse, x : "<<x<<'\n';
    std::cout<<"After reverse, x : "<<reversebits(x)<<'\n';
}