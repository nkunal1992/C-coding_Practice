#include <bits/stdc++.h>

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;

    Node()
        : lchild {nullptr}, rchild {nullptr} {}
    Node(int key)
        : lchild {nullptr}, data {key}, rchild {nullptr} {}
    ~Node()=default;
};

class Tree{
public:
    Node *root;
    Tree()
        : root {nullptr} {}
    void insert(int key);
    Node* rinsert(Node *p,int key);
    void levelorder(Node *p);
    void Ipreorder(); //iterative preorder
    void Iinorder(); //iterative inorder
    void Ipostorder(); //iterative postorder
    Node* Inorder_Predecessor(Node *p);
    Node* Inorder_Successor(Node *p);
    int height(Node *p);
    Node* Delete(Node *p, int key);
    void create_bst_from_preorder(std::vector<int> arr);
};

void Tree::insert(int key){
    if(root == nullptr){
        root = new Node(key);
        return;
    }
    Node *temp {root},*parent {nullptr};

    while(temp){
        if(key == temp->data)
            return;
        else if(key < temp->data){
            parent = temp;
            temp = temp->lchild;
        }
        else{
            parent = temp;
            temp = temp->rchild;
        }
    }
    if(key < parent->data)
        parent->lchild = new Node(key);
    else 
        parent->rchild = new Node(key);
}

Node* Tree::rinsert(Node *p, int key){
    if(p == nullptr){
        p = new Node(key);
        return p;
    }
    if(p->data == key) return p;
    else if(key < p->data)
        p->lchild = rinsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = rinsert(p->rchild, key);

    return p;
}

