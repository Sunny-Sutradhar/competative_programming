/***
 * Author : Sunny Sutradhar
 * Date : 13/01/2022 
 ***/


#include<bits/stdc++.h>
using namespace std;

int solve(int a[],int n){
    std::map<int, int> map;
    int l=0,r=0,k=0,pre=0,s=0,ne,tmpl,tmpr;

    for(int i=0;i<n;i++){
        auto it = map.find(a[i]);
        if(it!=map.end()){
             pre = it->second;
             ne = i+1;
             //tmpl = pre+(n-ne);
             tmpr = pre+(n-ne);
             if(k<tmpr)k=tmpr;
             //map.erase(map.begin(),it);
             map[a[i]] = i+1;
             //map.insert(make_pair(a[i],i+1));

        }else{
            map.insert(make_pair(a[i],i+1));
        }
    }
    // std::map<int, int> :: iterator it;
    // for(it = map.begin();it!=map.end();++it){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    if(k==0)return -1;
    else return k;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<solve(a,n)<<endl;
    }
}