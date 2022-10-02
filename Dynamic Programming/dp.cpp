/*********************
 *   Sunny Sutradhar *
 *     13/07/2022    *
 *********************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;



bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int printMinCountPrime(int N)
{

    int minCount;

    // Case 1:
    if (isPrime(N)) {
        minCount = 1;
    }

    // Case 2:
    else if (N % 2 == 0) {
        minCount = 2;
    }

    // Case 3:
    else {

        // Case 3a:
        if (isPrime(N - 2)) {
            minCount = 2;
        }

        // Case 3b:
        else {
            minCount = 3;
        }
    }

    cout << minCount << endl;
}


int main()
{
    int N = 100;

    printMinCountPrime(N);
    return 0;
}
