#include <bits/stdc++.h>
using namespace std;

void process(string filename){
    ifstream in;
    in.open(filename);

    string line; //to read each line from file
    string fname,lname,rollNo;
    float cgpa;

    while(getline(in,line)){
        stringstream info {line} ,out;
        info>>fname>>lname>>rollNo>>cgpa;
        out<<fname<<" "<<lname<<" "<<rollNo<<" "<<cgpa
        ;
        cout<<out.str()<<endl;
    }
}

int main(){
    string filename {"test.txt"};
    process(filename);
}