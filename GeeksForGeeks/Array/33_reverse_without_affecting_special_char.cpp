#include <bits/stdc++.h>
using namespace std;

void reverse_special(string &str, int low, int high){
    if(low >= high) return;
    while(!isalpha(str[low])) low++;
    while(!isalpha(str[high])) high--;

    swap(str[low],str[high]);
    reverse_special(str,low+1,high-1);
}

int main(){
    string str = {"Ab,c,de!$"};
    reverse_special(str,0,str.length()-1);
    cout<<str<<endl;
}