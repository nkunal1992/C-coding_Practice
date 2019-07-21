#include <bits/stdc++.h>
using namespace std;

/*
    for_each just applies fun on each item, it does not make any changes to the container.
    for changing container item directy, use transform
 */

int main(){
    int a[] = {2,4,6,7,1,9,21};
    int n = sizeof(a)/sizeof(a[0]);

    //square each num of array a
    for_each(a,a+n,[](int x){cout<<(x*x)<<" ";});

    cout<<endl;
}