#include<iostream>
#include<string>
using namespace std;

void test01(){
    string s1("asdasd");
    string s2(10, 'f');
    try{
        for (int i = 0; i <= s1.size(); i++){
            cout << s1.at(i) << " ";
        }
        cout << endl;
    }catch(...){
        cout << "out of range!" << endl;
    }

    s2 += 'a';
    s2 += "asfa";
    s2.append(s1, 2, 3);
    cout << s2 << endl;
    
}

int main(){
    test01();
}