#include <bits/stdc++.h>

using namespace std;
#define lli long long int

void addedge(vector<lli> adj[], lli u, lli v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void addpseudo(vector<lli> adj[], lli u , lli v, lli p ){
	adj[u].push_back(p);
	adj[p].push_back(u);
	adj[v].push_back(p);
	adj[p].push_back(v);
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
	lli p=n+1;

	vector<lli> adj[2*n +1 ];
	vector<bool> visited(2*n +1);
	vector<int> color(2*n +1);

	for(int i=0;i<m;i++){
		lli x,y,k;
		cin>>x>>y>>k;
		if(k%2==1){
			addedge(adj,x,y);
		}
		else{
			addpseudo(adj,x,y,p);
			p++;
		}
	}
	visited[1] = true;
	color[1] = 0;
	if(is_bipa(adj,1,visited,color)){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
return 0;
}