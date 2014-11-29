#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

struct node{
    char info;
    node* left;
    node* right;
    bool visited;

    node()
    {
        visited = false;
    };
};

typedef node* item;

item z;

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

item create_tree()
{
    item x;
    char c;

    // Create a stack of size 50
    Stack stack(50);

    // Set up a null-node
    z = new node;
    z->left = z;
    z->right = z;

    while((c = cin.get()) != '\n')
    {
        while(c == ' ')
            cin.get(c);

        // Set up a new node x with value received from cin to c
        x = new node();
        x->info = c;

        // Set leaves to be null
        x->left = z;
        x->right = z;

        // If this node is an operator, pop from stack and set as leaves
        if(c == '*' || c == '+' || c == '-' || c == '^' || c == '/')
        {
            x->right = stack.pop();
            x->left = stack.pop();
        }

        // Push node x onto the stack and keep going
        stack.push(x);

    }

    // Return the last value pushed to the stack
    return stack.pop();
}


void visit(item t)
{
    cout << "\nVisited node with value: " << t->info;
    t->visited = true;

}

void postorder_traverse(item t)
{
    // Set up a new stack
    Stack stack(50);

    // Push t onto the new stack
    stack.push(t);

    while(!stack.empty())
    {
        t = stack.pop();
        if(t->visited)
        {
            t->visited = false;
            cout << "\n" << t->info << " was visited, set to false.";
        }
        else{
            cout << "\n" << t->info << " set to visited and pushed back onto stack.";
            visit(t);
            stack.push(t);
            cout << "\n";
            if(t->right != z)
            {
                stack.push(t->right);
                cout << "\tRight-leaf found, pushed back on stack: " << t->right->info << "\n";
            }
            if(t->left != z)
            {
                cout << "\tLeft-leaf found, pushed back on stack: " << t->left->info << "\n";
                stack.push(t->left);
            }
        }
    }
}


void preorder_recurse(item t)
{
    if(t == z)
        return;

    visit(t);
    preorder_recurse(t->left);
    preorder_recurse(t->right);
}

void postorder_recurse(item t)
{
    if(t == z)
        return;

    postorder_recurse(t->left);
    postorder_recurse(t->right);
    visit(t);
}

void change_content(item t)
{
    if(t == z)
        return;
    cout << "\nChange content of " << t->info << " to number: ";
    cin >> t->info;
    cin.ignore(1000,'\n');
}

int inorder_recurse(item t)
{
    if(t == z)
        return 0;

    int c = 0;

    if(t->info != '*' && t->info != '+')
        change_content(t);

    //inorder_recurse(t->left);
    visit(t);
    //inorder_recurse(t->right);

    if(t->info == '*')
        return inorder_recurse(t->left) * inorder_recurse(t->right);
    else if(t->info == '+')
        return inorder_recurse(t->left) + inorder_recurse(t->right);

    return (t->info - '0');
}




int count_internal_nodes(item v)
{
    int c = 0;

    if(v->right != z)
    {
        c = count_internal_nodes(v->right);
    }

    if(v->left != z)
    {
        c = count_internal_nodes(v->left);
    }

    return 1 + c;
}

int count_nodes(item v)
{
    int c = 0;

    if(v->right != z)
    {
        c += count_internal_nodes(v->right);
    }

    if(v->left != z)
    {
        c += count_internal_nodes(v->left);
    }

    return 1 + c;
}

int count_full_nodes(item v)
{
    int c = 0;

    if(v->right != z)
    {
        c = count_internal_nodes(v->right);
    }

    if(v->left != z)
    {
        c = count_internal_nodes(v->left);
    }

    return 1 + c;
}

int get_height(item v)
{
    int i = count_internal_nodes(v);

    return ceil(log2(i));
}

int main()
{
    item root;
    cout << "Enter postfix expression: ";
    root = create_tree();

    cout << "\n" << inorder_recurse(root);

    //cout << "\n" << "Internal nodes: " << count_internal_nodes(root);
    //cout << "\n" << "Height of tree is: " << get_height(root);

    //cout << "Post order traversal: ";
    //postorder_traverse(root);
}
