#include <bits/stdc++.h>
#define lli  long long int

const int N = 1e6 + 5005;
using namespace std;
	int n, m, c;
	int parent[N];
    int size[N];
    
void make_set(lli v)
{
    parent[v] = v;
    size[v] = 1;
}
lli find_leader(lli v)
{
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find_leader(parent[v]);
}
void merge_set(lli a, lli b)
{
    a = find_leader(a);
    b = find_leader(b);
    if (a != b)
    {
        if (size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}
int index(int i, int j)
{
    return i * m + j;
}
int main()
{
    
    cin >> n >> m >> c;
    int a[n + 2][m + 2];
    

    memset(a, -1, sizeof(a));

    for(int i=1;i<= n;i++){
            for(int j=1;j<= m;j++){
                cin >> a[i][j];
                make_set(index(i, j));
            }
    } 

    for(int i=1;i<= n;i++){
            for(int j=1;j<= m;j++){

            if (a[i][j] == a[i - 1][j]){
                merge_set(index(i, j), index(i - 1, j));
            }
        }
    }
    for(int i=1;i<= n;i++){
            for(int j=1;j<= m;j++){
        
            if (a[i][j - 1] == a[i][j]){
                merge_set(index(i, j - 1), index(i, j));
            }
        }
    }
    lli maxi = -1, color = -1;
    for(int i=1;i<= n;i++){
            
            for(int j=1;j<= m;j++){

            lli x = find_leader(index(i, j));
            if (size[x] > maxi)
            {
                maxi = size[x];
                color = a[i][j];
            }
        }
    }
    cout<<maxi<<" "<<color<<endl;
    return 0;
}