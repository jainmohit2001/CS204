#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long int
#include "subtract-header.cpp"
using namespace std;

// 0 for s1>s2
// 1 for s1<s2
// 2 for s1==s2
int compare(string s1,string s2){
	if(s1.length()>s2.length()){
		return 0;
	}
	else if (s1.length()<s2.length()){
		return 1;
	}
	else{
		int flag=-1;
		for(int i=0;i<s1.length();i++){
			if(s1[i]>s2[i]){
				flag=0;
				break;
			}
			else if(s1[i]<s2[i]){
				flag=1;
				break;
			}
		}
		if(flag==-1){
			return 2;
		}
		else return flag;
	}

}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int l1 = s1.length();
	int l2 = s2.length();
	string temp;
	temp=s2;
	int p = l1-l2;
	long long int ans=0;
	for(int i=0;i<l1-l2;i++){
		temp.append("0");
		
	}
	if(s2.length()==1 && s2[0]=='0'){
		cout<<"invalid operation"<<endl;
		return 0;
	}
	int times=0;
	while(s1.length() >= s2.length() && (compare(s1,s2)==0 || compare(s1,s2)==2)){
		
		while(1){

			if(compare(s1,temp)==0 || compare(s1,temp)==2){
				s1 = sub(s1,temp);
				times++;
			}
			else{
				if(temp.length()>=l2){
					temp.erase(temp.end()-1);
					ans += pow(10,p)*times;
					p--;
					times=0;
					break;
				}
				
			}
		}
	}
	if(s1.length()==0){
		s1.append("0");
	}
	cout<<"Quotient is: "<<ans<<endl;
	cout<<"Remainder is: "<<s1<<endl;
	return 0;
}