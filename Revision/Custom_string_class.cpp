#include <bits/stdc++.h>
using namespace std;

class String{
    friend ostream &operator << (ostream &os, const String &obj);
    friend istream &operator >> (istream &is, String &obj);
    char *str;
public:
    String() //default constructor
        : str {nullptr} {
            str = new char[1];
            str[0] = '\0';
    }
    String(const char *s) //Overloaded constructor
        : str {nullptr} {
            str = new char[strlen(s)+1];
            strcpy(str,s);
    }
    String(const String &obj) //Copy Constructor
        : str {nullptr} {
            str = new char[strlen(obj.str)+1];
            strcpy(str,obj.str);
    }
    String(String &&obj) //Move Constructor
        : str (obj.str) {
            obj.str = nullptr;
    }
    //Copy assignment
    String &operator = (const String &rhs){
        if(this == &rhs) //self assignment check
            return *this;
        delete [] str; //delete as we will overwrite it
        str = new char[strlen(rhs.str)+1];
        strcpy(str,rhs.str);
        return *this;
    } 
    //Move assignment
    String &operator = (String &&rhs){
        if(this == &rhs)
            return *this;
        delete [] str; //deallocate current storage
        str = rhs.str; //steal the pointer

        rhs.str = nullptr; //nullout the rhs object

        return  *this;
    }
    String operator + (const String &rhs) const{
        char *buff = new char[strlen(str)+strlen(rhs.str)+1];
        strcpy(buff,str);
        strcat(buff,rhs.str);

        String temp {buff};
        delete [] buff;
        return temp;
    }
    bool operator == (const String &rhs){
        if(strcmp(str,rhs.str) == 0)
            return true;
        else 
            return false;
    }
    bool operator < (const String &rhs){
        if(strcmp(str,rhs.str) < 0)
            return true;
        else 
            return false;
    }
    bool operator <= (const String &rhs){
        if(strcmp(str,rhs.str) <= 0)
            return true;
        else 
            return false;
    }
    bool operator > (const String &rhs){
        if(strcmp(str,rhs.str) > 0)
            return true;
        else 
            return false;
    }
    bool operator >= (const String &rhs){
        if(strcmp(str,rhs.str) >= 0)
            return true;
        else 
            return false;
    }
    bool operator != (const String &rhs){
        if(strcmp(str,rhs.str) != 0)
            return true;
        else 
            return false;
    }
    int length(){
        return strlen(str);
    }
};

ostream &operator << (ostream &os, const String &obj){
    os<<obj.str;
    return os;
}

istream &operator >> (istream &is, String &obj){
    char *buff = new char[1000];
    is>>buff;

    obj = String {buff};
    delete [] buff;
    return is;
}
int main(){
    String s1;
    cin>>s1;
    cout<<s1<<" Length : "<<s1.length()<<endl;
    String s2;
    cin>>s2;
    cout<<"s1==s2 :"<<boolalpha<<(s1==s2)<<"\ns1<s2 :"<<(s1<s2)<<endl;
}