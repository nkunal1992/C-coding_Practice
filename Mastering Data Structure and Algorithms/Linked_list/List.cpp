#include <bits/stdc++.h>

template <class T>
class Node{
private:
    T data;
    Node *next;

public:
    Node()
        :next {nullptr} {}
    
    Node(T item)
        :data {item}, next {nullptr} {}

    Node* insert_front(T key);
    Node* insert_rear(T key);
    void display();
    void display_recursive(Node *head);
    void display_reverse(Node *head);
    int count();
    int count_recursive(Node *head);
    void add();
    void add_recursive(Node *head);
    void max();
    void min();
    void max_recursive(Node* head);
    void search(T key);
    void search_recursive(Node* head, T key);
    Node* insert_at_pos(int pos, T key);
    Node* insert_in_sorted(T key);
    Node* create_list(std::vector<T> arr);
    std::pair<Node*,T> delete_at_pos(int pos);
    bool is_sorted();
    void delete_duplicate();
    Node* reverse_links();
    void reverse_links_recursion(Node *first, Node* prev, Node* cur);
};

template <class T>
Node<T>* Node<T>::insert_front(T key){
    Node *temp = new Node(key);
    temp->next = this;
    return temp;
}

template <class T>
Node<T>* Node<T>::insert_rear(T key){
    Node *temp = new Node(key);
    if(this == nullptr)
        return temp;

    Node *it {this};
    while(it->next != nullptr){
        it = it->next;
    }
    it->next = temp;
    return this;
}

