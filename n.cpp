#include <iostream>

using namespace std;


typedef int item;

class Stack{
    private:
        item* stack;
        int p;
    public:
        // Constructs a stack of the given size (defaults to 100)
        Stack(int max = 100)
        {
            stack = new item[max];
            p = 0;
        }
        ~Stack()
        {
            delete[] stack;
        }

        // Add node v to the next key in the stack
        void push(item v)
        {
            stack[p++] = v;
        }

        // Get the last item from the stack
        item pop()
        {
            return stack[--p];
        }

        // Return true if p < 1, and false if p > 1
        int empty()
        {
            return !p;
        }
};

int main()
{
    Stack stack;

    int n = 10;
    stack.push(n);

    for(n = n-1; n>0; n--)
    {
        stack.push(stack.pop()*n);
    }

    cout << stack.pop();
}
