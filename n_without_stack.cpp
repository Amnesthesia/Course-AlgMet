#include <iostream>

using namespace std;

int main()
{
    int n = 10, result = n;

    for(n = n-1; n>0; n--)
    {
        result *= n;
    }

    cout << result;
}