template <class T>
void Node<T>::display(){
    Node *temp {this};

    std::cout<<"\nElements are : [ ";
    while(temp){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"]\n";
}

template <class T>
void Node<T>::display_recursive(Node *head){
    if(head == this)
        std::cout<<"\nElements are : [ ";
    if(head != nullptr){
        std::cout<<head->data<<" ";
        display_recursive(head->next);
    }
    else
        std::cout<<"]\n";
}

template <class T>
void Node<T>::display_reverse(Node *head){
    if(head == this)
        std::cout<<"\nElements in reverse order are : [ ";
        
    if(head != nullptr){
        display_reverse(head->next);
        std::cout<<head->data<<" ";
    }
    
    if(head == this)
        std::cout<<"]\n";
}

template <class T>
int Node<T>::count(){
    Node *temp {this};
    int counter {0};

    while(temp){
        counter++;
        temp = temp->next;
    }

    return counter;
}

template <class T>
int Node<T>::count_recursive(Node* head){

    if(head == nullptr)
        return 0;
    else
        return 1+count_recursive(head->next);

}

template <class T>
void Node<T>::add(){
    Node *temp {this};
    T sum {};
    while(temp){
        sum += temp->data;
        temp = temp->next;
    }

    std::cout<<"\nSum of all elements is : "<<sum<<"\n";
}

template <class T>
void Node<T>::add_recursive(Node* head){
    static T sum {};
    if(head != nullptr){
        sum += head->data;
        add_recursive(head->next);
    }

    if(head == this)
        std::cout<<"\nSum of all elements is : "<<sum<<"\n";
}

template <class T>
void Node<T>::max(){
    Node* temp {this};
    T max_item {std::numeric_limits<T>::min()};

    while(temp){
        if(temp->data > max_item)
            max_item = temp->data;

        temp = temp->next;
    }

    std::cout<<"\nMax element is : "<<max_item<<"\n";
}

template <class T>
void Node<T>::min(){
    Node* temp {this};
    bool flag = (typeid(T).name() == typeid(std::string).name()); //check if type is string
    T min_item = {};
    if(flag){
        std::string t {std::numeric_limits<char>::max()}; //convert max char to string
        min_item = t;
    }
    else 
        min_item = std::numeric_limits<T>::max();

    while(temp){
        if(temp->data < min_item)
            min_item = temp->data;

        temp = temp->next;
    }

    std::cout<<"\nMin element is : "<<min_item<<"\n";
}

template <class T>
void Node<T>::max_recursive(Node *head){
    static T max_item {std::numeric_limits<T>::min()};

    if(head){
        if(head->data > max_item)
            max_item = head->data;
        
        max_recursive(head->next);
    }

   if(head == this)
        std::cout<<"\nMax element is : "<<max_item<<"\n";
}

template <class T>
void Node<T>::search(T key){
    Node* temp {this};
    bool flag {false};

    while(temp){
        if(temp->data == key){
            flag = true;
            break;
        }
        temp = temp->next;
    }

    std::cout<<"\nWhether "<<key<<" found? : "<<std::boolalpha<<flag<<"\n";
}

template <class T>
void Node<T>::search_recursive(Node* head, T key){
    static bool flag {false};
    if(head){
        if(head->data == key){
            flag = true;
            head = nullptr;
        }
        else 
            search_recursive(head->next, key);
    }
    if(head == nullptr)
        std::cout<<"\nWhether "<<key<<" found? : "<<std::boolalpha<<flag<<"\n";
}

template <class T>
Node<T>* Node<T>::insert_at_pos(int pos, T key){//insert at position pos
    int n = this->count();
    if(pos == 0){
        return this->insert_front(key);
    }
    else if(pos > n){
        std::cout<<"\nInvalid position. Can't insert\n";
        return this;
    }
    else{
        Node* temp {this};
        Node* new_node = new Node(key);

        while(pos-1){
            temp = temp->next;
            pos--;
        }

        new_node->next = temp->next;
        temp->next = new_node;

        return this;
    }
}

template <class T>
Node<T>* Node<T>::insert_in_sorted(T key){
    Node *cur {this},*prev {nullptr};
    if(cur == nullptr)
        return this->insert_front(key);

    while(cur && cur->data < key){
        prev = cur;
        cur = cur->next;
    }
    Node *new_node = new Node(key);
    prev->next = new_node;
    new_node->next = cur;

    return this;
}

template <class T>
Node<T>* Node<T>::create_list(std::vector<T> arr){
    Node* head {nullptr};
    for(int i {0}; i<static_cast<int>(arr.size()); i++)
       head =  head->insert_at_pos(i,arr[i]);

    return head;
}

template <class T>
std::pair<Node<T>*,T> Node<T>::delete_at_pos(int pos){
    int n = this->count(), t_pos {pos};
    std::pair<Node*,T> res;
    T deleted {};
    if(pos >= n || pos < 0){
        std::cout<<"\nInvalid position.\n";
        return std::make_pair(this,deleted);
    }
    //std::cout<<"Hi";
    Node* cur {this};
    Node* prev {nullptr};
    while(t_pos-1 >= 0){
        prev = cur;
        cur = cur->next;
        t_pos--;
    }
    deleted = cur->data;

    if(pos == 0)
        res = std::make_pair(this->next,deleted);
    else{
        res = std::make_pair(this,deleted);     
        prev->next = cur->next;
    }
    delete cur;
    cur = nullptr;

    return res;
}

template <class T>
bool Node<T>::is_sorted(){
    Node *temp {this};
    T max_item {std::numeric_limits<T>::min()};
    while(temp){
        if(temp->data < max_item)
            return false;
        max_item = temp->data;
        temp = temp->next;
    }
    return true;
}

template <class T>
void Node<T>::delete_duplicate(){
    Node *cur {this};
    if(cur == nullptr)
        return;

    Node *next {this->next};

    while(next!=nullptr){
        if(cur->data != next->data){
            cur = next;
            next = next->next;
        }
        else{
            cur->next = next->next;
            delete next;
            next = cur->next;
        }
    }
}
template <class T>
Node<T>* Node<T>::reverse_links(){
    Node *prev_to_prev {nullptr}, *prev {nullptr}, *cur {this};
    while(cur != nullptr){
        prev_to_prev = prev;
        prev = cur;
        cur = cur->next;

        prev->next = prev_to_prev; //reverse the link
    }
    return prev;
}

// template <class T>
// void Node<T>::reverse_links_recursion(Node<T> *first, Node<T> *prev, Node<T> *cur){
//     while(cur != nullptr){
//         this->reverse_links_recursion(first,cur, cur->next);
//         cur->next = prev;
//     }
//     if(cur == nullptr){
//         first = prev;
//     }
// }

int main(){
    Node<std::string> *head {nullptr};
    std::vector<std::string> arr {"Narayan","Rachit","Rachit", "TMayank", "Yogesh","ZSaket","ZSaket"};
    
    head = head->create_list(arr);
    head->display();

    // head = head->insert_at_pos(6,"Tata");
    // head->display();

    // auto p = head->delete_at_pos(-9);
    // head = p.first;
    // std::cout<<"deleted item = "<<p.second<<std::endl;
    head->delete_duplicate();
    head->display();

    head = head->reverse_links();
    head->display();

    // head->reverse_links_recursion(head,nullptr,head);
    // head->display();

    // std::cout<<"Is list sorted? : "<<std::boolalpha<<head->is_sorted()<<std::endl;
    
    // int counter = head->count();
    // std::cout<<"\nNo of element in list : "<<counter<<"\n";

    // counter = head->count_recursive(head);
    // std::cout<<"\nNo of element in list : "<<counter<<"\n";

    // head->add();
    // head->add_recursive(head);
    // head->max();
    // head->min();
    // head->max_recursive(head);
    // head->search(std::string("yogesh"));
    // head->search_recursive(head, std::string("rishabh"));
}