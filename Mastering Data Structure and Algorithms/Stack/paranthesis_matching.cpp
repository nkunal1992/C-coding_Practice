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
class stack{
    Node<T> *Top;
    int length;
public:
    stack(){
        Top = nullptr;
        length = 0;
    }

    stack(std::vector<T> arr){
        int n = static_cast<int>(arr.size());
        length = n;
        if(n==0){
            Top = nullptr;
        }
        else{
            Top = new Node<T>(arr[0]);

            Node<T> *new_node;
            for(int i=1; i<n; i++){
                new_node = new Node<T>(arr[i]);
                new_node->next = Top;
                Top = new_node;
            }
        }
    }

    ~stack() {
        Node<T> *p = Top;
        while(Top){
            Top = Top->next;
            delete p;
            p = Top;
        }
        length = 0;
    }
    void push(T data);
    void pop();
    T top() { return Top ? Top->data : (std::numeric_limits<T>::min()); }
    bool empty() { return Top == nullptr; }
    bool full();
    int size() { return length; }
    void peep(int index);
    void display();
};

template <class T>
void stack<T>::push(T data){
    Node<T> *temp {Top}, *new_node {new Node<T>(data)};
    if(new_node == nullptr){
        std::cout<<"Stack Overflow\n";
        return;
    }
    if(temp == nullptr){
        Top = new_node;
        length = 1;
        return;
    }
    else{
        new_node->next = Top;
        Top = new_node;
        length += 1;
        return;
    }
}

template <class T>
void stack<T>::pop(){
    if(Top == nullptr){
        std::cout<<"Stack underflow\n";
        return;
    }
    Node<T> *t {Top};
    Top = Top->next;
    delete t;
    length -= 1;
}

template <class T>
bool stack<T>::full(){ 
    Node<T> *t = new Node<T>();
    if(t == nullptr) return true;
    free(t);
    return false; 
}

template <class T>
void stack<T>::peep(int index){
    if(length - index <= 0){
        std::cout<<"Invalid index\n";
        return;
    }
    Node<T> *temp {Top};
    for(int i=0; i<index; i++)
        temp = temp->next;

    std::cout<<"Element at index "<<index<<" is "<<temp->data<<"\n";
}

template <class T>
void stack<T>::display(){
    Node<T> *temp {Top};
    while(temp){
        std::cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

bool paranthesis_match(std::string str){
    stack<char> s1;
    std::map<char,char> dict {std::make_pair(']','['), std::make_pair('}','{'), std::make_pair(')','(')};
    for(int i=0; i<static_cast<int>(str.length()); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            s1.push(str[i]);
        else if(str[i] == ')' or str[i] == '}' || str[i] == ']'){
            char ch = dict[str[i]];
            if(s1.size() == 0 || s1.top() != ch)
                return false;
            s1.pop();
        }
    }
    if(s1.size() == 0) return true;
    return false;
}

int main(){
    std::string str {"[{2+3*(2-1)}]"};
    std::cout<<std::boolalpha<<paranthesis_match(str)<<"\n";
}

