//Find Parity

#include <bits/stdc++.h>

//O(log n)
short nearest_power_of_2(short n){
    if(n && !(n & (n-1))) //check if it is power of 2
        return n;

    short p {1};
    while(p<n)
        p <<= 1;

    return p;
}

//o(n) : n = word size
short parity(unsigned long x){
    // std::cout<<"\nparity\n";
    short result {0};
    while(x){      
        result ^= (x&1);
        x = x>>1;
        // std::cout<<"\nresult : "<<result<<" x: "<<x<<std::endl;
    }
    return result;
}

//O(k) : k = no of 1s in x
short parity1(unsigned long x){
    // std::cout<<"\nparity1\n";
    short result {0};
    while(x){      
        result ^= 1;
        x &= (x-1); //drops lowest set bit
       // x = x>>1;
        // std::cout<<"\nresult : "<<result<<" x: "<<x<<std::endl;
    }
    return result;
}

short parity2(unsigned long x){
    
    short d {0};
    unsigned long t {x};
    while(t >>= 1) d++; //find no of digit

    // std::cout<<"\nNo of bit :"<<d<<" nearest power of 2: ";
    d = nearest_power_of_2(d);
    // std::cout<<d<<"\n";
    while(d/2){
        d = d/2;
        x ^= x>>d;
    }

    return x & 0x1;
}

//O(log(wordsize))
short parity3(unsigned long x){
    
    short wordsize {64};

    while(wordsize){
        wordsize /= 2;
        x ^= x>>wordsize;
    }
    return x & 0x1;
}


int main(){
    std::cout<<parity(65)<<std::endl;
    std::cout<<parity2(65)<<std::endl;
    std::cout<<parity3(65)<<std::endl;
}