/******
 * Author : Sunny Sutradhar
 * Date   : 18/04/2022 
 ******/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
bool prime[1000001];
vector<int>v;
vector<ll>all;
void seive(){
    int n=31623;
    for(int i=2;i<=n;i++){
        if(!prime[i]){
           for(int j = i*i;j<n;j+=i){
              prime[j] = true;
           }
        }
    }
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            v.push_back(i);
            all.push_back(i);
        }
    }
}
void Segment_sieve(ll m,ll n){
    if(m==1)m++;
    int len = n-m+1;
    bool a[len+1]={false};
    ll num;

    for(int p:v){
        if(p*p>n)break;
        ll g = (m/p)*p;
        if(g<m)g+=p;
        for(ll j=g;j<=n;j+=p){
            if(j!=p) 
                a[j-m] = true;
        }
    }
    for(int i=0;i<len;i++){
        if(!a[i]){
            //cout<<m+i<<endl;
            all.push_back(m+i);
        }
    }
    //cout<<endl;
}

int main(){
    seive();
    ll i = 1000000;
    for(int j=1;j<10;j++){
        Segment_sieve(i,i*j);
        i*=j;
    }
    
   
   int n = all.size();
   cout<<n<<endl;
   cout<<all[0]<<endl;

}