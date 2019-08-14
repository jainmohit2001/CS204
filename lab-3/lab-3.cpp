#include <bits/stdc++.h>
#include <stack>

using namespace std;
int main(){
	int t;
	cin>>t;
	string ans[t];
	for(int j=0;j<t;j++){
		string s;
		cin>>s;
		stack<char> ss;
		ans[j] = "YES";
		int temp=0;
		bool flag=1;
		for(int i=0;i<s.length();i++){
			switch (s[i]){
				case '(': ss.push('(');break;
				case '{': ss.push('{');break;
				case '[': ss.push('[');break;
				case '<': ss.push('<');break;
				case '|': if(temp%2==0){ss.push('|');temp++;break;} else{if(ss.empty() == 0 && temp%2==1){ if((ss.top() - '|') == 0){ ss.pop(); temp++;break;} } else{flag=0;} }break;
				case ')': if(ss.empty() == 0){ if((ss.top() - '(') == 0){ ss.pop(); } } else{flag=0;} break;
				case '}': if(ss.empty() == 0){ if((ss.top() - '{') == 0){ ss.pop(); } } else{flag=0;} break;
				case ']': if(ss.empty() == 0){ if((ss.top() - '[') == 0){ ss.pop(); } } else{flag=0;} break;
				case '>': if(ss.empty() == 0){ if((ss.top() - '<') == 0){ ss.pop(); } } else{flag=0;} break;	
			}
		
			if(flag==0){
				break;
			}
		}
		if(flag!=0 && ss.empty()==1){
			ans[j] = "YES";
		}
		else{
			ans[j] = "NO";
		}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}