// page 620
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    string s1[4] = {"fine", "fish", "fashion", "fate"};
    string s2[2] = {"busy", "bats"};
    string s3[2] = {"silly", "singers"};
    vector<string> words (4);
    copy(s1, s1 + 4, words.begin());
    ostream_iterator<string, char> out (cout, " ");
    copy(words.begin(), words.end(), out);
    cout << endl;

    // construct anonymous back_insert_iterator object
    copy(s2, s2 + 2, back_insert_iterator< vector<string> > (words));
    copy(words.begin(), words.end(), out);
    cout << endl;

    // construct anonymous insert_iterator object
    copy(s3, s3 + 2, insert_iterator< vector<string> > (words, words.begin()));
    copy(words.begin(), words.end(), out);
    cout << endl;

    return 0;
}