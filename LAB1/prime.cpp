#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long int
using namespace std;

int main(){
	ll n;
	cin>>n;
	bool flag=0;
	ll sq_n = sqrt(n);
	for(ll i=2;i<sq_n;i++){
		if(n%i == 0){
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"Number is Prime"<<endl;
	}
	else{
		cout<<"Number is not Prime"<<endl;
	}
	return 0;

}