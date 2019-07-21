#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {2,4,6,7,1,9,9,21};
    int n = sizeof(a)/sizeof(a[0]);

    int b[] = {7,1,9};

    //search sequence b in a
    auto it = search(a,a+n,b,b+3);
    cout<<"Sequence found at index "<<(it-a)<<endl;

    //search two 9's in a
    it = search_n(a,a+n,2,9);
    cout<<"Two 9's found at index : "<<(it-a)<<endl;
}