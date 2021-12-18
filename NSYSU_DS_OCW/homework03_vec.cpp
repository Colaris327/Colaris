// knight
#include <iostream>
#include <vector>
using namespace std;

class knight
{
    public:
        int i; // vertical
        int j; // horizon
        int dir; // direction
        knight(int x, int y, int view): i(x), j(y), dir(view) {}
        knight(): i(2), j(2), dir(0) {}
        knight & operator=(const knight &);
};

template<typename T>
class STACK
{
    private:
        vector<T> array; // stack array
    public:
        STACK() {array.clear();}
        bool isEmpty() const {return array.size() == 0;}
        T Top() const;
        void Pop();
        void Push(const T & item);
};

template<typename T>
T STACK<T>::Top() const
{
    return array.back();
}

template<typename T>
void STACK<T>::Pop()
{
    array.pop_back();
}

template<typename T>
void STACK<T>::Push(const T & item)
{
    array.push_back(item);
}

knight & knight::operator=(const knight & A)
{
    this->i = A.i;
    this->j = A.j;
    this->dir = A.dir;
    return *this;
}

int ** CreatBoard(int size)
{
    int **array = new int*[size + 4]; // +4 is for boundary
    for (int i = 0; i < size + 4; i++)
        array[i] = new int[size + 4];
    for (int i = 0; i < size + 4; i++)
        for (int j = 0; j < size + 4; j++)
            array[i][j] = 1;
    for (int i = 2; i < size + 2; i++)
        for (int j = 2; j < size + 2; j++)
            array[i][j] = 0;
    return array;
}

void PrintBoard(int **arr, int size)
{
    for (int i = 2; i < size + 2; i++)
    {
        for (int j = 2; j < size + 2; j++)
        {
            cout.width(3);
            cout << arr[i][j];
        }
        cout << endl;
    }        
}

int main()
{
    for (int size = 1; size <= 6; size++)
    {
        int **board = CreatBoard(size);
        STACK<knight> Kstack;
        knight K;
        int step = 1;
        board[K.i][K.j] = step;

        while (true)
        {
            if (step == size * size)
            {
                PrintBoard(board, size);
                break;
            }

            if (board[K.i - 2][K.j + 1] == 0 && K.dir < 1)
            {
                board[K.i - 2][K.j + 1] = ++step;
                Kstack.Push(knight(K.i, K.j, 1));
                K.dir = 0;
                K.i = K.i - 2;
                K.j = K.j + 1;
            }
            else if (board[K.i - 1][K.j + 2] == 0 && K.dir < 2)
            {
                board[K.i - 1][K.j + 2] = ++step;
                Kstack.Push(knight(K.i, K.j, 2));
                K.dir = 0;
                K.i = K.i - 1;
                K.j = K.j + 2;
            }
            else if (board[K.i + 1][K.j + 2] == 0 && K.dir < 3)
            {
                board[K.i + 1][K.j + 2] = ++step;
                Kstack.Push(knight(K.i, K.j, 3));
                K.dir = 0;
                K.i = K.i + 1;
                K.j = K.j + 2;
            }
            else if (board[K.i + 2][K.j + 1] == 0 && K.dir < 4)
            {
                board[K.i + 2][K.j + 1] = ++step;
                Kstack.Push(knight(K.i, K.j, 4));
                K.dir = 0;
                K.i = K.i + 2;
                K.j = K.j + 1;
            }
            else if (board[K.i + 2][K.j - 1] == 0 && K.dir < 5)
            {
                board[K.i + 2][K.j - 1] = ++step;
                Kstack.Push(knight(K.i, K.j, 5));
                K.dir = 0;
                K.i = K.i + 2;
                K.j = K.j - 1;
            }
            else if (board[K.i + 1][K.j - 2] == 0 && K.dir < 6)
            {
                board[K.i + 1][K.j - 2] = ++step;
                Kstack.Push(knight(K.i, K.j, 6));
                K.dir = 0;
                K.i = K.i + 1;
                K.j = K.j - 2;
            }
            else if (board[K.i - 1][K.j - 2] == 0 && K.dir < 7)
            {
                board[K.i - 1][K.j - 2] = ++step;
                Kstack.Push(knight(K.i, K.j, 7));
                K.dir = 0;
                K.i = K.i - 1;
                K.j = K.j - 2;
            }
            else if (board[K.i - 2][K.j - 1] == 0 && K.dir < 8)
            {
                board[K.i - 2][K.j - 1] = ++step;
                Kstack.Push(knight(K.i, K.j, 8));
                K.dir = 0;
                K.i = K.i - 2;
                K.j = K.j - 1;
            }
            else if (!Kstack.isEmpty())
            {
                board[K.i][K.j] = 0;
                K = Kstack.Top();
                Kstack.Pop();
                step--;
            }
            else if (Kstack.isEmpty())
            {
                cout << "no solution" << endl;
                break;
            }
        }
    }
    return 0;
}