/******
 * Author : Sunny Sutradhar
 * Date   : 22/04/2022 
 ******/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef char node_type;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        ll count=0,l=-1,s=-1,k,m;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
               count++;
               //break;
            }
        }
        if(count<=1){
            cout<<count<<endl;
        }else{
            count = 0;
            for(int i=0;i<n-1;i++){
                if(a[i]==a[i+1]){
                   l = i;
                   s= i+1;
                  break;
                }
            }
            for(int i = n-1;i>0;i--){
                 if(a[i]==a[i-1]){
                    k = i-1;
                    m = i;
                 break;

               }
            }
            //cout<<l<<" "<<s<<endl;
            //cout<<k<<" "<<m<<endl;
            if(s==k)cout<<1<<endl;
            else{
                cout<<k-s<<endl;
            }
            
        }
    }
}