#include <bits/stdc++.h>
using namespace std;

/*
    Given an array A[] of n numbers and another number x, determines whether or not there exist
    two elements in A[] whose sum is exactly x.

    Approach: use hashmap
 */

bool does_Pair_With_Sum_X_Exist(int *a, int n, int x){
    map<int,int> hash;

    for(int i=0; i<n; i++){
        if(hash.count(a[i]) == 0)
            hash[a[i]] = 0;
        else 
            hash[a[i]]++;
    }

    for(int i=0; i<n; i++){
        int temp = x-a[i];
        if(hash.count(temp)){
            if(temp == a[i] && hash[temp]>1)
                cout<<"Pair with sum "<<x<<" is "<<a[i]<<" and "<<temp<<endl;
            else if(temp!=a[i])
                cout<<"Pair with sum "<<x<<" is "<<a[i]<<" and "<<temp<<endl;
            break;
        }
    }
}

int main(){
    int arr[] = {1,2,5,6,9,-10,-4,-6};
    int n = sizeof(arr)/sizeof(arr[0]);

    does_Pair_With_Sum_X_Exist(arr,n,12);
}