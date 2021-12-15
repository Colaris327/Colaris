// page 484
// compile with student.cpp
#include "studentc.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
    int i;
    for (i = 0; i < pupils; i++)
        set(ada[i], quizzes);
    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; i++)
        cout << ada[i].Name();
    cout << "\nResults:";
    for (i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done\n";
    return 0;
}

void set(Student & sa, int n)
{
    cout << "Enter the student's name: ";
    getline(cin, sa);
    cout << "Enter " << n << " quiz scores: ";
    for (int i = 0; i < n; i++)
    {
        cin >> sa[i];
    }
    while (cin.get() != '\n')
        continue;
}