#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

const int modulo = 1e7 + 19;
static bool hasht[modulo][4];
lli p[2];
int main()
{
    p[0] = 769;
    p[1] = 1543;
    lli n;
    cin >> n;
    string s, t, temp;
    lli powers[105][2];
    memset(powers, 1, sizeof(powers));
    for(int j=0;j< 2;j++)
    {
        for (int i = 1; i <= 100; i++)
        {
            powers[i][j] = ((powers[i - 1][j] % modulo) * p[j]) % modulo;
        }
    }
    vector<string> v;
    for(int i=0;i< n;i++)
    {
        cin >> s;
        v.push_back(s);
        lli ss = lli(s.size());
        for(int j=0;j< 2;j++)
        {
            lli h = 0;
            for(int k=0;k< ss;k++)
            {
                if ('a' <= s[k] && s[k] <= 'z'){
                    h = (h + (lli(s[k] - 'a' + 1) * powers[k][j]) % modulo) % modulo;
                }
                else{
                    h = (h + (lli(s[k] - 'A' + 27) * powers[k][j]) % modulo) % modulo;
                }
            }
            hasht[h][j] = true;
        }
    }
    for(int i=0;i< n;i++)
    {
        temp = v[i];
        reverse(v[i].begin(),v[i].end());
        t = v[i];
        if (temp == t){
            continue;
        }
        lli st = t.size();
        int f = 1;
        for(int j=0;j< 2;j++)
        {
            lli h = 0;
            for(int k=0;k< st;k++)
            {
                if ('a' <= t[k] && t[k] <= 'z'){
                    h = (h + (lli(t[k] - 'a' + 1) * powers[k][j]) % modulo) % modulo;
                }
                else{
                    h = (h + (lli(t[k] - 'A' + 27) * powers[k][j]) % modulo) % modulo;
                }
            }
            if (hasht[h][j] == false){
                f = 0;
            }
        }
        if (f == 1)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

/*
5
abc
cba
agf
sad
sadsad
*/