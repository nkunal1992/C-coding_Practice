#include <bits/stdc++.h>
using namespace std;

/*  Transforms the range [first,last) into a range with all the elements for which 
    pred returns true removed, and returns an iterator to the new end of that range.

    Return Value

    An iterator to the element that follows the last element not removed.
    The range between first and this iterator includes all the elements in the sequence for 
    which pred does not return true.

 */

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof(a)/sizeof(a[0]);

    auto it = remove_if(a,a+n,[](int x){return x%2==0;}); //it will point to end of result
    
    for(auto i=a; i<it; i++) cout<<*i<<" ";
    cout<<endl;
}