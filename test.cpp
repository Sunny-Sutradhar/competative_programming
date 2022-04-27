/***
 * Author : Sunny Sutradhar
 * Date : 02/03/2022 
 ***/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(int argc, char const *argv[]){
     string s;
   cin>>s;
   int len = s.size();
   stack<pair<string,int>> st;
   set<string> set;
   st.push(make_pair(s,0));
   string text,temptext;
   char temp;
   int i = 0,j,cond=0,index = 1,val=1;
   //tempStack.push(s);
   while(!st.empty()){
       text = st.top().first;
       i = st.top().second;
         st.pop();
       if(i+1<len){
         st.push(make_pair(text,i+1));
       }
       set.insert(text);
       //cout<<text<<endl;
       for(j = i+1;j<len;j++){
           temptext = text;
           temp = temptext[i];
           temptext[i] = temptext[j];
           temptext[j] = temp;
           st.push(make_pair(temptext,i+1));
           set.insert(temptext);
           //tempStack.push(temptext);
           //cout<<temptext<<endl;
       }
       
       //set.insert(temptext);

   }
   cout<<set.size()<<endl;
   // set<string> ::iterator itr;

   for(auto itr = set.begin();itr!=set.end();itr++){
      cout<<*itr<<endl;
   }

   
   // while(!tempStack.empty()){
   //      cout<<tempStack.top()<<endl;
   //      tempStack.pop();
   // }
    

    

    return 0;
}