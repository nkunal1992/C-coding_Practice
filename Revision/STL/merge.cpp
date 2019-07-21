#include <bits/stdc++.h>
using namespace std;

int main(){
    int a1[] {1,7,4,3,2,9,-10};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int a2[] {11,7,14,5,21,19,-1};
    int n2 = sizeof(a2)/sizeof(a2[0]);

    sort(a1,a1+n1);
    sort(a2,a2+n2);
    int a3[n1+n2];
    merge(a1,a1+n1,a2,a2+n2,a3);
    for(int i=0; i<n1+n2; i++) cout<<a3[i]<<" ";
    cout<<endl;
}