void Tree::levelorder(Node *p){
    std::queue<Node *> q;
    if(p){
        std::cout<<p->data<<" ";
        q.push(p);
    }
    while(!q.empty()){
        p = q.front(); q.pop();
        
        if(p->lchild){
            std::cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild){
            std::cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }
}

void Tree::Ipreorder(){
    std::stack<Node *> s;
    Node *temp {root};
    while(temp || !s.empty()){
        if(temp != nullptr){
            std::cout<<temp->data<<" ";
            s.push(temp);
            temp = temp->lchild;
        }
        else{
            temp = s.top(); s.pop();
            temp = temp->rchild;
        }
    }
}

void Tree::Iinorder(){
    std::stack<Node *> s;
    Node *temp {root};
    while(temp || !s.empty()){
        if(temp != nullptr){
            s.push(temp);
            temp = temp->lchild;
        }
        else{
            temp = s.top(); s.pop();
            std::cout<<temp->data<<" ";
            temp = temp->rchild;
        }
    }
}

void Tree::Ipostorder(){
    std::stack<intptr_t> s;
    Node *temp {root};
    while(temp || !s.empty()){
        if(temp != nullptr){
            s.push(reinterpret_cast<intptr_t>(temp));
            temp = temp->lchild;
        }
        else{
            intptr_t t = s.top(); s.pop();
            if(t > 0){
                s.push(-t);
                temp = reinterpret_cast<Node *>(t)->rchild; //typecast to Node* and assign
            }
            else{ // it's for printing 
                std::cout<<reinterpret_cast<Node *>(-t)->data<<" ";
                temp = nullptr;
            }
        }
    }
}

Node* Tree::Inorder_Predecessor(Node *p){
    Node *temp {p};
    if(temp == nullptr || temp->lchild == nullptr) return temp;

    temp = temp->lchild; //left subtree

    while(temp->rchild){
        temp = temp->rchild;
    }
    return temp;
}

Node* Tree::Inorder_Successor(Node *p){
    Node *temp {p};
    if(temp == nullptr || temp->rchild == nullptr) return temp;

    temp = temp->rchild; //right subtree

    while(temp->lchild){
        temp = temp->lchild;
    }
    return temp;
}

int Tree::height(Node *p){
    int lh {0}, rh {0};
    if(!p)
        return 0;
    
    lh = height(p->lchild);
    rh = height(p->rchild);

    if(lh > rh)
        return lh+1;
    else 
        return rh+1;
}

Node* Tree::Delete(Node *p, int key){
    if(p == nullptr) return p; //if tree doesn't exist
    if(!p->lchild && !p->rchild){
        if(p == root)
            root = nullptr;
        delete p;
        return nullptr;
    }
    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else{
        //found node has one child
        if(p->lchild == nullptr){ //only right child or no child
            Node *temp = p->rchild;
            delete p;
            return temp;
        }
        if(p->rchild == nullptr){ //only left child or no child
            Node *temp = p->lchild;
            delete p;
            return temp;
        }
        if(height(p->lchild) > height(p->rchild)){
            Node *temp = Inorder_Predecessor(p);
            p->data = temp->data;
            p->lchild = Delete(p->lchild, temp->data);
        }
        else{
            Node *temp = Inorder_Successor(p);
            p->data = temp->data;
            p->rchild = Delete(p->rchild, temp->data);
        }
    }
    return p;
}

void Tree::create_bst_from_preorder(std::vector<int> arr){
    int n {static_cast<int>(arr.size())}, i {0};
    if(n == 0) return;
    std::stack<Node *> s;
    Node *new_node, *cur;

    root = new Node(arr[i++]);
    cur = root;
    while(i<n){
        if(arr[i] < cur->data){
            new_node = new Node(arr[i++]);
            cur->lchild = new_node;
            s.push(cur);
            cur = new_node;
        }
        else
        {
            int top = s.empty()?INT_MAX:s.top()->data;
            if(arr[i] > cur->data && arr[i] < top){
                new_node = new Node(arr[i++]);
                cur->rchild = new_node;
                cur = new_node;
            }
            else{
                cur = s.top();
                s.pop();
            }
        }  
    }
}

int main(){
    Tree t1;
    std::vector<int> arr {7,4,12,2,6,9,19,3,5,8,11,15,20 };
    for(auto i {0}; i<arr.size(); i++)
        t1.root = t1.rinsert(t1.root, arr[i]);
        //t1.insert(arr[i]);

    std::cout<<"\nLevel order : ";
    t1.levelorder(t1.root);
    std::cout<<"\nPre order : ";
    t1.Ipreorder();
    std::cout<<"\nIn order : ";
    t1.Iinorder();
    std::cout<<"\nPost order : ";
    t1.Ipostorder();
    Node *t = t1.Inorder_Predecessor(t1.root);
    std::cout<<"\nInorder Predecessor of "<<t1.root->data<<" : "<<t->data;
    t = t1.Inorder_Successor(t1.root);
    std::cout<<"\nInorder Successor of "<<t1.root->data<<" : "<<t->data;
    t = t1.Delete(t1.root, 40);
    if(t==nullptr)
        std::cout<<"\nElement doesn't exist\n";
    else{
        t1.root = t;
        std::cout<<"\nLevel order : ";
        t1.levelorder(t1.root);
    }

    Tree t2;
    std::vector<int> arr1 {7, 4,2, 3, 6, 5, 12,9, 8, 11,19,15,20};
    t2.create_bst_from_preorder(arr1);
    std::cout<<"\n\nLevel order : ";
    t2.levelorder(t2.root);
    std::cout<<"\nPre order : ";
    t2.Ipreorder();
    std::cout<<"\nIn order : ";
    t2.Iinorder();
    std::cout<<"\nPost order : ";
    t2.Ipostorder();
    t = t2.Inorder_Predecessor(t2.root);
    std::cout<<"\nInorder Predecessor of "<<t2.root->data<<" : "<<t->data;
    t = t2.Inorder_Successor(t2.root);
    std::cout<<"\nInorder Successor of "<<t2.root->data<<" : "<<t->data;
    t = t2.Delete(t2.root, 4);
    if(t==nullptr)
        std::cout<<"\nElement doesn't exist\n";
    else{
        t2.root = t;
        std::cout<<"\nLevel order : ";
        t2.levelorder(t2.root);
    }
    std::cout<<"\n\n";
}