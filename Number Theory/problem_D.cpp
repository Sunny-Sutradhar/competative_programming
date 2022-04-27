/******
 * Author : Sunny Sutradhar
 * Date   : 25/04/2022 
 ******/
//prime factorization with sieve
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define maxnum 1000000
bool prime[maxnum+5]={false};
vector<int>allPrime;
int primeFector[maxnum+5];
int totalFector[maxnum+5];
int ans[maxnum+5];
void seive(){
    int n=maxnum;
    prime[0] = true;
    prime[1] = true;
    primeFector[0] = 0;
    primeFector[1] = 0;
    for(int i=2;i*i<=n;i++){
        if(!prime[i]){
            primeFector[i] = i;
            for(int j=i*i;j<=n;j+=i){
                if(!prime[j]){
                    prime[j] = true;
                    primeFector[j] = i;
                }
                
            }
        }
    }

    /* DEBUG*/
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            primeFector[i] = i;
        }
    }
    // for(int i=0;i<=n;i++){
    //    cout<<primeFector[i]<<" ";
    // }
}

void prime_fector_of_n_number(int n = maxnum){
    ans[1] = 0;
    for(int i=2;i<=n;i++){
        if(!prime[i])totalFector[i] = 1;
        else{
            int num = i/primeFector[i];
            totalFector[i] = totalFector[num]+1;
        }
        ans[i] = totalFector[i]+ans[i-1];
        //cout<<totalFector[i]<<endl;;
    }
}




int main(){
   seive();
   prime_fector_of_n_number();
   int n;
   while(scanf("%d",&n)!=EOF){
      // int ans = 0;
      // for(int i=2;i<=n;i++){
      //   ans+=totalFector[i];
      // }
      cout<<ans[n]<<endl;
   }
}