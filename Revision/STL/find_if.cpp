#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {2,4,6,7,1,9,21};
    int n = sizeof(a)/sizeof(a[0]);

    //find first odd 
    auto it = find_if(a,a+n,[](int x){return x%2==1;});
    cout<<"First odd is : "<<*it<<endl;
}