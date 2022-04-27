#include<bits/stdc++.h>
using namespace std;

struct totalValue
{
    int s;
    int e;
    
};

bool compare(totalValue i, totalValue j){
    return i.e<j.e;
}

int main(){
    
    int n,q;
    cin>>n>>q;
    struct totalValue N[n],Q[q];
    for(int i=0;i<n;i++){
        cin>>N[i].s>>N[i].e;
        
    }
    for(int i=0;i<q;i++){
       cin>>Q[i].s>>Q[i].e;
      // Q[i].index = i;
    }
    sort(N,N+n,compare);
    //O(nlogn + n*q) solution 
    for(int i=0;i<q;i++){
        int start,finish,count=0;
        start = Q[i].s;
        finish = Q[i].e;

        for(int j=0;j<n;j++){
           if(start<=N[j].s && finish>=N[j].e){
               count++;
               start = N[i].e;
           }
        }
        cout<<count<<endl;
    }


    

}