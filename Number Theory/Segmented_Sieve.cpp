/*********************
 *   Sunny Sutradhar *
 *     10/06/2022    *
 *********************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

const int N = 1000000;
bool prime[N+1];
vector<int> allPrime;

ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

void seive(){;
    for(int i=2;i<=N;i++){
         prime[i] = true;
    }
    for(int i=2;i*i<=N;i++){
        if(prime[i]){
            for(int j = i+i;j<=N;j+=i){
                //cout<<j<<endl;
                prime[j] = false;
            }
        }
    }
}
vector<ll> genarateAllPrime(int n){
    vector<ll> v;
    for(int i=2;i<=n;i++){
       if(prime[i]){
          v.push_back(i);
       }
    }
    return v;
}

void segmentSeive(ll l,ll r){
      int n = r-l+1;
      bool demo[n];
      for(int i=0;i<n;i++){
         demo[i] = true;
      }
      if(l==1)demo[0] = false;
      vector<ll>primes = genarateAllPrime(sqrt(r));
      for(auto it: primes){
         ll fisrtMultiple = (l/it)*it;
         if(fisrtMultiple<l) fisrtMultiple +=it;
         for(ll i = max(fisrtMultiple,it*it);i<=r;i+=it){
             //cout<<i<<endl;
             demo[i-l] = false;
         }

      }

      for(ll i = l;i<=r;i++){
         if(demo[i-l]){
            cout<<i<<endl;
         }
      } cout<<endl;


}
std::map<string, int> mp;
void permutation(string a, int l, int r) 
{ 
    if (l == r) 
        mp.insert({a,0});
    else
    { 
        for (int i = l; i <= r; i++) 
        { 
            swap(a[l], a[i]); 
            permutation(a, l+1, r); 
            swap(a[l], a[i]); 
        } 
    } 
} 
ll abs(ll a,ll b){
    if(a>b)return a-b;
    return b-a;
}
int main(){

    seive();

    int t;
    cin>>t;

    while(t--){
        ll l,r;
        cin>>l>>r;
        segmentSeive(l,r);
    }


}