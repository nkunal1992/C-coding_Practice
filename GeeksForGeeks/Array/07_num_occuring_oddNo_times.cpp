#include <bits/stdc++.h>
using namespace std;

/*
    All numbers are occuring even no of times except one.
    use xor
 */

int findOdd(int *a, int n){
    int res = 0;
    for(int i=0; i<n; i++)
        res ^= a[i];

    return res;
}

int main(){
    int arr[] = {1,2,3,2,1,4,4,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<findOdd(arr,n)<<endl;
}