#include <iostream>
#include <string.h>

using namespace std;

char vowels[] = {'A','O','U','I','E','Y'};
char history[4];
int nHistory = 0;

bool isVowel(char c)
{
    for(int i=0; i<strlen(vowels);i++)
        if(vowels[i] == c or (char)((int)vowels[i]+32) == c)
            return true;
    return false;
}

void printRemaining(char str[])
{
    char newStr[strlen(str)-1];
    for(int i=1; i<strlen(str);i++)
        newStr[i-1] = str[i];

    cout << str[0];

    printRemaining(str);
}

int n(int n)
{
    int result = n;

    for(n = n-1; n>0; n--)
    {
        result *= n;
    }

    return n;
}

int main()
{
    string s;

    cout << "Enter string: ";
    getline(cin,s);

    char letters[s.length()],permutation[s.length()];

    // Copy all letters to array
    for(int i = 0; i<s.length();i++)
        letters[i] = s.at(i);


    for(int i = 0; i<s.length(); i++)
        printRemaining(letters);

}
