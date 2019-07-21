#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {2,4,6,7,1,9,21};
    int n = sizeof(a)/sizeof(a[0]);

    //square each num of array a
    transform(a,a+n,a,[](int x){return x*x;});

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}