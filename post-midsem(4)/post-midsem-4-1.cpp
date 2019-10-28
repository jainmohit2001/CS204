#include <bits/stdc++.h>

using namespace std;
#define lli long long int

void addedge(vector<lli> adj[], lli u, lli v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}


bool is_bipa(vector<lli> adj[], lli v, vector<bool>& visited, vector<int>& color){
	for(lli u : adj[v]){
		if(visited[u] == false){
			visited[u] = true;
			color[u] = !color[v];
			if(!is_bipa(adj,u,visited,color)){
				return false;
			}
		}
		else if(color[u] == color[v]){
			return false;
		}
	}
return true;
}

int main(){
	lli n,m;
	cin>>n>>m;

	vector<lli> adj[n+1];
	vector<bool> visited(n+1);
	vector<int> color(n+1);

	for(int i=0;i<m;i++){
		lli x,y;
		cin>>x>>y;
		addedge(adj,x,y);
	}
	visited[1] = true;
	color[1] = 0;
	if(is_bipa(adj,1,visited,color)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
return 0;
}