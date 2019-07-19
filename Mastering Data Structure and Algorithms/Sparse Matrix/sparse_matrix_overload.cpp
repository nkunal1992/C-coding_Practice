#include <bits/stdc++.h>

class Element{
public:
    int i;
    int j;
    int value;
};

class Sparse{
    int m; //row no
    int n; //column no
    int num; // No of non-zero element
    Element *ele;
public:
    Sparse(int row, int column, int n)
        : m {row}, n {column}, num {n}, ele {new Element [n]} {}
    ~Sparse(){
        delete [] ele;
    }
    
    friend std::istream& operator >>(std::istream &is, Sparse &s);
    friend std::ostream& operator <<(std::ostream &os, Sparse &s);

    Sparse operator +(Sparse &s);
};

Sparse Sparse::operator+(Sparse &s){
    int i {0}, j {0}, k {0};
    if(m!=s.m || n!=s.n) return Sparse(0,0,0);

    Sparse *sum = new Sparse(m,n,num+s.num);
    while(i<num && j<s.num){
        if(ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if(ele[i].i > s.ele[j].i)
            sum->ele[k++] = s.ele[j++];
        else{
            if(ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if(ele[i].j > s.ele[j].j)
                sum->ele[k++] = s.ele[j++];
            else 
                sum->ele[k] = ele[i];
                sum->ele[k++].value = ele[i++].value + s.ele[j++].value;
        }
    }

    for(; i<num; i++) sum->ele[k++] = ele[i];
    for(; j<s.num; j++) sum->ele[k++] = s.ele[j];

    return *sum;
}

std::istream& operator >>(std::istream &is, Sparse &s){
    std::cout<<"Enter non-zero elements(row,col,value)\n";
    for(int i {0}; i<s.num; i++)
        is>>s.ele[i].i>>s.ele[i].j>>s.ele[i].value;

    return is;
}

std::ostream& operator <<(std::ostream &os, Sparse &s){
    int k {0};
    for(int i {0}; i<s.m; i++){
        for(int j {0}; j<s.n; j++){
            if(s.ele[k].i == i && s.ele[k].j == j)
                os<<s.ele[k++].value<<" ";
            else 
                os<<"0 ";
        }
        os<<'\n';
    }
    return os;
}

int main(){
    Sparse s1(5,5,5);
    Sparse s2(6,5,5);
    std::cin>>s1;
    std::cin>>s2;

    Sparse sum = s1+s2;
    std::cout<<"First Matrix\n"<<s1;
    std::cout<<"\nSecond Matrix\n"<<s2;
    std::cout<<"\nSum Matrix\n"<<sum;
}