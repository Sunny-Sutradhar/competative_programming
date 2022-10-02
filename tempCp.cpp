#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;



int main() {
   freopen("input.txt", "r", stdin);
   int n,m,k;
   cin>>n>>m>>k;
   vector<string>a;
   for(int i=0;i<n;i++){
       string temp;
       cin>>temp;
       a.push_back(temp);
   }
   //cout<<("Hello");
   //cout<<a[0]<<endl;
   stack<pair<int,int>>stk;
   pair<int,int>data;
   int max_i,max_j;
   int maxVal = 0;
   int totalDot = 0;
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        if(a[i][j]=='.'){
            //cout<<i<<" "<<j<<endl;
            int tempValue = 0;
            stk.push({i,j});
            while(!stk.empty()){
                data = stk.top();
                stk.pop();
                int x = data.first;
                int y = data.second;
                a[x][y] = 'V';
                if(x+1<n && a[x+1][y]=='.'){
                      stk.push({x+1,y});
                      //cout<<x+1<<" "<<y<<endl;
                }
                if(x-1>=0 && a[x-1][y]=='.'){
                      stk.push({x-1,y});
                      //cout<<x-1<<" "<<y<<endl;
                }
                if(y+1<m && a[x][y+1]=='.'){
                      stk.push({x,y+1});
                      //cout<<x<<" "<<y+1<<endl;
                }
                if(y-1>=0 && a[x][y-1]=='.'){
                      stk.push({x,y-1});
                      //cout<<x<<" "<<y-1<<endl;
                }
                tempValue++;
                totalDot++;
                //cout<<stk.size()<<endl;
                

            }
            //cout<<tempValue<<endl;
            if(maxVal<tempValue){
                maxVal = tempValue;
                max_i = i;
                max_j = j;
                //cout<<maxVal<<endl;
            }
        }
     }
   } 
   cout<<maxVal<<endl;
   //cout<<totalDot<<endl;
   int makeX =  (k - (totalDot - maxVal));
   
   stk.push({max_i,max_j});
   cout<<makeX<<endl;
   maxVal-=makeX;
    while(!stk.empty()){
        data = stk.top();
        stk.pop();
        int x = data.first;
        int y = data.second;
        a[x][y] = '.';
        if(x+1<n && a[x+1][y]=='V'){
              stk.push({x+1,y});
              //val++;
        }
        if(x-1>=0 && a[x-1][y]=='V'){
              stk.push({x-1,y});
            
        }
        if(y+1<m && a[x][y+1]=='V'){
              stk.push({x,y+1});
        }
        if(y-1>=0 && a[x][y-1]=='V'){
              stk.push({x,y-1});
        }
        maxVal--;
        if(maxVal==0)break;
        //cout<<i<<endl;

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='V')a[i][j]='X';
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }



}


