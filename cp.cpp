#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pr;
const ll INF = 1e9;

/*
void check8Adjecent(){
    for(int k = max(i-1,0);k<=min(n-1,i+1);k++){
        for(int l = max(j-1,0);l<=min(m-1,j+1);l++){
            if(a[k][l]=='#'){
                count++;
            }
        }
    }
}
*/

int main(){
    
    int n;
    cin>>n;
    string a;
    cin>>a;
    
    int count = 0;
    int ans = 0;
    map<char,int>x,y;
    for(int i=1;i<n;i++){
        
        for(int j = 0;j<i;j++){
            x.insert({a[j],1});
        }
        for(int k = i;k<n;k++){
            auto it = x.find(a[k]);
            if(it!=x.end()){
                y.insert({a[k],1});
            }
        }
        
            
            int sx = x.size();
            int sy = y.size();
            ans = max(ans,min(sx,sy));
        
        
            
        x.clear();
        y.clear();
    }
    cout<<ans<<endl;
    


}


