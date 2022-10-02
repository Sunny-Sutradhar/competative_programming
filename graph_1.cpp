/*********************
 *   Sunny Sutradhar *
 *     19/05/2022    *
 *********************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

typedef pair<int,pair<int,int>>p;

//

int abs(int a,int b){
    if(a>b){
        return a-b;
    }
    return b-a;
}

int main(){
    int t;
    cin>>t;
  while(t--){
     int n,m;
     cin>>n>>m;
     string graph[m];
     for(int i=0;i<m;i++){
        cin>>graph[i];
     }
                   //    cost,(x,y)
     priority_queue<p,vector<p>,greater<p>>pq;
     pq.push({0,{0,0}});
     int cost=0,x,y,i =0;
     while(!pq.empty()){
         auto it = pq.top();
         pq.pop();
         // i++;
         // if(i==500)break;
         cost = it.first;
         x = it.second.first;
         y = it.second.second;
         //cout<<cost<<" "<<x<<" "<<y<<endl;
         if(x==n-1 && y==m-1){
            break;
         }
         if(x+1<n){
            int temp = cost;
           // cout<<graph[x][y]<<" "<<graph[x+1][y]<<" ";
            if(graph[x][y] != graph[x+1][y])
                temp+=1;
           // cout<<temp<<endl;
            if( graph[x+1][y]!='0')pq.push({temp,{x+1,y}});

         }
         if(x-1>=0){
            int temp =cost;
            if(graph[x][y] != graph[x-1][y])
                temp+=1;
           if( graph[x-1][y]!='0') pq.push({temp,{x-1,y}});
         }
         if(y+1<n){
            int temp=cost;
            if(graph[x][y] != graph[x][y+1])
                temp+=1;
            if( graph[x][y+1]!='0')pq.push({temp,{x,y+1}});
         }
         if(y-1>=0){
            int temp =cost;
            if(graph[x][y] != graph[x][y-1])
                temp+=1;
           if( graph[x][y-1]!=-1) pq.push({temp,{x,y-1}});
         }
         //cout<<x<<" "<<y<<endl;
         graph[x][y] = '0';
     }
     cout<<cost<<endl;
 }


    
    
}