#include <bits/stdc++.h>

int main(){
    /* 
    std::srand(std::time(0));
    int random = std::rand()%10;
    std::cout<<random<<"\n";
    */

    std::mt19937 generator;
    generator.seed(std::time(0));

    std::uniform_int_distribution<int> dice;
    std::cout<<dice(generator)<<"\n";

    std::uniform_int_distribution<int> dice1(1,6);
    std::cout<<dice1(generator)<<"\n";

    std::uniform_real_distribution<double> dice3;
    std::cout<<dice3(generator)<<"\n";
    
    auto x = std::generate_canonical<double,10>(generator);
    std::cout<<x<<std::endl;;
}