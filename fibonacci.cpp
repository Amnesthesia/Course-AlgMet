#include <iostream>

using namespace std;
int fibb(int n, int x);

int main()
{

    int n[2] = {1,1};
    for(int i = 1; i < 100; i = n[0] + n[1])
    {
        n[0] = n[1];
        n[1] = i;
        cout << i << "\n";
    }


    fibb(1,1);
}

int fibb(int n,int x)
{
    cout << n+x << " (n was " << n << " x was " << x << ") \n";
    if(n+x > 100)
        return 0;
    fibb(x,(n+x));
}
