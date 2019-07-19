#include <bits/stdc++.h>

class Node{
public:
    int data;
    int height;
    Node *lchild;
    Node *rchild;
    

    Node(int key)
        : lchild {nullptr}, data {key}, rchild {nullptr}, height{1} {}
    ~Node()=default;
};

class AVL_Tree{
public:
    Node *root;
    AVL_Tree()
        : root {nullptr} {}
    Node* LL_Rotation(Node *p);
    Node* LR_Rotation(Node *p);
    Node* RR_Rotation(Node *p);
    Node* RL_Rotation(Node *p);
    Node* rinsert(Node *p,int key);
    void levelorder(Node *p);
    void Ipreorder(); //iterative preorder
    void Iinorder(); //iterative inorder
    void Ipostorder(); //iterative postorder
    Node* Inorder_Predecessor(Node *p);
    Node* Inorder_Successor(Node *p);
    int Nodeheight(Node *p);
    int bf(Node *p); //balance factor calculation
    Node* Delete(Node *p, int key);
};

Node* AVL_Tree::LL_Rotation(Node *p){
    Node *left {p->lchild};
    p->lchild = left->rchild;
    left->rchild = p;

    p->height = Nodeheight(p);
    left->height = Nodeheight(left);
    if(root == p)
        root = left;
    return left;
}

Node* AVL_Tree::LR_Rotation(Node *p){
    Node *plr {p->lchild->rchild};

    p->lchild->rchild = plr->lchild;
    plr->lchild = p->lchild;

    p->lchild = plr->rchild;
    plr->rchild = p;

    plr->lchild->height = Nodeheight(plr->lchild);
    plr->rchild->height = Nodeheight(plr->rchild);
    plr->height = Nodeheight(plr);

    if(root == p)
        root = plr;

    return plr;
}

Node* AVL_Tree::RL_Rotation(Node *p){
    Node *prl {p->rchild->lchild};

    p->rchild->lchild = prl->rchild;
    prl->rchild = p->rchild;

    p->rchild = prl->lchild;
    prl->lchild = p;

    prl->lchild->height = Nodeheight(prl->lchild);
    prl->rchild->height = Nodeheight(prl->rchild);
    prl->height = Nodeheight(prl);

    if(root == p)
        root = prl;

    return prl;
}

Node* AVL_Tree::RR_Rotation(Node *p){
    Node *pr {p->rchild};

    p->rchild = pr->lchild;
    pr->lchild = p;

    pr->lchild->height = Nodeheight(pr->lchild);
    pr->height = Nodeheight(pr);

    if(p == root)
        root = pr;

    return pr;
}

Node* AVL_Tree::rinsert(Node *p, int key){
    if(p == nullptr){
        p = new Node(key);
        return p;
    }
    if(p->data == key) return p;
    else if(key < p->data)
        p->lchild = rinsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = rinsert(p->rchild, key);

    p->height = Nodeheight(p); //updating height of each node

    //check balance factor and rotate accordingly
    if(bf(p) == 2 && bf(p->lchild) == 1) //LL rotation
        return LL_Rotation(p);
    else if(bf(p) == 2 && bf(p->lchild) == -1) //LR rotation
        return LR_Rotation(p);
    else if(bf(p) == -2 && bf(p->rchild) == 1) //LR rotation
        return RL_Rotation(p);
    else if(bf(p) == -2 && bf(p->rchild) == -1) //RR rotation
        return RR_Rotation(p);

    return p;
}

Node* AVL_Tree::Delete(Node *p, int key){
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
        if(p->lchild->height > p->rchild->height){
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

    p->height = Nodeheight(p); //update height

    if(bf(p) == 2 && bf(p->lchild) == 1)
        return LL_Rotation(p);
    else if(bf(p) == 2 && bf(p->lchild) == -1)
        return LR_Rotation(p);
    else if(bf(p) == 2 && bf(p->lchild) == 0)
        return LL_Rotation(p); //we can perform LR_Rotation also
    else if(bf(p) == -2 && bf(p->rchild) == -1)
        return RR_Rotation(p);
    else if(bf(p) == -2 && bf(p->rchild) == 1)
        return RL_Rotation(p);

    return p;
}

void AVL_Tree::levelorder(Node *p){
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

void AVL_Tree::Ipreorder(){
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

void AVL_Tree::Iinorder(){
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

void AVL_Tree::Ipostorder(){
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

Node* AVL_Tree::Inorder_Predecessor(Node *p){
    Node *temp {p};
    if(temp == nullptr || temp->lchild == nullptr) return temp;

    temp = temp->lchild; //left subAVL_Tree

    while(temp->rchild){
        temp = temp->rchild;
    }
    return temp;
}

Node* AVL_Tree::Inorder_Successor(Node *p){
    Node *temp {p};
    if(temp == nullptr || temp->rchild == nullptr) return temp;

    temp = temp->rchild; //right subAVL_Tree

    while(temp->lchild){
        temp = temp->lchild;
    }
    return temp;
}

int AVL_Tree::Nodeheight(Node *p){
    int lh {0}, rh {0};

    lh = p && p->lchild? p->lchild->height:0;
    rh = p && p->rchild? p->rchild->height:0;

    return lh>rh? lh+1:rh+1;
}

int AVL_Tree::bf(Node *p){
    int lh {0}, rh {0};

    lh = p && p->lchild? p->lchild->height:0;
    rh = p && p->rchild? p->rchild->height:0;

    return lh-rh;
}

int main(){
    AVL_Tree t1;
    std::vector<int> arr {9,5,10,0,6,11,-1,1,2};//63, 9, 19, 27, 18, 108, 99, 81
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
    t1.root = t1.Delete(t1.root,10);
    std::cout<<"\n\n-------After deleting---------\n";
    std::cout<<"\nLevel order : ";
    t1.levelorder(t1.root);
    std::cout<<"\nPre order : ";
    t1.Ipreorder();
    std::cout<<"\nIn order : ";
    t1.Iinorder();
    std::cout<<"\nPost order : ";
    t1.Ipostorder();
    std::cout<<"\n\n";
}