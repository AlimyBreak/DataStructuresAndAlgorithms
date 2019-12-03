

#ifndef __UNIONFINDSETTESTHELPER_H__
#define __UNIONFINDSETTESTHELPER_H__

#include <iostream>
#include <ctime>
#include "unionFindSet1.h"
#include "unionFindSet2.h"
#include "unionFindSet3.h"
#include "unionFindSet4.h"
#include "unionFindSet5.h"


using namespace std;

namespace UnionFindTestHelper{
    
    
    
    void testUF1(int n)
    {
        srand(time(NULL));
        UF1::UnionFindSet uf1 = UF1::UnionFindSet(n);
        
        time_t startTime = clock();
        
        /* 若干次并*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf1.unionElement(a,b);
        }
        
        /*若干次查*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf1.isConnected(a,b);
        }
        
        time_t endTime = clock();
        
        cout << "UF1," << 2*n << " ops, " << double(endTime - startTime ) /CLOCKS_PER_SEC  << endl;
        
        
    }
    
  
    void testUF2(int n)
    {
        srand(time(NULL));
        UF2::UnionFindSet uf2 = UF2::UnionFindSet(n);
        
        time_t startTime = clock();
        
        /* 若干次并*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf2.unionElement(a,b);
        }
        
        /*若干次查*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf2.isConnected(a,b);
        }
        
        time_t endTime = clock();
        
        cout << "UF2," << 2*n << " ops, " << double(endTime - startTime ) /CLOCKS_PER_SEC  << endl;
        
        
    }
    
    void testUF3(int n)
    {
        srand(time(NULL));
        UF3::UnionFindSet uf3 = UF3::UnionFindSet(n);
        
        time_t startTime = clock();
        
        /* 若干次并*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf3.unionElement(a,b);
        }
        
        /*若干次查*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf3.isConnected(a,b);
        }
        
        time_t endTime = clock();
        
        cout << "UF3," << 2*n << " ops, " << double(endTime - startTime ) /CLOCKS_PER_SEC  << endl;
        
        
    }
    
    
    void testUF4(int n)
    {
        srand(time(NULL));
        UF4::UnionFindSet uf4 = UF4::UnionFindSet(n);
        
        time_t startTime = clock();
        
        /* 若干次并*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf4.unionElement(a,b);
        }
        
        /*若干次查*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf4.isConnected(a,b);
        }
        
        time_t endTime = clock();
        
        cout << "UF4," << 2*n << " ops, " << double(endTime - startTime ) /CLOCKS_PER_SEC  << endl;
        
        
    }
    
    void testUF5(int n)
    {
        srand(time(NULL));
        UF5::UnionFindSet uf5 = UF5::UnionFindSet(n);
        
        time_t startTime = clock();
        
        /* 若干次并*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf5.unionElement(a,b);
        }
        
        /*若干次查*/
        for(int i = 0 ; i < n ; i++)
        {
            int a = rand() % n ;
            int b = rand() % n ;
            uf5.isConnected(a,b);
        }
        
        time_t endTime = clock();
        
        cout << "UF5," << 2*n << " ops, " << double(endTime - startTime ) /CLOCKS_PER_SEC  << endl;
        
        
    }
    
    
    
}





#endif /* !__UNIONFINDSETTESTHELPER_H__ */