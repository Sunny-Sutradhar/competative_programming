#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
 
    while(t--){
        char a[30],s[100],b[30];
        cin>>a>>s;
        int lenA = strlen(a);
        int lenS = strlen(s);
        int j = lenS;
        int index=0,sum,numA,numB,check=0;
        for(int i=lenA-1;i>=0;i--){
            j--;
 
            if(j<0){
                check = -1;
                break;
            }
            if(a[i]>s[j]){
                if(j-1<0){
                  check = -1;
                  break;
                }
 
                int fs = s[j]-'0';
                sum = s[j-1]-'0';
 
                sum*=10;
                sum+=fs;
                numA = a[i]-'0';
               // cout<<sum<<" sum"<<endl;
                numB = sum - numA;
                if(numB>9){check = -1;break;}
                j-=1;
 
                b[index++] = numB+ '0';
                //cout<<numA<<endl;
 
              
            }else{
                sum = s[j]-'0';
                numA = a[i]-'0';
                numB = sum - numA;
                if(numB>9){check = -1;break;}
                b[index++] = numB + '0';
                //cout<<numA<<endl;
                //cout<<numB<<" b"<<endl;
 
 
            }
            
 
        }
 
        if(check==-1)cout<<-1<<endl;
        else{
            //cout<<j<<endl;
            j--;
            for(int i=j;j>=0;j--){
                b[index++] = s[i];
            }
             b[index] = '\0';
             int len = strlen(b);
             len--;
             for(int i=len;i>=0;i--){
                if(b[len]=='0')len--;
                else break;
             }
            if(len<0)cout<<0<<endl;
            else{
                for(int i=len;i>=0;i--){
                //if(b[i]=='0' && i=len)
                cout<<b[i];
               // cout<<"what!";
               }
               cout<<endl;
            }
             
             
        }
        
    }
 
}