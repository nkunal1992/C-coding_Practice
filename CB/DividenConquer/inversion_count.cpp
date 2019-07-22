#include <bits/stdc++.h>
using namespace std;

//we can use merge sort logic to count inversion
int merge(int *a, int s, int m, int e){
    int *b = new int[e-s+1];
    int inversion_count = 0;

    int i = s; //point to first part
    int j = m+1; //point to second part
    int k = 0; //points to b array
    while(i <= m and j <= e){
        if(a[i] > a[j]){
            inversion_count += (m-i+1);
            b[k++] = a[j++];
        }
        else 
            b[k++] = a[i++];
    }
    //copy remaining item
    for(; i<=m; i++) b[k++] = a[i];
    for(; j<=e; j++) b[k++] = a[j];

    //copy sorted element back to original array
    k = 0;
    for(int i=s; i<=e; i++) a[i] = b[k++];

    //release b array
    delete [] b;

    return inversion_count;
}

int inversionCount(int *a, int s, int e){
    if(s >= e) return 0;
    int mid = (s+e)/2;

    return inversionCount(a,s,mid) + inversionCount(a,mid+1,e) + merge(a,s,mid,e);
}

int main(){
    int a[] = {4,6,1,2,7,3};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<inversionCount(a,0,n-1)<<endl;

    return 0;
}