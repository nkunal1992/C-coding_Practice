#include <bits/stdc++.h>
using namespace std;

/*
    Given a number, you have to print all possible characters
 */
char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"}; 

// i : point to in, j : point to out
void printKeypad(char in[10], char out[10], int i, int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    int digit = in[i]-'0';
    if(digit == 0 || digit == 1) //as at 0 and 1, no character is mapped on phone keypad
        return printKeypad(in,out,i+1,j);
    int k=0;
    while(keypad[digit][k] != '\0'){
        out[j] = keypad[digit][k++];
        printKeypad(in,out,i+1,j+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char in[10] = {"345"};
    char out[10];

    printKeypad(in,out,0,0);
}