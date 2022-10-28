/*********************
 *   Sunny Sutradhar *
 *     13/07/2022    *
 *********************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dp[1000000];

int factorial(){
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<100001;i++){
        dp[i] = i*dp[i-1];
    }
}




int main()
{
    int t;
    factorial();
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }


}
