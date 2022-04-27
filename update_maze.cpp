/***
 * Author : Sunny Sutradhar
 * Date : 25/01/2022 
 ***/
#include<bits/stdc++.h>
using namespace std;
int a[100][100];

//Here x,y is Sourse point and X,Y destination point
//n,m is Maze Size;
//Here we only use simple bfs to find the sortest path
int leesAlgorithms(int n,int m,int x,int y,int X,int Y){
    queue<pair<pair<int,int>,int>> q;
    //queue structure ((x,y),c)
    //vector<pair<int,int>> parent;
    bool visited[n+1][m+1] ={false};

    int cost = 0;
    if(a[x][y]==0 || a[X][Y]==0){ //If sourse and destination is block/0 then answer is -1.
        return -1;
    }
    q.push({{x,y},0});
    while(!q.empty()){
        x = q.front().first.first; //((x,y),c)
        y = q.front().first.second;
        cost = q.front().second;
        //cout<<x<<" "<<y<<" -> "<<cost<<endl;
        if(X==x && Y==y)
         { 
            return cost;
         }
        q.pop();
        visited[x][y] = true;
        a[x][y] = -1;
        if(x-1>=0 && a[x-1][y]==1){
           if(!visited[x-1][y])
            q.push({{x-1,y},cost+1});
        }
        if(x+1<n && a[x+1][y]==1){
          if(!visited[x+1][y])
            q.push({{x+1,y},cost+1});
        }
        if(y-1>=0 && a[x][y-1]==1){
           if(!visited[x][y-1])
            q.push({{x,y-1},cost+1});
        }
        if(y+1<m && a[x][y+1]==1){
           if(!visited[x][y+1])
            q.push({{x,y+1},cost+1});
        }

    }
    return -1;

}

int main(){
    int n,m,x,y,X,Y;
    cin>>n>>m; 

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    } 

    cin>>x>>y; //Starting point
    cin>>X>>Y; //ending point
    
    cout<<leesAlgorithms(n,m,x,y,X,Y)<<endl;

 
}

/*
inputs
9 10
1 0 1 1 1 1 0 1 1 1
1 0 1 0 1 1 1 0 1 1
1 1 1 0 1 1 0 1 0 1
0 0 0 0 1 0 0 0 0 1
1 1 1 0 1 1 1 0 1 0 
1 0 1 1 1 1 0 1 0 0
1 0 0 0 0 0 0 0 0 1
1 0 1 1 1 1 0 1 1 1
1 1 0 0 0 0 1 0 0 1
0 0
3 4 


5 6
1 1 1 1 0 0
1 0 0 1 1 1
1 0 1 0 1 0
1 0 1 0 1 0
1 1 1 1 1 0
0 0
4 3
*/
//queue
/*
||
|((4,4),8)|
|((3,2),7)|
|((4,3),7)|Wow we find the destination :-). Now we return the cost =7
|((3,4),7)|*
|((4,2),6)|*
|((2,4),6)|*
|((1,5),6)|* "No way to go"
|((4,1),5)|*
|((1,4),5)|*
|((4,0),4)|*
|((1,3),4)|*
|((3,0),3)|*
|((0,3),3)|*
|((2,0),2)|*
|((0,2),2)|*
|((1,0),1)|*
|((0,1),1)|*
|((0,0),0)|* //Source

*/

