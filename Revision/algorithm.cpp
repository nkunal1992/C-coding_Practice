#include <bits/stdc++.h>
using namespace std;

int main(){
    //transform
    string name {"Narayan Kunal"};
    transform(name.begin(),name.end(),name.begin(),::toupper); //change to uppercase and store in name
    cout<<name<<'\n';

    int a[] = {10,11,12,13,14,15,16};
    transform(a,a+7,a,a,multiplies<int>()); //plus<int>() for addition
    for(auto i:a) cout<<i<<" ";
    cout<<endl;

    int num = count_if(a,a+7,[](int x){return (x&1) == 0;});
    cout<<"Even count : "<<num<<endl;

    int c = count(a,a+7,121);
    cout<<c<<endl;

    int b[10] = {};
    replace(b,b+10,0,-6);
    for(auto i:b) cout<<i<<" ";
    cout<<endl;
}