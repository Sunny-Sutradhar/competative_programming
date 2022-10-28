//Disjoint Set

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;


void makeSet(int u){
    parent[u] = u;
}


// time complexity O(n);
int findParent(int u){
    if(parent[u] == u){
        return u;
    }

    return findParent(parent[u]);
}

// Optimized Find operation 
// time complexity log(n)
int findParentOptimized(int u){
    if(parent[u]==u){
        return u;
    }
    parent[u] = findParentOptimized(parent[u]);

    return parent[u];
}

void unionSet(int u,int v){
    int parentOfu = findParentOptimized(u);
    int parentOfv = findParentOptimized(v)
    if(parentOfu!=parentv){
       parent[parentOfu] = parentv;
    }
}


int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    
    
}

