#include <bits/stdc++.h>

void stringPermutation1(const std::string &str, int k){
    static int A[10] {0};
    static char res[10];
    int i;
    if(str[k]=='\0'){
        res[k]='\0';
        std::cout<<res<<"\n";
    }
    else{
        for(i=0;str[i]!='\0'; i++){
            if(A[i]==0){
                A[i]=1;
                res[k]=str[i];
                stringPermutation1(str,k+1);
                A[i]=0;
            }
        }
    }
}

void stringPermutation2(std::string &str, int low, int high){
    if(low==high)
        std::cout<<str<<std::endl;
    else{
        for(int i {low}; i<=high; i++){
            std::swap(str[low],str[i]);
            stringPermutation2(str,low+1,high);
            std::swap(str[low],str[i]);
        }
    }
}

int main(){
    std::string str {"ABC"};
    stringPermutation2(str,0,2);
}