#include <bits/stdc++.h>

void checkifAnagram(const std::string &str1, const std::string &str2){
    if(str1.length()!=str2.length()){
        std::cout<<str1<<" and "<<str2<<" are not anagram\n";
        return;
    }
    int hash[26] {0},i;
    for(i=0; str1[i]!='\0'; i++){
        hash[str1[i]-97]+=1;
    }
    for(i=0; str2[i]!='\0'; i++){
        hash[str2[i]-97]-=1;
        if(hash[str2[i]-97]<0){
            std::cout<<str1<<" and "<<str2<<" are not anagram\n";
            return;
        }
    }
    if(str2[i]=='\0')
        std::cout<<str1<<" and "<<str2<<" are anagram\n";
}

int main(){
    std::string str1 {"medical"}, str2 {"decimal"};
    checkifAnagram(str1,str2);
}