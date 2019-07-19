#include <bits/stdc++.h>

class queue{
    size_t max_size;
    int f;
    int r;
    int *Q;
public:
    queue()
        : max_size {8}, f {-1}, r {-1}, Q {new int [max_size]} {}
    queue(size_t n)
        : max_size {n}, f {-1}, r {-1}, Q {new int [max_size]} {}
    queue(std::vector<int> arr)
        : max_size { arr.size() ? 2*arr.size():8 }, f {-1}, r {-1}, Q { new int [max_size] }{
        for(size_t i=0; i<arr.size(); i++)
            Q[++r] = arr[i];
    }
    ~queue(){
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

void queue::display(){
    std::cout<<"Elements are : [ ";
    for(int i=f+1; i<=r; i++){
        std::cout<<Q[i]<<" ";
    }
    std::cout<<"]\n";
}

void queue::push(int data){
    if(r == static_cast<int>(max_size)-1){
        std::cout<<"Queue full\n";
        return;
    }
    Q[++r] = data;
}

void queue::pop(){
    if(f == r){
        f=r=-1;
        std::cout<<"Queue empty\n";
        return; 
    }
    f++;
}

int queue::front(){
    if(f == r){
        f=r=-1;
        //std::cout<<"Queue empty\n";
        return INT_MIN; 
    }
    return Q[f+1];
}

int queue::back(){
    if(f == r){
        f=r=-1;
        //std::cout<<"Queue empty\n";
        return INT_MIN; 
    }
    return Q[r];
}

bool queue::empty(){
    if(f == r){
        f=r=-1;
        return true;
    }
    return false;
}

bool queue::full(){
    if(r == static_cast<int>(max_size)-1)
        return true;
    else 
        return false;
}

int main(){
    std::vector<int> arr {};
    queue q1(arr);
    q1.display();
    if(q1.front()!=INT_MIN)
        std::cout<<q1.front()<<"\n";
    q1.pop();
    q1.display();
    q1.push(21);
    q1.display();
}