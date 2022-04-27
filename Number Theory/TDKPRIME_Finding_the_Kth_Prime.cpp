
/******
 * Author : Sunny Sutradhar
 * Date   : 18/04/2022 
 ******/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

bool prime[90000001];
vector<int>ans;
void sieve(int n=90000000){
	
     for(int i= 2;i*i<=n;i++){
          if(!prime[i]){
          	 for(int j = i*i;j<=n;j+=i){
          	 	prime[j] = true;
          	 }
          }
     }
     
     for(int i=2;i<=n;i++){
     	if(!prime[i]){
           ans.push_back(i);
           cout<<i<<endl;
     	}
     }
}

int main(){
	sieve(50);
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		//cout<<n;
		cout<<ans[n-1]<<endl;
	}
}
