#include <bits/stdc++.h>

class stack{
    int max_size;
    int Top;
    int *s;

public:
    stack()
        : max_size {8}, Top {-1}, s {new int [8]} {}
    stack(int n)
        : max_size {n}, Top {-1}, s {new int [n]} {}
    stack(std::vector<int> arr){
        int n = static_cast<int>(arr.size());
        if(n == 0){
            s = new int [8];
        }
        else{
            s = new int [2*n];
            for(int i=0; i<n; i++)
                s[i] = arr[i];
            Top = n-1;
        }
    }
    ~stack(){
        delete [] s;
    }
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
    bool full();
    int peek(int index);
    void display();
    void create(std::vector<int> arr);
};

void stack::push(int data){
    if(Top == max_size-1){
        std::cout<<"Stack Overflow\n";
        return;
    }
    Top++;
    s[Top] = data;
}

void stack::pop(){
    if(Top == -1){
        std::cout<<"Stack underflow\n";
        return;
    }
    Top--;
}

int stack::top(){
    if(Top == -1){
        std::cout<<"Stack underflow\n";
        return -1;
    }
    return s[Top];
}

int stack::size(){
    return Top+1;
}

bool stack::empty(){
    if(Top == -1)
        return true;
    else 
        return false;
}

bool stack::full(){
    if(Top == max_size-1)
        return true;
    else 
        return false;
}

int stack::peek(int index){
    if(Top - index < 0){
        std::cout<<"Invalid index\n";
        return -1;
    }
    return s[Top-index];
}

void stack::display(){
    int n = size();
    for(int i {0}; i<n; i++)
        std::cout<<peek(i)<<"\n";
}

void stack::create(std::vector<int> arr){
    for(int i {0}; i<static_cast<int>(arr.size()); i++)
        push(arr[i]);
}

int main(){
    //stack s = stack(16);
    std::vector<int> arr {1,2,3,4,5,6,7};
    stack s(arr);
    //s.create(arr);
    s.display();
}