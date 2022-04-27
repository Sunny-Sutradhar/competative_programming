/******
 * Author : Sunny Sutradhar
 * Date   : 18/04/2022 
 ******/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int prime_factorization(int n){
     int count =0;
     if(n<2)return 0;

     for(int i=2;i*i<=n;i++){
          if(n%i==0){
              count++;
             while(n%i==0){
                n/=i;
             } 
          }
     }
     if(n>1)count++;
     return count;
}

int main(){
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        cout<<n<<" : "<<prime_factorization(n)<<endl;

    }
}