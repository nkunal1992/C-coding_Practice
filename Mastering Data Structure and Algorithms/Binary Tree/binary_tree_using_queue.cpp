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
    void create();
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    void Ipreorder(); //iterative preorder
    void Iinorder(); //iterative inorder
    void Ipostorder(); //iterative postorder
    void levelorder(Node *p);
    int count(Node *p);
    int height(Node *p);
    int leaf(Node *p);
};

void Tree::create(){
    Node *cur_node, *new_node;
    int x;
    std::queue<Node *> q;

    std::cout<<"Enter root data\n";
    std::cin>>x;

    root = new Node(x);
    q.push(root);

    while(!q.empty()){
        cur_node = q.front(); q.pop();
        
        std::cout<<"Enter left child of "<<cur_node->data<<"\n";
        std::cout<<"{\"If no child, enter -1\"}\n";
        std::cin>>x;

        if(x!=-1){
            new_node = new Node(x);
            cur_node->lchild = new_node;
            q.push(new_node);
        }

        std::cout<<"Enter right child of "<<cur_node->data<<"\n";
        std::cout<<"{\"If no child, enter -1\"}\n";
        std::cin>>x;

        if(x!=-1){
            new_node = new Node(x);
            cur_node->rchild = new_node;
            q.push(new_node);
        }        
    }
}

void Tree::preorder(Node *p){
    if(p)
        std::cout<<p->data<<" ";
    if(p->lchild)
        preorder(p->lchild);
    if(p->rchild)
        preorder(p->rchild);
}

void Tree::postorder(Node *p){
    if(p->lchild)
        preorder(p->lchild);
    if(p->rchild)
        preorder(p->rchild);
    if(p)
    std::cout<<p->data<<" ";
}

void Tree::inorder(Node *p){
    if(p->lchild)
        preorder(p->lchild);
    if(p)
        std::cout<<p->data<<" ";
    if(p->rchild)
        preorder(p->rchild);
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

int Tree::count(Node *p){
    if(p)
        return count(p->lchild)+count(p->rchild)+1;
    return 0;
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


int Tree::leaf(Node *p){
    if(!p)
        return 0;
    if(!p->lchild && !p->rchild)
        return 1;

    return leaf(p->lchild)+leaf(p->rchild);
}

int main(){
    Tree t1;
    t1.create();
    std::cout<<"Preorder : ";
    // t1.preorder(t1.root);
    t1.Ipreorder();
    std::cout<<"\nInorder : ";
    // t1.inorder(t1.root);
    t1.Iinorder();
    std::cout<<"\nPostorder : ";
    // t1.postorder(t1.root);
    t1.Ipostorder();
    std::cout<<"\nLevelorder : ";
    t1.levelorder(t1.root);
    std::cout<<"\nCount : "<<t1.count(t1.root);
    std::cout<<"\nHeight : "<<t1.height(t1.root);
    std::cout<<"\nLeaf count : "<<t1.leaf(t1.root);
    std::cout<<"\n";
}