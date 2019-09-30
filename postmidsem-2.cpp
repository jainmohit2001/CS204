#include <bits/stdc++.h>
#include <math.h>
#define ll long long int
#define f first
#define s second
using namespace std;


bool comp(pair <ll,ll> &a, pair <ll,ll> &b){
	return (a.f < b.f || (a.f == b.f && a.s < b.s) );
}

bool cw(pair <ll,ll> &a,pair <ll,ll> &b, pair <ll,ll> &c ){
	return a.f*(b.s-c.s) + b.f*(c.s - a.s) + c.f*(a.s - b.s) < 0;
}

bool ccw(pair <ll,ll> &a,pair <ll,ll> &b, pair <ll,ll> &c ){
	return a.f*(b.s-c.s) + b.f*(c.s - a.s) + c.f*(a.s - b.s) > 0;
}

int main(){
	ll n;
	cin>>n;
	vector< pair <ll,ll> > v;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	if(v.size()==1){
		return 0;
	}
	sort(v.begin(), v.end());
	pair <ll,ll>  p1;
	p1= v[0];
	pair <ll,ll> p2;
	p2 = v[n-1];
	vector< pair <ll,ll> > up, down;
	up.push_back(p1);
	down.push_back(p1);
	for(ll i=1;i< n;i++){
		if(i==n-1 || cw(p1,v[i],p2)){
			while(up.size() >=2 && !cw(up[up.size()-2], up[up.size()-1],v[i])){
				up.pop_back();
			}
			up.push_back(v[i]);
		}
		if(i==n-1 || ccw(p1,v[i],p2)){
			while(down.size() >=2 && !ccw(down[down.size()-2], down[down.size()-1],v[i])){
				down.pop_back();
			}
			down.push_back(v[i]);
		}
	}
	v.clear();
	for(ll i=0;i<up.size();i++){
		v.push_back(up[i]);
	}
	for(ll i=down.size()-2;i>0;i--){
		v.push_back(down[i]);
	}
	cout<<endl;
	for(ll i=0;i<v.size();i++){
		cout<<v[i].first<< " "<<v[i].second<<endl;
	}
	return 0;
}