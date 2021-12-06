#include <iostream>
#include <climits>
using namespace std;

int main(){
    int rats = 101;
    int *pt = &rats;
    int & rodents = *pt;
    int bunnies = 50;
    pt =  &bunnies;

    cout << rodents;
    cout << rats;
    return 0;
}