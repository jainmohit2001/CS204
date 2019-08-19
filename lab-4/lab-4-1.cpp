#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


struct node{
	string s;
	struct node* lptr;
	struct node* rptr;
};

struct node* cn(string data){
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->lptr = NULL;
	temp->rptr = NULL;
	temp->s = data;
	return temp; 
}
int prec(char c){
	if(c =='('){
		return -1;
	}
	else if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
}
struct node* exptree(string s){
	stack<char> stk1;
	stack<struct node* > stk2;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			int j=i;
			int temp=0;
			while(s[j]>='0' && s[j]<='9'){
				temp = temp*10 + (s[j] - '0');
				j++;
			}
			string temp1 = to_string(temp);
			
			stk2.push(cn(temp1));
			i = j-1;
		}
		else if(s[i] == '('){
			stk1.push(s[i]);

		}
		else if(s[i]=='*' || s[i] == '-' || s[i]=='+' || s[i]=='^' || s[i]=='/'){
			if(stk1.empty() == 1){
				
				stk1.push(s[i]);
			}
			else{
					if(prec(stk1.top()) < prec(s[i])){
						
					 stk1.push(s[i]);
					}
				else{
					while(stk1.empty() == 0){
					if(prec(stk1.top()) >= prec(s[i])){
						string y=" ";
						y[0] = stk1.top();
						stk1.pop();
						struct node* n = cn(y);
						n->rptr = stk2.top();
						stk2.pop();
						n->lptr = stk2.top();
						stk2.pop();
						stk2.push(n);
					}
					}
					stk1.push(s[i]);
				}
			}
		}

		
		else if(s[i]==')'){
			
			while(stk1.top() !='('){
					string y=" ";
					y[0] = stk1.top();
					stk1.pop();
					struct node* n = cn(y);
					n->rptr = stk2.top();
					stk2.pop();
					n->lptr = stk2.top();
					stk2.pop();
					stk2.push(n);
			}
			
			stk1.pop();
		}
		
	
	}
		while(stk1.empty() != 1){
			string y=" ";
			y[0] = stk1.top();
			
			stk1.pop();
			struct node* n = cn(y);
			n->rptr = stk2.top();
			stk2.pop();
			n->lptr = stk2.top();
			

			stk2.pop();
			stk2.push(n);
		}
	
	return stk2.top();

}

int eval(struct node *root){
	if(root==NULL){
		return -1;
	}
	if(root->lptr == NULL && root->rptr == NULL){
		
		return stoi(root->s);
	}
	
	int l_val = eval(root->lptr);
	int r_val = eval(root->rptr);
	
	string temp = root->s;
	if(temp[0] == '+'){
		
		return l_val + r_val;
	}
	if(temp[0] == '*'){
		
		return l_val *  r_val;
	}
	if(temp[0] == '-'){
		
		return l_val - r_val;
	}
	if(temp[0] == '/'){
			
		return l_val / r_val;
	}
	if(temp[0] == '^'){
			
		return pow(l_val,r_val);
	}
return -1;
}
int main(){
	int t;
	cin>>t;
	vector< vector<int> > v(t);
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			v[i].push_back(eval(exptree(s)));
		}
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<endl;
		}
	}
	
	return 0;
}