#include <iostream>
#include "cg_lib/primitives/range.h"
using namespace std;

int main()
{
    Range<int> range(10, 10);
    cout << range << endl;
    return 0;
}

