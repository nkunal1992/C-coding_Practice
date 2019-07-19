#include <bits/stdc++.h>
using namespace std;

/*
    use leader in array approach
 */

void replaceGratestRight(int *a, int n){
    int leader = a[n-1];
    a[n-1] = -1;

    for(int i=n-2; i>=0; i--){
        if(a[i] > leader){
            int temp = a[i];
            a[i] = leader;
            leader = temp;
        }
        else{
            a[i] = leader;
        }
    }

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {16,17,4,3,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    replaceGratestRight(arr,n);
}