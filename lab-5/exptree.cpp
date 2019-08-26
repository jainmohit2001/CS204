#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <math.h>
#include <vector>
#include <string.h>
#include <map>
#include <unordered_map>
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
struct node* exptree(string s,unordered_map<string,int> *m){
	stack<char> stk1;
	stack<struct node* > stk2;
	int f=0;

	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			int j=i;
			int temp=0;
			while(s[j]>='0' && s[j]<='9'){
				temp = temp*10 + (s[j] - '0');
				j++;
			}
			string temp1 = to_string(temp);
			if(f==0){f=2;}
			stk2.push(cn(temp1));
			i = j-1;
		}
		else if(s[i] == '('){
			f=0;
			stk1.push(s[i]);

		}
		else if(s[i]=='*' || s[i] == '-' || s[i]=='+' || s[i]=='^' || s[i]=='/'){
			if(stk1.empty() == 1){
				
				stk1.push(s[i]);
			}
			else{
				if(s[i]=='^' && stk1.top()=='^'){

					stk1.push(s[i]);
				}
				else if(prec(stk1.top()) < prec(s[i])){
						if(f==0){
							f=1;
							
						}
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
						struct node* minus = cn("0");

						if(stk2.empty()==1){
							n->lptr = minus;
						}
						else{
							n->lptr = stk2.top();
							stk2.pop();
						}
						
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
					struct node* minus = cn("0");

					if(stk2.empty()==1){
					
							n->lptr = minus;
								
					}

					else if(f==1){
						n->lptr = minus;
								
					}
					else{
						
						n->lptr = stk2.top();
						
						stk2.pop();
					}
					
					stk2.push(n);
			}

			stk1.pop();
		}

    else{
        int p=i;
        string var;
        for(p;p<s.length();p++){
            if(!((s[p]>='a' && s[p] <='z' )|| (s[p]>='A' && s[p]<='Z'))){
                   break;
            }
             var.push_back(s[p]);
        }
        auto itr1 = (*m).find(var);

        if(itr1 == (*m).end()){
            return NULL;
        }
        else{
            string val = to_string(itr1->second);

            stk2.push(cn(val));

        }
        i = p-1;
    }
	}
		while(stk1.empty() != 1){
			string y=" ";
			y[0] = stk1.top();
			stk1.pop();
			struct node* n = cn(y);
			n->rptr = stk2.top();
			stk2.pop();
			struct node* minus = cn("0");
			if(stk2.empty()==1){
				n->lptr = minus;
			}
			else{
				n->lptr = stk2.top();
				stk2.pop();
			}
			
			stk2.push(n);
		}

	return stk2.top();

}

int eval(struct node *root){
	if(root==NULL){
		return INT_MIN;
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
return INT_MIN;
}
int main(){
	int t;
	cin>>t;
	vector<int> v;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		unordered_map<string , int> mymap;
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			int flag=0;
			for(int k=0;k<s.length();k++){
                if(s[k]=='='){
                    flag=1;
                    string ran,val;
                    ran = s.substr(0,k);
                    val = s.substr(k+1,s.length());
                    auto itr = mymap.find(ran);
                    if(itr == mymap.end()){
                        if(eval(exptree(val,&mymap))==INT_MIN){
                            v.push_back(INT_MIN);
                        }
                        else{
                            mymap[ran] = eval(exptree(val,&mymap));
                        }
                    }
                    else{
                        if(eval(exptree(val,&mymap))==INT_MIN){
                            v.push_back(INT_MIN);
                        }
                        else{
                            itr->second = eval(exptree(val,&mymap));
                        }
                    }
                }
			}
			if(flag==0){
                v.push_back(eval(exptree(s,&mymap)));
			}
		}
	}

		for(int j=0;j<v.size();j++){
			if(v[j] == INT_MIN){
                cout<<"CANNOT BE EVALUATED"<<endl;
			}
			else{
			cout<<v[j]<<endl;
		}
		}


	return 0;
}