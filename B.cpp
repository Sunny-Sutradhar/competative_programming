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

//B

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        ll a[n];
        std::map<ll, int> map;
        for(int i=0;i<n;i++){
            cin>>a[i];
            map.insert({a[i],0});
        }

        for(int i=0;i<n;i++){
            map[a[i]]+=1;
        }
        int x=0;
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(map[a[i]]>=k)x++;
        }
        for(int i=0;i<n;i++){
            cout<<map[a[i]]<<""<<endl;
           if(map[a[i]]>=k && map[a[i]]<=x)
            l=a[i];
           if(map[a[i]]>=k && map[a[i]]>=x)
            r=a[i];
        }
        if(l!=0 && r!=0){
            cout<<l<<" "<<r<<endl;
        }else{
            cout<<"-1"<<endl;
        }




    }
}