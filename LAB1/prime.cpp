#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long int
#define fast  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#include "func.cpp"
using namespace std;

int main(){
    fast;
    long long int maxx = 1000001;
    int arr[maxx] = {0};
    arr[0]=1;
    arr[1] = 1;
    for(int i=2;i<maxx/2;i++){
        if(arr[i] == 0){
            for(int j=i*2;j<maxx;j +=i){
                arr[j] = 1;
            }

        }
    }
    int val=2;
    bool flag=-1;
    int t;
    cin>>t;
    string ans[t];
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        ans[i] = "Prime";
        while(1){
            if(val>=1000000){
                flag=1;
                break;
            }
        if(arr[val]==0){
            string temp = "",rem = "" ;
            temp += to_string(val);
            if(comp(multiply(temp,temp),s) ==0 ){
                ans[i] = "Prime";
                break;
            }
            if(comp(s,temp) == 0){
            rem = remain(s,temp);
            if(rem[0] == '0'){
                ans[i] = "Not a Prime";
                flag=0;
                break;
            }
            }
            else{
                break;
            }
        }
        val++;
        }
        if(flag==1){
            string temp = "",rem = "" ;
            temp += to_string(val);
            while(1){
                    if(comp(multiply(temp,temp),s) ==0){
                        ans[i] = "Prime";
                        break;
                    }
                    if(comp(s,temp)==0){
                rem = remain(s,temp);
                if(rem[0] == '0'){
                    ans[i] = "Not a Prime";
                    flag=0;
                    break;
                }
                temp = add(temp,"1");
            }
            else{
                break;
            }
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
