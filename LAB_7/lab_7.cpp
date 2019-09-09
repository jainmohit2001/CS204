#include <bits/stdc++.h>
using namespace std;

bool comp(string s1,string s2){
	string xy = s1.append(s2);
	string yx = s2.append(s1);
	if(xy>yx){
		return 1;
	}
	return 0;

}
void merge(string arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    
    string Left[n1], Right[n2]; 
  
    for (i = 0; i < n1; i++){ 
        	Left[i] = arr[l + i];
        } 
    for (j = 0; j < n2; j++){ 
        	Right[j] = arr[m + 1+ j];
        } 
  
    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (comp(Left[i],Right[j]) == 0) 
        { 
            arr[k] = Left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = Left[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergesort(string arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergesort(arr, l, m); 
        mergesort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
}
  
int main(){
	int t;
	cin>>t;
	string ans[t];
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		string arr[n];
		for(int j=0;j<n;j++){
			cin>>arr[j];
		}
		mergesort(arr,0,n-1);
		string a="";
		for(int j=n-1;j>=0;j--){
			a += arr[j];
		}
		ans[i] = a;
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
return 0;
}