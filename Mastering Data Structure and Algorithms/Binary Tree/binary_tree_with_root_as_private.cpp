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
    Node *root;
public:
    Tree()
        : root {nullptr} {}
    void create();
    void preorder(){ preorder(root); }
    void postorder(){ postorder(root); }
    void inorder(){ inorder(root); }
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    void levelorder(Node *p);
    void height(Node *p);
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
        std::cin>>x;

        if(x!=-1){
            new_node = new Node(x);
            cur_node->lchild = new_node;
            q.push(new_node);
        }

        std::cout<<"Enter right child of "<<cur_node->data<<"\n";
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

int main(){
    Tree t1;
    t1.create();
    std::cout<<"Preorder : ";
    t1.preorder();
    std::cout<<"\nInorder : ";
    t1.inorder();
    std::cout<<"\nPostorder : ";
    t1.postorder();
    std::cout<<"\n";
}