#include <iostream>
#include <cmath>
#include "Objects/box.h"

using namespace std;

int main(){
    box package;
    package.height = int{};
    package.width = int{};
    package.length = int{};

    cout << "input the height: ";
    cin >> package.height;
    cout << endl;

    cout << "input the width: ";
    cin >> package.width;
    cout << endl;

    cout << "input the length: ";
    cin >> package.length;
    cout << endl;

    cout << "The volume is " << package.volume(package.length, package.width, package.height) << endl;
    
    int squaredHeight = pow(package.height, 2);
    cout << squaredHeight << endl;
    cout << sqrt(squaredHeight) << endl;
    return 0;
}