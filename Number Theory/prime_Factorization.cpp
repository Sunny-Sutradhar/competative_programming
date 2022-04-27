/******
 * Author : Sunny Sutradhar
 * Date   : 18/04/2022 
 ******/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
bool prime[1000000];

void prime_factorization(int n){
     int count =0;
      
     cout<<n<<" = ";
     for(int i=2;i*i<=n;i++){
          if(n%i==0){
              count = 0;
             while(n%i==0){
                n/=i;
                count++;
             } 
             cout<<i<<"^"<<count<<", ";
          }
     }
     if(n>1)cout<<n<<"^"<<1<<endl;
     else cout<<endl;
}

int main(){
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        prime_factorization(n);

    }
}