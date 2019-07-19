#include <bits/stdc++.h>
using namespace std;

// m: no of rows, n: no of column
void spiralPrint(int m, int n, int a[][100]){
    int k = 0; //starting row index
    int l = 0; //starting col index

    while(k < m && l < n){
        //print first row from remaining rows
        for(int i=l; i<n; i++)
            cout<<a[k][i]<<" ";
        k++; //increment first row index

        //print last column from remaining columns
        for(int i=k; i<m; i++)
            cout<<a[i][n-1]<<" ";
        n--; //decrement last column index

        //print last row from remaining rows
        if(k<m){
            for(int i=n-1; i>=l; i--)
                cout<<a[m-1][i]<<" ";
            m--; //decrement last row index
        }

        //print first column from remaining columns
        if(l<n){
            for(int i=m-1; i>=k; i--)
                cout<<a[i][l]<<" ";
            l++; //increment first column index
        }
    }
    cout<<'\n';
}

int main(){
    int a[][100] = { {1,2,3,4,5,6},
                  {7,8,9,10,11,12},
                  {13,14,15,16,17,18}};
    
    spiralPrint(3,6,a);
}