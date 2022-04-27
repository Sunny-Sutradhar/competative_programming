#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
typedef int node_type;
#define MAX 1000000000


void addEdge(vector<node_type> adj[],node_type s, node_type d){
     adj[s].push_back(d);
     adj[d].push_back(s);  
}

void print_graph(vector<node_type> adj[],node_type  vertex){
      for(int i=0;i<vertex;i++){
          int s = i;
          cout<<s;
          for(auto x : adj[s]){
            cout<<" -- > "<<x;
          }cout<<endl;
      }

}

void dfs(vector<node_type> adj[] , node_type source,int vertex){
      stack<node_type> stk;
      stk.push(source);
      vector<node_type> path;
      node_type
      map<node_type,bool > isVisited;
      for(int i=0;i<vertex;i++){
          isVisited.insert({i,false});
      }

      while(!stk.empty()){
          
      }
      
}

int main(){
  
  int vertex = 5;
  vector<node_type> adj[vertex];
  //addEdge = new vector<node_type>5;

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  addEdge(adj,4,3);
  print_graph(adj,vertex);
  
  

}

