#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long int
#include "subtract-header.cpp"
using namespace std;

// 0 for s1>s2
// 1 for s1<s2
// 2 for s1==s2
int comp(string s1,string s2){
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
    int t;
    cin>>t;
    string ans[t][2];
    for(int i=0;i<t;i++){
            ans[i][0] = "";
    ans[i][1] = "";
	string s1,s2;
	cin>>s1>>s2;
	int l1 = s1.length();
	int l2 = s2.length();
	string temp;
	temp=s2;
	int power = l1-l2;
	long long int a=0;
	for(int i=0;i<l1-l2;i++){
		temp.append("0");

	}
	if(s2.length()==1 && s2[0]=='0'){
		ans[i][0] = "Invalid operation";
		return 0;
	}
	int t=0;
	while(s1.length() >= s2.length() && comp(s1,s2)!=1){

		while(1){

			if(comp(s1,temp)!=1){
				s1 = sub(s1,temp);
				t++;
			}
			else{
				if(temp.length()>=l2){
					temp.erase(temp.end()-1);
					a += pow(10,power)*t;
					power--;
					t=0;
					break;
				}

			}
		}
	}
	if(s1.length()==0){
		s1.append("0");
	}
	ans[i][0] += to_string(a);
	ans[i][1] = s1;
    }
    for(int i=0;i<t;i++){
        cout<<ans[i][0]<<endl;
        cout<<ans[i][1]<<endl;
    }
	return 0;
}
