#include <iostream>
using namespace std;

struct sysop
{
    char name[26];
    char quote[64];
    int used;
};

const sysop & use(sysop & sysopref); // function with a reference return type

int main()
{
    sysop looper = {"Rick", "I'm a goto kind of guy"};
    use(looper);
    cout << "Looper: " << looper.used << " use(s)" << endl;
    sysop copycat;
    copycat = use(looper);
    cout << "Looper: " << looper.used << " use(s)" << endl;
    cout << "Copycat: " << copycat.used << " use(s)" << endl;
    cout << "use(looper): " << use(looper).used << " use(s)\n";
    return 0;
}


const sysop & use(sysop & sysopref)
{
    cout << sysopref.name << " says:\n";
    cout << sysopref.quote << endl;
    sysopref.used++;
    return sysopref;
}