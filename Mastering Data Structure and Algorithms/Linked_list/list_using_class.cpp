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
class list{
    private:
        Node<T> *first;
    public:
        list(){
            first = nullptr;
        }

        list(std::vector<T> arr){
            int n = static_cast<int>(arr.size());
            if(n==0){
                first = nullptr;
            }
            else{
                first = new Node<T>(arr[0]);

                Node<T> *new_node, *cur {first};
                for(int i=1; i<n; i++){
                    new_node = new Node<T>(arr[i]);
                    cur->next = new_node;
                    cur = cur->next;
                }
            }
        }

        ~list() {
            Node<T> *p = first;
            while(first){
                first = first->next;
                delete p;
                p = first;
            }
        }

        Node<T> *get_head() {return first;}
        void set_head(Node<T> *head) { first = head;}
        void display();
        void insert_at_pos(int pos, T key);
        int count();
        void reverse_recursion(Node<T> *p, Node<T> *q);
        void concatenate(list &list2);
        void merge(list &list2);
        bool is_loop();
        void middle_element();
        void intersection_point(Node<T> *second);
};

template <class T>
void list<T>::display(){
    Node<T> *temp {first};
    std::cout<<"Elements are : [ ";
    while(temp){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"]\n";
}

template <class T>
void list<T>::insert_at_pos(int pos, T key){
    Node<T> *temp {first}, *new_node {new Node<T>(key)};
    if(temp == nullptr){
        first = new_node;
        return;
    }

    if(pos == 0){
        new_node->next = first;
        first = new_node;
        return;
    }

    while(temp && pos-1 > 0){
        temp = temp->next;
        pos--;
    }
    if(pos == 1){
    new_node->next = temp->next;
    temp->next = new_node;
    }
    else{
        std::cout<<"Invalid position. Can't insert\n";
    }
}

template <class T>
int list<T>::count(){
    Node<T> *temp {first};
    unsigned int counter {0};
    while(temp){
        counter++;
        temp = temp->next;
    }
    return counter;
}

template <class T>
void list<T>::reverse_recursion(Node<T> *prev, Node<T> *cur){
    if(cur != nullptr){
        reverse_recursion(cur, cur->next);
        cur->next=prev;
    }
    if(cur == nullptr)
        first = prev;
}

template <class T>
void list<T>::concatenate(list<T> &list2){
    Node<T> *temp {first}, *second {list2.get_head()};
    if(second == nullptr)
        return;
    if(temp == nullptr){
        first = second;
        return;
    }
    while(temp->next != nullptr) {temp = temp->next;}

    temp->next = second;
    second = nullptr;
}

template <class T>
void list<T>::merge(list<T> &list2){
    Node<T> *third, *last, *f {first}, *s {list2.get_head()};
    if(s == nullptr)
        return;
    if(f == nullptr){
        first = s;
        return;
    }

    if(f->data < s->data){
        third = last = f;
        f = f->next;
        last->next = nullptr;
    }
    else{
        third = last = s;
        s = s->next;
        last->next = nullptr;
    }

    while(f && s){
        if(f->data < s->data){
            last->next = f;
            last = f;
            f = f->next;
            last->next = nullptr;
        }
        else{
            last->next = s;
            last = s;
            s = s->next;
            last->next = nullptr;
        }
    }

    if(f) last->next = f;
    if(s) last->next = s;

    f = nullptr;
    first = third;
    s = nullptr;
}

template <class T>
bool list<T>::is_loop(){
    Node<T> *cur {first}, *prev {first};
    if(cur == nullptr)
        return false;
    do{
        cur = cur->next;
        prev = prev->next;
        prev = prev ? prev->next : nullptr;
    }while(prev && cur && (prev != cur));

    if(prev == cur)
        return true;
    else 
        return false;
}

template <class T>
void list<T>::middle_element(){
    if(first == nullptr){
        std::cout<<"List is empty. No middle element\n";
        return;
    }
    std::stack<Node<T> *> s;
    Node<T>* temp {first};
    while(temp){
        s.push(temp);
        temp = temp->next;
    }
    int n = s.size(), t = n;
    T middle = (s.top())->data;
    while(n > (t/2)){
        middle = (s.top())->data;
        n--;
        s.pop();
    }
    std::cout<<"Middle element is : "<<middle<<"\n";
}

template <class T>
void list<T>::intersection_point(Node<T> *sec){
    if(first == nullptr || sec == nullptr){
        std::cout<<"No intersection point\n";
        return;
    }
    std::stack<Node<T> *> s1,s2;
    Node<T> *f {first}, *s {sec};

    while(f){
        s1.push(f);
        f = f->next;
    }
    while(s){
        s2.push(s);
        s = s->next;
    }

    T res;
    bool flag;
    while(s1.top() == s2.top()){
        res = (s1.top())->data;
        s1.pop();
        s2.pop();
        flag = true;
    }
    if(!flag){
        std::cout<<"No intersection point\n";
        return;
    }
    else{
        std::cout<<"Intersection point is "<<res<<std::endl;
    }
}

int main(){
    std::vector<int> arr {2,4,6,8,10}, arr2 {3,5,7,9};
    list<int> int_list = list<int>(arr);
    list<int> list2 = list<int>(arr2);
    int_list.display();
    //int_list.reverse_recursion(nullptr,int_list.get_head());
    //int_list.concatenate(list2);
    int_list.merge(list2);
    int_list.display();
    std::cout<<"no of node in list : "<<int_list.count()<<"\n";

    list<int> l1 = list<int>(arr);
   // list<int> l2 = list<int>(arr2);
    l1.display();
    // Node<int> *first = l1.get_head(), *t1, *t2;
    // t2 = first;
    // t1 = first->next->next->next->next;
    // t1->next = first->next;//make cycle

    // std::cout<<std::boolalpha<<"Is loop exist : "<<l1.is_loop()<<std::endl;
    // t1->next = nullptr;//break cycle
    list2.display();
    list2.middle_element();
    l1.get_head()->next->next = list2.get_head()->next;
    // l1.display();
    // list2.display();
    l1.intersection_point(list2.get_head());
    return 0;
}