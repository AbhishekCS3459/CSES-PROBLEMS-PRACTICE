#include <bits/stdc++.h>
using namespace std;
int main()
{
    int no = 9;
    if (((no >> 3) & 1) == 1)
    {
        cout << "set" << endl;
    }
    else
    {
        cout << "not set" << endl;
    }

    return 0;
}
