#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {2,4,6,7,1,9,-8,9,21};
    int n = sizeof(a)/sizeof(a[0]);

    auto it = minmax_element(a,a+n); //returns pair

    cout<<"Min : "<<*(it).first<<" Max: "<<*(it).second<<endl;
}