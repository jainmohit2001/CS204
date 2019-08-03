#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long int
#include "add-header.cpp"
using namespace std;

string multby1(string s1,int n,int zero){
	int len = s1.length();
	int arr[len+1] = {0};
	int carry=0;
	for(int i=len;i>=1;i--){
		int temp = (s1[i-1] - '0')*n + carry;
		arr[i] = temp%10;
		carry = temp/10;
	}
	arr[0] = carry;
	string s;
	if(arr[0] != 0){
		s += to_string(arr[0]);
	}
	for(int i=1;i<len+1;i++){
		s += to_string(arr[i]);
	}
	for(int i=0;i<zero;i++){
		s += to_string(0);
	}
	return s;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int m = s2.length();
	string temp1=multby1(s1,(s2[m-1]-'0'),0);
	int zeros=1;
	for(int i=m-2;i>=0;i--){
		string temp2 = multby1(s1,(s2[i]-'0'),zeros);
		temp1 = add(temp1,temp2);
		zeros++;
	}
	cout<<temp1<<endl;
return 0;
}