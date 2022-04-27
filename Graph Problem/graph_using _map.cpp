/***
 * Author : Sunny Sutradhar
 * Date : 11/03/2022 
 ***/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
typedef char node_type;
#define MAX 1000000000
#define OUTOFTHESTACK 0
#define INTHESTACK 1
#define VIZITED 2




//for directed graph
void addEdge(map<node_type,vector<node_type>> &map,node_type s,node_type d){
     auto it = map.find(s);

     //if node is already in the map
     if(it!=map.end()){
        map[s].push_back(d);
     }
     //else we inser the node in the map
     else{
       vector<node_type> v;
       v.push_back(d);
       map.insert({s,v});
     }
}



void print_graph(map<node_type,vector<node_type>> map){

    for(auto it = map.begin();it!=map.end();++it){
          node_type s = it->first;
          vector<node_type> v = it->second;
          for(int i = 0;i<v.size();i++){
               cout<<s<<" -----> "<<v[i]<<endl;
          }
     }
}
void dfs(map<node_type,vector<node_type>> g,node_type source){
    map<node_type,int> vizited_node;
    for(auto it = g.begin();it!=g.end();++it){
          node_type s = it->first;
          vizited_node.insert({s,OUTOFTHESTACK});
    }
    stack<node_type> s;
    vector<node_type> finalG;
    s.push(source);
    while(!s.empty()){
        node_type node;
        node = s.top();
        finalG.push_back(node);
        vizited_node[node] = VIZITED;
        s.pop();
        vector<node_type> v = g[node];
        for(int i = 0;i<v.size();i++){
            if(vizited_node[v[i]]==OUTOFTHESTACK){
               s.push(v[i]);
               vizited_node[v[i]]=INTHESTACK;
            }
        }
    }
    for(int i=0;i<finalG.size();i++){
        cout<<finalG[i]<<" ";
    }cout<<endl;

}

void bfs(map<node_type,vector<node_type>> g,node_type source){
    map<node_type,int> vizited_node;
    for(auto it = g.begin();it!=g.end();++it){
          node_type s = it->first;
          vizited_node.insert({s,OUTOFTHESTACK});
    }
    queue<node_type> s;
    vector<node_type> finalG;
    s.push(source);
    while(!s.empty()){
        node_type node;
        node = s.front();
        finalG.push_back(node);
        vizited_node[node] = VIZITED;
        s.pop();
        vector<node_type> v = g[node];
        for(int i = 0;i<v.size();i++){
            if(vizited_node[v[i]]==OUTOFTHESTACK){
               s.push(v[i]);
               vizited_node[v[i]]=INTHESTACK;
            }
        }
    }
    for(int i=0;i<finalG.size();i++){
        cout<<finalG[i]<<" ";
    }cout<<endl;
}



int main(){

   map<node_type,vector<node_type>> adj;
   addEdge(adj, 'A', 'B');
   addEdge(adj, 'A', 'C');
   addEdge(adj, 'A', 'D');
   addEdge(adj, 'B', 'E');
   addEdge(adj, 'C', 'F');
   addEdge(adj, 'D', 'G');
 
   
    print_graph(adj);
    dfs(adj,'A');
    bfs(adj,'A');
  
}

