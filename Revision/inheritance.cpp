#include <bits/stdc++.h>
using namespace std;

class Base final{
    int p_a;
protected:
    int pr_a;
public:
    int pu_a;
};
class PuDerived:public Base{

};

class PrDerived:protected Base{

};

int main(){
    PuDerived pr;
    cout<<pr.pr_a<<endl;
}