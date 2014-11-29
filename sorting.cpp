#include <iostream>

using namespace std;

int a[] = {3,2,5,1,4,6,10,8,9,7};

void insertionsort(int n)
{
    for(int i=1; i<n; i++)
    {
        int j, value = a[i];

        for(j=i; a[j-1] > a[i]; j--)
            a[j] = a[j-1];

        a[j] = value;

    }

    for(int i = 0; i<n; i++)
        cout << a[i] << " ";
}


int main()
{
    insertionsort(10);
}
