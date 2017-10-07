#include<bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("ham_messages.txt","r",stdin);
	freopen("chnge.txt","w",stdout);*/
	string str;
	while(cin>>str != NULL){
		int i = 0;
		while(i < str.length()){
			if(str[i] <= 'Z' && str[i] >= 'A'){
				str[i] += 32;
				cout<<str[i];
			}
			else if(str[i] == '$')
				cout<<" "<<str[i]<<" ";
			else if(str[i] <= 'z' && str[i] >= 'a')
				cout<<str[i];
			i++;
		}
		cout<<" ";
	}
	return 0;
}
