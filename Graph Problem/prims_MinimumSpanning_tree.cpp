//Disjoint Set

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void prims(vector<vector<pair<int,int>>> &graph){
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
     pq.push({0,{1,1}}); // in soucec 1 cost is 0
     vector<vector<pair<int,int>>>minimum_spaning_tree(graph.size());

    pair<int,pair<int,int>>node;
    vector<bool> isVisited;
    for(int i=0;i<graph.size();i++){
        isVisited.push_back(false);
    }

    while(!pq.empty()){
        node = pq.top();
        pq.pop();

        int u = node.second.first;
        int v = node.second.second;
        int cost = node.first;
        //cout<<u<<" - > "<<v<<" = "<<cost<<endl;
        if(!isVisited[v4]) 
            minimum_spaning_tree[u].push_back({v,cost});
        isVisited[v] = true;
        isVisited[u] = true;

        for(auto it:graph[v]){
            if(isVisited[it.first]==false)
                pq.push({cost+it.second,{v,it.first}});
                //cout<<cost+it.first<<" = "<<v<<" ->"<<it.first<<endl;
        }

    } 
   
    for(int i=1;i<minimum_spaning_tree.size();i++){
        for(auto it:minimum_spaning_tree[i]){
            cout<<i<<" -> "<<it.first<<" = "<<it.second<<endl;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int vertex,edge;
    cin>>vertex>>edge;

    vector<vector<pair<int,int>>> graph(vertex+1);

    for(int i=0;i<edge;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        graph[u].push_back({v,cost});
        graph[v].push_back({u,cost});
    }

    prims(graph);


    
    
}

