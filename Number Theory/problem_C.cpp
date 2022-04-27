/******
 * Author : Sunny Sutradhar
 * Date   : 18/04/2022 
 ******/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
bool prime[1299710];

void seive(){
    int n=1299710;
    for(int i=2;i*i<n;i++){
        if(!prime[i]){
           for(int j = i*i;j<n;j+=i){
              prime[j] = true;
           }
        }
    }
}
int findDiff(int n){
    if(!prime[n]) return 0;
    int count=0;
    for(int i=n-1;;i--){
        count++;
        if(!prime[i])break;
    }
    if(prime[n]){
        for(int i=n;;i++){
            if(!prime[i])break;
            count++;     
        }
    }
    return count;
}

int main(){
    seive();
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        cout<<findDiff(n)<<endl;

    }
}