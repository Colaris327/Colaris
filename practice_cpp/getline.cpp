#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    const int ArSize = 20;
    char name[ArSize];
    string dessert;

    cout << "Enter your name : ";
    cin.getline(name, ArSize);
    cout << "Enter your favorite dessert : ";
    getline(cin, dessert);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name;


    return 0;
}