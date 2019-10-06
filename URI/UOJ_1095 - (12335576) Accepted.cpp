#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    for(int j = 60; j >= 0; j--)
    {
            cout << "I=" << i << " " << "J=" << j <<endl;
            i = i + 3;
            j = j - 4;
    }
    return 0;
}