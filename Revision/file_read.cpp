#include <bits/stdc++.h>
using namespace std;

void operation(string filename){
    ifstream in_file;
    in_file.open(filename);
    string line {};
    vector<string> tokens; //to store all tokens
    string token; //to store intermediate token
    
    while(getline(in_file,line)){
        //tokenization using stringstream class
        stringstream tokenize (line);
        while(getline(tokenize,token,' '))
            tokens.push_back(token);
        //cout<<line<<'\n';
    }
    in_file.close();

    for(const auto &token:tokens)
        cout<<token<<endl;
}

int main(){
    string filename {"test.txt"};
    operation(filename);
}