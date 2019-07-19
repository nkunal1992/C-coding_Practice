#include <bits/stdc++.h>

class cqueue{
    size_t max_size;
    int f;
    int r;
    int *Q;
public:
    cqueue()
        : max_size {8}, f {0}, r {0}, Q {new int [max_size]} {}
    cqueue(size_t n)
        : max_size {n}, f {0}, r {0}, Q {new int [max_size]} {}
    cqueue(std::vector<int> arr)
        : max_size { arr.size() ? 2*arr.size():8 }, f {0}, r {0}, Q { new int [max_size] }{
        for(size_t i=0; i<arr.size(); i++)
            Q[++r] = arr[i];
    }
    ~cqueue(){
        delete [] Q;
        f = r = -1;
    }
    void display();
    void push(int data);
    void pop();
    int front();
    int back();
    bool empty();
    bool full();
};

void cqueue::display(){
    int size = static_cast<int>(max_size);
    std::cout<<"Elements are : [ ";
    for(int i=(f+1)%size; i<=r; i=(i+1)%size){
        std::cout<<Q[i]<<" ";
    }
    std::cout<<"]\n";
}

void cqueue::push(int data){
    int size = static_cast<int>(max_size);
    if((r+1)%size == f){
        std::cout<<"cqueue full\n";
        return;
    }
    r = (r+1)%size;
    Q[r] = data;
}

void cqueue::pop(){
    int size = static_cast<int>(max_size);
    if(f == r){
        f=r=0;
        std::cout<<"cqueue empty\n";
        return; 
    }
    f = (f+1)%size;
}

int cqueue::front(){
    int size = static_cast<int>(max_size);
    if(f == r){
        f=r=0;
        //std::cout<<"cqueue empty\n";
        return INT_MIN; 
    }
    return Q[(f+1)%size];
}

int cqueue::back(){
    if(f == r){
        f=r=0;
        //std::cout<<"cqueue empty\n";
        return INT_MIN; 
    }
    return Q[r];
}

bool cqueue::empty(){
    if(f == r){
        f=r=0;
        return true;
    }
    return false;
}

bool cqueue::full(){
    int size = static_cast<int>(max_size);
    if((r+1)%size == f)
        return true;
    else 
        return false;
}

int main(){
    std::vector<int> arr {};
    cqueue q1(arr);
    q1.display();
    if(q1.front()!=INT_MIN)
        std::cout<<q1.front()<<"\n";
    q1.pop();
    q1.display();
    q1.push(21);
    q1.display();
}