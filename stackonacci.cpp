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

    stack.push(1);
    stack.push(1);


    for(int i=0; i<5; i++)
    {
        int previous  = stack.pop();
        stack.push(previous ^ stack.pop() );

        stack.push((stack.pop() ^ previous) + previous);

        int c = stack.pop();
        stack.push(c);
        cout << c << "\n";

    }

}
