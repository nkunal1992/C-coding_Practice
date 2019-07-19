#include <bits/stdc++.h>

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node()
            : next {nullptr}, prev {nullptr} {}
        Node(int key)
            : data {key}, next {nullptr}, prev {nullptr} {};
        ~Node()=default;
};

class dlist{
    private:
        Node *first;
    public:
        dlist()
            : first {nullptr} {}
        dlist(std::vector<int> arr){
            int n = static_cast<int>(arr.size());
            if(n == 0)
                dlist();
            else{
                first = new Node(arr[0]);
                Node *temp {first};
                for(int i=1; i<n; i++){
                    Node *new_node = new Node(arr[i]);
                    temp->next = new_node;
                    new_node->prev = temp;
                    temp = new_node;
                }
            }
        }
        ~dlist(){
            if(first){
                Node *temp {first};
                while(first){
                    first = first->next;
                    delete temp;
                    temp = first;
                }
            }
        }
        void display();
        int length();
        void insert(int pos, int key);
        int remove(int index);
        void reverse();
};

int dlist::length(){
    if(first == nullptr) return 0;
    int count {0};
    Node *temp {first};
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

void dlist::display(){
    std::cout<<"Elements are : [ ";
    if(first == nullptr){
        std::cout<<"]\n";
        return;
    }
    Node *temp {first};
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"]\n";
}

void dlist::insert(int index, int key){
    if(index < 0 || index > length()){
        std::cout<<"Invalid position\n";
        return;
    }
    if(index == 0){
        if(first == nullptr){
            first = new Node(key);
            return;
        }
        else{
            Node *new_node = new Node(key);
            new_node->next = first;
            first->prev = new_node;

            first = new_node;
            return;
        }
    }
    else{
        Node *new_node = new Node(key);
        Node *temp {first};
        for(int i=0; i<index-1; i++)
            temp = temp->next;

        new_node->next = temp->next;
        new_node->prev = temp;
        if(temp->next) //if next node is availavle then only update it's previous link
            temp->next->prev = new_node;
        temp->next = new_node;
    }
}

int dlist::remove(int index){
    if(first == nullptr){
        std::cout<<"List is empty. Can't delete\n";
        return -1;
    }
    if(index < 0 || index >= length()){
        std::cout<<"Invalid index.\n";
        return -1;
    }

    int deleted;
    Node *temp {first};

    if(index == 0){
        first = first->next;
        deleted = temp->data;
        delete temp;
    }
    else{
        for(int i=0; i<index; i++)
            temp = temp->next;

        temp->prev->next = temp->next;
        deleted = temp->data;
        if(temp->next)
            temp->next->prev = temp->prev;
        delete temp;
    }
    return deleted;
}

void dlist::reverse(){
    Node *temp {first};
    while(temp){
        std::swap(temp->next, temp->prev);
        temp = temp->prev;
        if(temp && temp->next == nullptr) first = temp;
    }
}

int main(){
    std::vector<int> arr {2,4,6,1,3,5,7,8};
    dlist l1 = dlist();
    l1.insert(0,2);
    l1.insert(1,5);
    l1.insert(1,7);
    l1.display();
   // l1.remove(23);
    l1.reverse();
    l1.display();
}