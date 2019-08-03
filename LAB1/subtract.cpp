#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long int
#include "add-header.cpp"
using namespace std;

string complement9(string s2,int len){
	int l2 = s2.length();

	int pos2 = l2-1;
	string s;
	for(int i=0;i<len+1;i++){
		s.append("9");

	}
	s[0] = '0';
	for(int i=0;i<l2;i++){
		s[len-i] = '0' + (9-(s2[pos2] - '0'));
		pos2--;
	}
	int carry= 1;
	int j=len;
	while(carry ){
		if(s[j] == '9'){
			s[j] = '0';
			carry=1;
			j--;
		}
		else{
			s[j] = s[j] + 1;
			carry=0;
			j--;
		}
	}
	if(s[0] == '0'){
		s.erase(s.begin());
	}
	return s;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int len = max(s1.length(),s2.length());
	string s2_com = complement9(s2,len);
	string s3 = add(s1,s2_com);
	int maxx = max(s1.length(),s2_com.length());
	if(s3.length()>maxx){
		s3.erase(s3.begin());
		cout<<s3<<endl;
	}
	else{
		s3 = complement9(s3,s3.length());
		cout<<"-"<<s3<<endl;
	}
	
	return 0;
}