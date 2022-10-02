#include<bits/stdc++.h>
using namespace std;

vector<string> v;


int getKthBit(int n,int k ){
	return((n&(1<<(k-1)))>>(k-1));
}
void comibation(int n){
	int total = pow(2,n);

	for(int i=0;i<total;i++){
        string a;
        for(int j = n;j>0;j--){
            a.push_back(getKthBit(i,j)+'0');
        }
        v.push_back(a);
	}

}



int main(int argc, char const *argv[])
{
	conmibation(5);
    for(int i=0;i<v.size();i++){
    	cout<<v[i]<<endl;
    }


	return 0;
}