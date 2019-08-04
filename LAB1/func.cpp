#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long int
using namespace std;

string add(string s1,string s2){
	ll maxx = max(s1.length(),s2.length());
	ll minn = min(s1.length(),s2.length());
	int s[maxx+1];
	s[0] = -1;
	ll pos1 = s1.length() -1;
	ll pos2 = s2.length() - 1;
	ll carry=0;
	for(int i=0;i<minn;i++){
		int temp = (s1[pos1] - '0') + (s2[pos2]-'0') + carry;
		s[maxx-i] = temp%10;
		carry = temp/10;
		pos1--;
		pos2--;
	}
	if(s1.length() == s2.length()){
		s[0] = carry;
	}
	else if(s1.length() > s2.length()){
	for(int i=0;i<maxx-minn +1;i++){
		int temp = s1[pos1] - '0' + carry;
		s[maxx-minn-i] = temp%10;
		carry = temp/10;
		pos1--;
	}
	}
	else{
		for(int i=0;i<maxx-minn;i++){
			int temp = (s2[pos2] - '0' + carry);
			s[maxx-minn-i] = temp%10;
			carry = temp/10;
			pos2--;
	}

	}
	string str;
	int i=0;
	if(s[0] >0){str += to_string(s[0]);}

	for(i=1;i<maxx+1;i++){
		str += to_string(s[i]);
	}


return str;

}
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

string sub(string s1, string s2){
	int len = max(s1.length(),s2.length());
	string s2_com = complement9(s2,len);
	string s3 = add(s1,s2_com);
	int maxx = max(s1.length(),s2_com.length());
	if(s3.length()>maxx){
		s3.erase(s3.begin());
		while(s3[0] == '0'){
			s3.erase(s3.begin());
		}
		return s3;
	}
	else{
		s3 = complement9(s3,s3.length());
		string s4;
		s4.append("-");
		s4.append(s3);
		return s4;
	}

}

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

string multiply(string s1,string s2){
	int m = s2.length();
	string temp1=multby1(s1,(s2[m-1]-'0'),0);
	int zeros=1;
	for(int i=m-2;i>=0;i--){
		string temp2 = multby1(s1,(s2[i]-'0'),zeros);
		temp1 = add(temp1,temp2);
		zeros++;
	}

return temp1;
}
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
string remain(string s1,string s2){
    string ans[2];
    ans[0] = "";
    ans[1] = "";
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
		ans[0] = "Invalid operation";
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
	ans[0] += to_string(a);
	ans[1] = s1;

	return s1;
}

