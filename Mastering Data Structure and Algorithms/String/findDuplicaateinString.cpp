#include <bits/stdc++.h>

void findDuplicate(const std::string &str){
    long int h {0}, mask {0};
    std::cout<<"\nDuplicates are : ";
    for(int i {0}; i<str.length(); i++){
        mask = 1;
        mask = mask << str[i]-97;

        if(mask & str[i] > 0)
            std::cout<<str[i]<<" ";
    }
    std::cout<<"\n";
}

int main(){
    std::string str {"narayan"};
    findDuplicate(str);
}