#include <iostream>
#include <map>
using namespace std;

//map

void test01(){
    map<int, int> m;

// insert
    pair<map<int, int>::iterator, bool> ret = m.insert(make_pair(3, 5));
    cout << ret.second << endl;

    auto r = m.insert(pair<int, int>(7, 11));
    cout << ret.second << endl;

    m.insert(map<int, int>::value_type(30, 30));

    //通过[]访问map，若存在则覆盖，不存在则创建
    m[11] = 13;
    m[11] = 14;
    for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++){
        cout << iter->first << ": " << iter->second << endl;
    }

    cout << endl <<  m[88] << endl << endl;

    for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++){
        cout << iter->first << ": " << iter->second << endl;
    }
}

int main(){
    test01();
    return 0;
}