#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    //freopen("input.txt", "r", stdin);
    
    int n;
    cin>>n;

    vector<ll>a;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }

    for(int i=0;i<n;i++){
        a.push_back(a[i]);
    }
    int nn= n;
    n = a.size();
    //map<int,>
    // for(int i=0;i<n;i++){
    //      cout<<a[i]<<" ";
    // }cout<<endl;
    ll meh = 0;
    ll max = -1e18;
    int startIndex = 0;
    for(int i=0;i<n;i++){
        meh += a[i];
        if(meh<a[i]){
            meh = a[i];
            startIndex = i;
        }
            //else{
        //     startIndex++;
        //     if(startIndex==nn)
        //     {
        //         meh = a[i];
        //         startIndex = 0;
        //     }
        // }
        
        if(max<meh){

           if(startIndex<nn){
               max = meh;
           }
           cout<<startIndex<<" "<<i<<endl;
        }
        //startIndex++;
    }
    cout<<max<<endl;

     


}


