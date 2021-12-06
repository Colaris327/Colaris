#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "Penguin";
    string s2, s3;
    if (s1[7] == '\0')
    {
        cout << "YES";
    }
    
    // cout << "You can assign one string to another : " << endl;
    // s2 = s1;
    // cout << s2 << endl;
    // cout << "You assign a C-style string to a string object : " << endl;
    // s2 = "buzzard";
    // cout << s2 << endl;
    // cout << "You can concatenate strings : " << endl;
    // s3 = s1 + s2;
    // cout << s3 << endl;
    // s2 += " for a day.";
    // cout << s2 << endl;

    // char str[] = "animal";
    // char *ps = str;
    // cout << str << endl;
    // cout << ps;
    return 0;
}