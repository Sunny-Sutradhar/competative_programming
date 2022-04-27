#include<bits/stdc++.h>
using namespace std;


vector<bool> prime(1000000);

void sive(int n){
    for(int i=2;i<=sqrt(n);i++){
    	if(prime[i]==false){
    		for(int j = i*2;j<n;j+=i){
    			prime[j] = true;
    		}
    	}
    }
    for(int i=2;i<n;i++){
    	if(!prime[i]){
    		cout<<i<<" ";
    	}
    }
}


//time complexity sqrt(n)
bool isPrime(int n){
	for(int i=2;i<=sqrt(n);i++){
       if(n%i==0)return false;
	}
    if(n==1)return false;
    return true;
}


int main(){
	 int n;
	 cin>>n;
	 // if(isPrime(n)){
	 // 	cout<<"This is prime number"<<endl;
	 // }
	 // else{
	 // 	cout<<"This is not prime number"<<endl;
	 // }
	 sive(n);
}