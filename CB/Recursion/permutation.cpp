#include <bits/stdc++.h>
using namespace std;

void permutation(char in[100], int i){
    if(in[i] == '\0'){
        cout<<in<<'\n';
        return;
    }

    for(int j=i; in[j]!='\0'; j++){
        swap(in[i],in[j]);
        permutation(in,i+1);
        swap(in[i],in[j]); //backtrack to store the original array
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char ch[] = {"ABC"};
    permutation(ch,0);
}