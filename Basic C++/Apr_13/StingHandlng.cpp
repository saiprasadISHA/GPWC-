#include <iostream>
using namespace std;

int main()
{
    char s1[100];
    cin >> s1; // It will work for a single word
    // cin.getline(s1);   // for any string input including space

    char *s = new char[100];
    cin >> s;
    cin.getline(s);
    return 0;
}