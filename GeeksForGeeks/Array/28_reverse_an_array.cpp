#include <bits/stdc++.h>
using namespace std;

template <class T>
void iter_reverse(T arr[], int n){
    for(int i=0, j=n-1; i<j;i++,j--)
        swap(arr[i],arr[j]);
}

template <class T>
void rec_reverse(T arr[], int i, int j){
    if(i==j) return;
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    rec_reverse(arr, i+1, j-1);
}

int main(){
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);

    //iter_reverse(a,n);
    rec_reverse(a,0,n-1);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}