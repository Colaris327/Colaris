#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using namespace std;
    Item po;
    Stack st;
    char ch;
    cout << "Please enter A to add a purchase order, \n"
        << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                cin >> po;
                if(st.isFull())
                    cout << "Stack already full.\n";
                else
                    st.push(po);
                break;
            
            case 'p':
            case 'P': if (st.isEmpty())
                        cout << "Stack already empty\n";
                    else
                    {
                        st.pop(po);
                        cout << "PO #" << po << " popped.\n";
                    }
                    break;
        }
        cout << "Please enter A to add a purchase order, \n"
            << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye.\n";
    return 0;
}