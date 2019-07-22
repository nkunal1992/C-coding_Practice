#include <bits/stdc++.h>
using namespace std;

int lower_bound(int *a, int n, int key){
    int s = 0;
    int e = n-1;
    int ans = -1;

    while(s <= e){
        int mid = (s+e)/2;

        if(a[mid] == key){
            ans = mid;
            e = mid-1; //we need to search in left
        }
        else if(a[mid] > key)
            e = mid-1;
        else 
            s = mid+1;
    }

    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a[] = {1,2,3,3,4,5,6,6,7,8,8,9};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<lower_bound(a,n,8)<<'\n';

    return 0;
}