#include<bits/stdc++.h>
using namespace std;



int main(){
   vector<pair<string,int>> inputs;
    int n;
    cin>>n;
    map<string,int>mp,output;
    string s;
    int maxS=INT_MIN;
    int num,maxN;
    for(int i=0;i<n;i++){
        cin>>s>>num;
        //cout<<s<<" "<<n<<endl;
        inputs.push_back(make_pair(s,num));
        mp[s] = 0;
        
        
    }
   
    for(int i=0;i<n;i++){
        //cout<<inputs[i].first<<" "<< inputs[i].second<<endl;
        mp[inputs[i].first] += inputs[i].second;
    }
    for(auto &i:mp){
        if(i.second>maxS)maxS =i.second;
    }
    //cout<<maxS<<endl;

    vector<pair<string,int>> :: iterator i;
     
    for(i=inputs.begin();i<inputs.end();++i){
        output[(*i).first] += (*i).second;
    
        

        if(output[(*i).first]>=maxS && mp[(*i).first]==maxS){
            s = (*i).first;
         //   maxS = mp[(*i).first];
           //cout<<maxS<<endl;
            break;
        }
       // cout<<(*i).first<<" "<< (*i).second<<endl;
    }
    cout<<s<<endl;
   
    

}