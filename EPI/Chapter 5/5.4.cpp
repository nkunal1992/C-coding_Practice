//Find closest integer with same weight
/*
Define the weight of a nonnegative integer x to be the no of bits that are set to 1 in in it's
binary representation.
*/

#include <bits/stdc++.h>

unsigned long closestIntSameBitCount(unsigned long x){
    constexpr int numUnsignBits = 64;
    for(int i {0}; i<numUnsignBits-1; i++){
        if(((x>>i)&1) != ((x>>(i+1))&1)){
            x = x ^ ((1L<<i)|(1L<<(i+1)));
            return x;
        }
    }
    throw "All bits are 0 or 1";
}

int main(){
    long x {0};
    std::cout<<"Before call, x : "<<x<<'\n';
    try{
        std::cout<<"After call, x : "<<closestIntSameBitCount(x)<<'\n';
    }
    catch(const char* ex){
        std::cout<<"Exception occurred: "<<ex<<'\n';
    }
}