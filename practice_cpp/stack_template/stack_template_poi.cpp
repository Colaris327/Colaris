// page 516
// test stock of pointer
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stack_template_poi.h"
const int Num = 10;

int main()
{
    std::cout << "Enter the stack size: ";
    int stacksize;
    std::cin >> stacksize;
    Stack<const char *> st (stacksize);
    std::srand(std::time(0));

    const char *in[Num] = {
        " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
        " 3: Betty Rocker", " 4: Ian Flagranti",
        " 5: Wolfgang Kibble", " 6: Portia Koop",
        " 7: Joy Almondo", " 8: Xaverie Paprika",
        " 9: Juan Moore", " 10: Misha Mache"
    };

    const char *out[Num];
    int processed = 0;
    int nextin = 0;
    while (processed < Num)
    {
        if (st.isEmpty())
            st.push(in[nextin++]);
        else if (st.isFull())
            st.pop(out[processed++]);
        else if (std::rand() % 2 && nextin < Num) // 50-50 chance
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    for (int i = 0; i < Num; i++)
        std::cout << out[i] << std::endl;
    return 0;
}