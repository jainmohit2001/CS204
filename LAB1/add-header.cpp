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