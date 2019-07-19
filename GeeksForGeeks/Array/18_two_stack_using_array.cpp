#include <bits/stdc++.h>
using namespace std;

class twostack{
    int *arr;
    int size;
    int top1;
    int top2;
public:
    twostack(int n){
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    ~twostack(){
        delete [] arr;
    }

    void push1(int data){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout<<"Stack overflow\n";
        }
    }

    void push2(int data){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout<<"Stack overflow\n";
        }
    }

    int pop1(){
        if(top1>-1){
            int res = arr[top1];
            top1--;
            return res;
        }
        else{
            cout<<"Stack underflow\n";
            exit(1);
        }
    }

    int pop2(){
        if(top2<size){
            int res = arr[top2];
            top2++;
            return res;
        }
        else{
            cout<<"Stack underflow\n";
            exit(1);
        }
    }
};

int main(){
    twostack s(5);
    s.push1(5);
    s.push2(10);
    s.push2(15);
    s.push1(11);
    s.push2(7);
    cout<<"Popped item from stack1 is "<<s.pop1()<<endl;
    s.push2(40);
    cout<<"Popped item from stack2 is "<<s.pop2()<<endl;
}