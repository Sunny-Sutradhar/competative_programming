/***
 * Author : Sunny Sutradhar
 * Date : 02/03/2022 
 ***/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


 
int main(int argc, char const *argv[])
{
   
   string s;
   cin>>s;
   int len = s.size();
   stack<pair<string,int>> st;
   set<string> set;
   st.push(make_pair(s,0));
   string text,temptext;
   char temp;
   int i = 0,j;
  
   while(!st.empty()){
       text = st.top().first;
       i = st.top().second;
         st.pop();
       if(i+1<len){
         st.push(make_pair(text,i+1));
       }
       set.insert(text);
       for(j = i+1;j<len;j++){
           temptext = text;
           temp = temptext[i];
           temptext[i] = temptext[j];
           temptext[j] = temp;
           st.push(make_pair(temptext,i+1));
           set.insert(temptext);
       }

   }

   cout<<set.size()<<endl;
   for(auto itr = set.begin();itr!=set.end();itr++){
      cout<<*itr<<endl;
   }



    return 0;
}