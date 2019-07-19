#include <bits/stdc++.h>
using namespace std;

/*
    Given an array A[], find the max difference b/w any two elements such that larger
    element appears after the smaller number in array.
 */
int maxDiff(int a[], int n){
    int Max = INT_MIN, Min = INT_MAX, diff;

    for(int i=0; i<n; i++){
        if(a[i] > Max){
            Max = a[i];
            if(Min != INT_MAX)
                diff = Max-Min;
        }
        if(a[i] < Min)
            Min = a[i];
    }

    return diff;
}

int main(){
    int a[] ={7,9,5,6,3,2}; //{2,3,10,6,4,8,1};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<maxDiff(a,n)<<endl;
}