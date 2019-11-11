#include <bits/stdc++.h> 
#define lli long long int


using namespace std; 

int main(){
    lli n;
    string s,temp1,temp2;
    vector<string>v;
    set<string> st;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        st.insert(s);
        v.push_back(s);
    }
    for(int i=0;i<n;i++)
    {
        temp2=v[i];
        reverse(v[i].begin(), v[i].end());
        temp1=v[i];
        if(temp2==temp1){
            continue;
        }
        if(st.find(temp1)!=st.end())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<< "NO"<<endl;
    return 0;
}
  
