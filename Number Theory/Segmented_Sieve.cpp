/******
 * Author : Sunny Sutradhar
 * Date   : 18/04/2022 
 ******/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
bool prime[1000001];

void seive(int n){
    prime[0] = true;
    prime[1] = true;
    for(int i=2;i*i<=n;i++){
       if(!prime[i]){
         for(int j = i+i;j<=n;j+=i){
            prime[j] = true;
         }
       }
    }
}

int segmented_sieve(int n){
    
}

int main(){
    seive(1000000);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(!prime[n]){
            cout<<n<<" THis is prime"<<endl;
        }else{
            cout<<n<<" "<<"This is not prime"<<endl;
        }
    }
}