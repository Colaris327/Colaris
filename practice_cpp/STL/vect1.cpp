// page 603
#include <iostream>
#include <string>
#include <vector>
const int NUM = 5;

int main()
{
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<int> rating (NUM);
    vector<string> titles (NUM);
    cout << "You will do exactly as told. You will enter\n"
        << NUM << " book titles and your rating (0-10).\n";
    int i;
    for ( i = 0; i < NUM; i++)
    {
        cout << "Enter title #" << i + 1 << ": ";
        getline(cin, titles[i]);
        cout << "Enter your rating: ";
        cin >> rating[i];
        cin.get();
    }
    cout << "Thank you. Ypu enter the following:\n"
        << "Rating\tBook\n";
    for (i = 0; i < NUM; i++)
    {
        cout << rating[i] << "\t" << titles[i] << endl;
    }
    return 0;
}