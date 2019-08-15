#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long int
using namespace std;

struct point{
	int x;
	int y;
	struct point* ptr;
};

void AddFirst(struct point **start,int a,int b){
	struct point* temp = (struct point *)malloc(sizeof(struct point));
	if(temp == NULL){
		return;
	}
	temp->x = a;
	temp->y = b;
	temp->ptr = *start;
	*start = temp;
}
 int DelFirst(struct point **start){
 	if(*start == NULL){
 		return -1;
 	}
 	else{
 		struct point *temp = *start;
 		*start = (*start)->ptr;
 		free(temp);
 	}
 	return 0;
 }

 int Del(struct point **start,int x1, int y1){
 	struct point *temp = *start;
 	struct point *prev = NULL;
 	while(temp != NULL){
 		if(temp->x == x1 && temp->y == y1){
 			if(temp == *start){
 				int x=DelFirst(start);
 				return x;
 			}
 			prev->ptr = temp->ptr;
 			free(temp);
 			return 0;
 		}
 		else{
 			prev = temp;
 			temp = temp->ptr;
 		}
 	}
 	return -1;
 }

int searchd(struct point *start, int d){
	int ctr=0;
	struct point* temp = start;
	while(temp != NULL){
		float dist = ((float)temp->x*(float)temp->x) + ((float)temp->y*(float)temp->y);
		if((float)d >= sqrt(dist)){
			ctr++;
		}
			temp = temp->ptr;
	}
	if(ctr==0){
		return -1;
	}
return ctr;
}
string Search(struct point* start,int x1,int y1){
	string s= "False";
	struct point *temp = start;
	while(temp != NULL){
		if(temp->x == x1 && temp->y == y1){
			s = "True";
			return s;
		}
		else{
			temp = temp->ptr;
		}
	}
	return s;
}

int Length(struct point*start){
 	int len=0;
 	struct point*temp = start;
 	while(temp != NULL){
 		len++;
 		temp = temp->ptr;
 	}
 	return len;
}
void print(struct point *start){
	struct point *temp = start;
	while(temp != NULL){
		cout<<"("<<temp->x<<","<<temp->y<<") ";
		temp = temp->ptr;
	}
	cout<<endl;
}


int main(){
	struct point *head = NULL;
	int n;
	cin>>n;
	int arr[n][3];
	for(int i=0;i<n;i++){
		cin>>arr[i][0];
		switch (arr[i][0]){
			case 1: cin>>arr[i][1]>>arr[i][2];break;
			case 3: cin>>arr[i][1]>>arr[i][2];break;
			case 5: cin>>arr[i][1]>>arr[i][2];break;
			case 2: break;
			case 6: break;
			case 4: cin>>arr[i][1];break;
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++){

		switch (arr[i][0]){
			case 1: AddFirst(&head,arr[i][1],arr[i][2]);break;
			case 2:	if(DelFirst(&head) == -1){cout<<DelFirst(&head)<<endl;}break;
			case 3: if(Del(&head,arr[i][1],arr[i][2])){cout<<Del(&head,arr[i][1],arr[i][2])<<endl;}break;
			case 4:	cout<<searchd(head,arr[i][1])<<endl;break;
			case 5: cout<<Search(head,arr[i][1],arr[i][2])<<endl;break;
			case 6: cout<<Length(head)<<endl;break;
		}
	}
	return 0;
}
