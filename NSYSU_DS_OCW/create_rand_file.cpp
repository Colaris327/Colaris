#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

int CreateRand(int range)
{
    return rand() % range;
}

int main()
{
    ofstream ofile;
    srand(time(0));
    ofile.open("input.txt", ios::out);
    vector<int> scale = {100};

    for (auto i : scale)
    {
        ofile << i << endl;
        for (int j = 0; j < i; j++)
            ofile << CreateRand(i) << endl;
    }
    ofile.close();
    return 0;
}