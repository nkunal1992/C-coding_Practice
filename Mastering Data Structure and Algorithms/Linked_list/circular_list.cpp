#include <bits/stdc++.h>

class Node{
    public:
        int data;
        Node *next;

        Node()
            : next {nullptr} {}
        Node(int key)
            : data {key},next {nullptr} {}
};

class clist{
    private:
        Node *head;
    public:
        clist()
            : head {nullptr} {}
        clist(std::vector<int> arr){
            int n = static_cast<int>(arr.size());
            if(n == 0)
                clist();
            else{
                head = new Node(arr[0]);
                head->next = head;
                Node *temp {head};
                for(int i=1; i<n; i++){
                    Node *new_node = new Node(arr[i]);
                    temp->next = new_node;
                    new_node->next = head;
                    temp = temp->next;
                }
            }
        }
        ~clist(){
            if(head){
                Node *temp = head? head->next : nullptr,*t;
                head->next = nullptr;
                t = temp;
                while(temp){
                    temp = temp->next;
                    delete t;
                    t = temp;
                }
            }
        }

        void display();
        int length();
        void insert(int index, int key);
        int remove(int index);
};

void clist::display(){
    Node *first {head};
    std::cout<<"Elements are : [ ";
    if(first == nullptr){ 
        std::cout<<"]\n"; 
        return;
    }
    do{
        std::cout<<first->data<<" ";
        first = first->next;
    }while(first != head);
    std::cout<<"]\n";
}

int clist::length(){
    int count {1};
    if(head == nullptr) return 0;
    Node *temp {head->next};
    while(temp != head){
        count++;
        temp = temp->next;
    }
    return count;
}

void clist::insert(int index, int key){
    Node *temp, *new_node = new Node(key);
    if(index < 0 || index > length()){
        std::cout<<"Invalid position\n";
        return;
    }
    if(index == 0){
        if(head == nullptr){
            head = new_node;
            new_node->next = head;
        }
        else{
            temp = head;
            while(temp->next != head) temp = temp->next;
            temp->next = new_node;
            new_node->next = head;

            head = new_node;
        }
    }
    else{
        temp = head;
        for(int i {0}; i<index-1; i++)
            temp = temp->next;

        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int clist::remove(int index){
    if(head == nullptr){
        std::cout<<"List is empty. Can't delete\n";
        return -1;
    }
    if(index < 0 || index >= length()){
        std::cout<<"Invalid index.\n";
        return -1;
    }

    int deleted;
    Node *temp {head};
    if(index == 0){
        while(temp->next != head) temp = temp->next;
        
        temp->next = head->next;
        
        deleted = head->data;
        delete head;
        head = temp->next;

        return deleted;
    }
    else{
        for(int i=0; i<index-1; i++)
            temp = temp->next;
        Node *q = temp->next;
        temp->next = q->next;
        deleted = q->data;
        delete q;
        return deleted;
    }
}

int main(){
   // std::vector<int> arr {2,3,4,6,1,9,7};
    clist l1 = clist();
    l1.insert(0,5);
    l1.insert(1,7);
    l1.insert(2,9);
    l1.display();
    int del = l1.remove(0);
    std::cout<<del<<"\n";
    l1.display();
}