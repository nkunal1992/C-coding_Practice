#include <bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n){
    
    sort(arr,arr+n);
    int min_diff = INT_MAX;

    for(int i=0; i<n-1; i++){
        if(arr[i+1] - arr[i] < min_diff)
            min_diff = arr[i+1] - arr[i];
    }

    return min_diff;
}

int main(){
    int arr[] = {30,5,20,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findMinDiff(arr,n)<<endl;

    return 0;
}