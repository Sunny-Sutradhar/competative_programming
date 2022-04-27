/***
 * Author : Sunny Sutradhar
 * Date : 15/01/2022 
 ***/
//Time limit Exist

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MAX 99999999999

void findMin(ll nums[], int low, int high, ll &min)
{
    if (low == high)                    
    {   
        if (min > nums[high]) {          
            min = nums[high];
        }
        return;
    }
    if (high - low == 1)                
    {
        if (nums[low] < nums[high])       
        {
            if (min > nums[low]) {       
                min = nums[low];
            }
           
        }
        else {
            if (min > nums[high]) {      
                min = nums[high];
            } 
        }
        return;
    }
 
 
    int mid = (low + high) / 2;
 
    findMin(nums, low, mid, min);
 
    findMin(nums, mid + 1, high, min);
}

ll solve(int k[],int n,long long int c[],int m){
    long long int sum = 0,tempC[m],min;
    std::map<ll, pair<int,bool>> map;
    sort(k,k+n,greater<>());
    for(int i=0;i<m;i++){
        map.insert(make_pair(c[i],make_pair(i,false)));
        tempC[i] = c[i];
    }
    map[MAX].second = true;
    // for(int i=0;i<m;i++){
    //     cout<<"what?";
    //     cout<<map[c[i]].first<<" "<<map[c[i]].second<<endl;
    // }
    min = 0;
    for(int i=0;i<n;i++){
        
        findMin(tempC,0,k[i]-1,min);
        //cout<<"min"<<min<<endl;
        if(map[min].second==false){
            sum+=min;
            //cout<<"map : "<<min<<endl;
            map[min].second = true;
            int index = map[min].first;
            tempC[index] = MAX;
            
            //cout<<"Sum: "<<sum<<endl;
            
        }
        else{

            sum += c[k[i]-1];
            //cout<<c[k[i]-1]<<" sum: "<<sum<<endl;
        }
        m++;
    }
    return sum;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int k[n];
        long long int c[m];
        for(int i=0;i<n;i++){
            cin>>k[i];
        }
        for(int i=0;i<m;i++){
            cin>>c[i];
        }
        //cout<<"check";
        cout<<solve(k,n,c,m)<<endl;
    }
}