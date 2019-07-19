#include <bits/stdc++.h>
using namespace std;

/*
    We are given an array of +ve int. We need to make the given array a 'Palindrome'.
    Only allowed operation is merge. Merging 2 adjacent ele means replacing them with their sum.
    Task is to find min no of merge operation required to make array palindrome.

    Approach:
    Let f(i,j) be min no of merge needed to make subarray a[i..j] a palindrome.
    base case: if(i==j) return 0.
    We start from i=0, j=n-1.
    1. if(a[i] == a[j]) ans = f(i+1,j-1)
    2. Else two case arise
        a. if(a[i] > a[j]), we should do merging at index j. a[j-1] = a[j-1]+a[j]
            ans = 1+f(i,j-1)
        b. if(a[i] < a[j]), we should do merge at index i, a[i+1] = a[i]+a[i+1]
            ans = 1+f(i+1,j)
    3. Our ans will be f(0,n-1)
 */

//recursive approach
int f(int *a, int i, int j){
    if(i==j) 
        return 0;
    int ans = 0;
    if(a[i] == a[j])
        ans = f(a,i+1,j-1);
    else if(a[i] > a[j]){
        a[j-1] = a[j]+a[j-1];
        ans = 1+f(a,i,j-1);
    }
    else{
        a[i+1] = a[i]+a[i+1];
        ans = 1+f(a,i+1,j);
    }
    return ans;
}

//iterative approach
int f2(int a[], int n){
    int ans = 0;
    for(int i=0, j=n-1; i<=j;){
        if(a[i] == a[j]){
            i++;
            j--;
        }
        else if(a[i] > a[j]){
            a[j-1] = a[j-1] + a[j];
            j--;
            ans++;
        }
        else{
            a[i+1] = a[i]+a[i+1];
            i++;
            ans++;
        }
    }
    return ans;
}

int main(){
    int a[] = {11,14,15,99};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<f(a,0,3)<<endl;
    cout<<f2(a,n)<<endl;
}