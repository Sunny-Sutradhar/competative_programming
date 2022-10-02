//BFS

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



int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    
    int vertex,edge;
    cin>>vertex>>edge;

    vector<vector<int>> undirected_graph(vertex+1);
    
    
    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        undirected_graph[x].push_back(y);
        undirected_graph[y].push_back(x);
    }

    view_undirected_graph(undirected_graph);

    
}

