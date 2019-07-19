#include <bits/stdc++.h>

template <class T>
class Node{
    public:
        T data;
        Node *next;
    
        Node()
            : data {}, next {nullptr} {}
        Node(T key)
            : data {key}, next {nullptr} {}
};

template <class T>
class queue{
    Node<T> *front;
    Node<T> *rear;
    int length;
public:
    queue(){
        front = nullptr;
        rear = nullptr;
        length = 0;
    }

    queue(std::vector<T> arr){
        int n = static_cast<int>(arr.size());
        length = n;
        if(n==0){
            front = nullptr;
            rear = nullptr;
        }
        else{
            Node<T> *new_node = new Node<T>(arr[0]);
            front = rear = new_node;
            for(int i=1; i<n; i++){
                new_node = new Node<T>(arr[i]);
                rear->next = new_node;
                rear = new_node;
            }
        }
    }

    ~queue() {
        Node<T> *p = front;
        while(front){
            front = front->next;
            delete p;
            p = front;
        }
        rear = nullptr;
        length = 0;
    }
    int size() { return length; }
    bool empty() { return front == nullptr; }
    void push(T data);
    void pop();
    bool full();
    void display();
};

template <class T>
void queue<T>::push(T data){
    Node<T> *new_node = new Node<T>(data);
    if(front == nullptr){
        front = rear = new_node;
        return;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        length += 1;
    } 
}

template <class T>
void queue<T>::pop(){
    Node<T> *temp {front};
    if(front != nullptr){
        front = front->next;
        delete temp;
        length -= 1;
    }
}

template <class T>
void queue<T>::display(){
    Node<T> *temp {front};
    while(temp){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"\n";
}

int main(){
    queue<int> q1(std::vector<int>{1,2,3,4,5,6,7});
    q1.pop();
    q1.pop();
    q1.display();
    std::cout<<q1.size()<<"\n";
}

