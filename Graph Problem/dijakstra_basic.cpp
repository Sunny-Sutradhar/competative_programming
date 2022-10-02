//Dijkstra

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;


void view_undirected_graph(vector<vector<int>> &graph){
    for(int i=1;i<graph.size();i++){
        cout<<"Vertex "<<i<<" : ";
        for(auto node : graph[i]){
            cout<<node<<"-> ";
        }cout<<endl;
    }
}


vector<int> dijkstra(vector<vector<pair<int,int>>> &graph,int source){
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>pq;
    int vertex = graph.size();
    //Intialize soruce to all node distance is INFINITE
    vector<int>dist(vertex+1,INT_MAX);
    //we push in priority queue 1st one is distance and second one is node name
    pq.push({0,source});
    dist[source] = 0;
    vector<pair<int,int>> adjNode;
    pair<int,int>node;

    while(!pq.empty()){
        node = pq.top();
        adjNode = graph[node.second];
        pq.pop();
        //cout<<node.first<<endl;
        //int current_cost = node.second;
        for(auto it : adjNode){
            //Path Relaxation
            //cout<<it.first<<" ";
            if(dist[it.first]>dist[node.second]+it.second){
                dist[it.first] = dist[node.second] + it.second;
                pq.push({dist[it.first],it.first});

            }
        }//cout<<endl;
    }

    return dist;

}



int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    
    int vertex,edge;
    cin>>vertex>>edge;

    vector<vector<pair<int,int>>> graph(vertex+1);
    
    //Lests Assume the graph is directed
    for(int i=0;i<edge;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        graph[u].push_back({v,cost});        
    }

    vector<int>ans = dijkstra(graph,1);
    for(int i=1;i<=vertex;i++){
        cout<<1<<" -> "<<i<<" : "<<ans[i]<<endl;
    }


    

    
}

