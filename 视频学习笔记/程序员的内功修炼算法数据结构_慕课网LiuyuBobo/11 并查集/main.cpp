
#include <iostream>
#include "unionFindSetTestHelper.h"

using namespace std;

int main(void)
{
    int n = 100000;
    UnionFindTestHelper::testUF1(n);
    UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);
    UnionFindTestHelper::testUF5(n);
    
    return 0 ;
    
}