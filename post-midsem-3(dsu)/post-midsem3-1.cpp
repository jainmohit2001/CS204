#include <bits/stdc++.h>
#define lli  long long int

const int N = 1e6 + 5005;
using namespace std;
    int n, m, k;
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
lli index(lli i, lli j)
{
    return i * m + j;
}
int main()
{
    
    cin >> n >> m;
    cin >> k;
    vector< pair <lli, lli>> v1;
    vector< pair <lli, lli>> v2;
    for(int i=0;i< k;i++)
    {
        lli x,y;
        cin >> x >> y;
        v1.push_back({x, y});
        v2.push_back({y, x});
        make_set(index(x, y));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for (int i = 0; i < k - 1; i++)
    {
        if ((v1[i].first == v1[i + 1].first && v1[i + 1].second == v1[i].second + 1 )||(v1[i].first == v1[i + 1].first + 1 && v1[i + 1].second == v1[i].second))
            merge_set(index(v1[i].first, v1[i].second), index(v1[i + 1].first, v1[i + 1].second));
    }
    for (int i = 0; i < k - 1; i++)
    {
        if ((v2[i].first == v2[i + 1].first && v2[i + 1].second == v2[i].second + 1 )|| (v2[i].first == v2[i + 1].first + 1 && v2[i + 1].second == v2[i].second))
            merge_set(index(v2[i].second, v2[i].first), index(v2[i + 1].second, v2[i + 1].first));
    }
     lli maxi = -1;
    for(int i=0;i< k;i++)
    {
        lli x = find_leader(index(v1[i].first, v1[i].second));
        if (size[x] > maxi)
            maxi = size[x];
    }
    cout<<maxi<<endl;
    return 0;
}