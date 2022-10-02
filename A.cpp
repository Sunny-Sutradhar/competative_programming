/*********************
 *   Sunny Sutradhar *
 *     10/05/2022    *
 *********************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;

//A

int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;

        if(a[0]-'0'+a[1]-'0'+a[2]-'0'==a[3]-'0'+a[4]-'0'+a[5]-'0'){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
       
        

    }
}