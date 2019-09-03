#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <math.h>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

struct node{
    int id;
    int recharge;
    struct node* lptr;
    struct node* rptr;
    int height;
};
int H(struct node* temp){
    if(temp==NULL){
        return 0;
    }
    return temp->height;
}
struct node* createnode(int user_id,int amt){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->id = user_id;
    temp->recharge = amt;
    temp->lptr = NULL;
    temp->rptr = NULL;
    temp->height = 1;
    return temp;
}
struct node* Search(struct node* root, int userid)
{
    if (root == NULL || root->id == userid){
       return root;
    }
    if (root->id < userid) {
       return Search(root->rptr, userid);
       }

        return Search(root->lptr, userid);

}
struct node* rightRotate(struct node* y){
    struct node* x = y->lptr;
    struct node* temp2 = x->rptr;
    x->rptr = y;
    y->lptr = temp2;

    y->height = max(H(y->lptr), H(y->rptr)) + 1;
    x->height = max(H(x->lptr), H(x->rptr)) + 1;
    return x;
}

struct node* leftRotate(struct node* x){
    struct node* y = x->rptr;
    struct node* temp2 = y->lptr;
    y->lptr = x;
    x->rptr = temp2;

    y->height = max(H(y->lptr), H(y->rptr)) + 1;
    x->height = max(H(x->lptr), H(x->rptr) )+ 1;
    return y;
}

int bal(struct node* N){
    if(N==NULL){
        return 0;
    }
    return (H(N->lptr)) - H((N->rptr));
}

struct node* insertnode(struct node* N, int userid, int amt){
    if(N==NULL){
        return createnode(userid,amt);
    }
    if(userid < N->id){
        N->lptr = insertnode(N->lptr,userid,amt);
    }
    else if(userid > N->id){
        N->rptr = insertnode(N->rptr,userid,amt);
    }
    else{
        return  N;
    }

    N->height = 1+ max(H(N->lptr), H(N->rptr));
    int balance = bal(N);
    if (balance > 1 && userid < N->lptr->id)
        return rightRotate( N);
    if (balance < -1 && userid >  N->rptr->id)
        return leftRotate( N);
    if (balance > 1 && userid >  N->lptr->id)
    {
         N->lptr = leftRotate( N->lptr);
        return rightRotate( N);
    }
    if (balance < -1 && userid <  N->rptr->id)
    {
         N->rptr = rightRotate( N->rptr);
        return leftRotate( N);
    }
    return  N;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lptr);
        printf("%d \n", root->id);
        inorder(root->rptr);
    }
}


int main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    int m[2] = {-1,-1};
    vector<int> ans;
    struct node* root = NULL;
    for(int i=0;i<q;i++){
        int a1;
        cin>>a1;
        if(a1==1){
                int a2,a3;
            cin>>a2>>a3;
            struct node* temp = Search(root,a2);

            if(root==NULL){
                root = insertnode(root,a2,a3);
                if(a3> m[1]){
                    m[0] = a2;
                    m[1] = a3;
                }
            }
            else if(temp == NULL){
                insertnode(root,a2,a3);
                if(a3 > m[1]){
                    m[0] = a2;
                    m[1] = a3;
                }
            }
            else{
                temp->recharge = temp->recharge + a3;
                if(temp->recharge > m[1] ){
                    m[0] = temp->id;
                    m[1] = temp->recharge;
                }
            }

        }
        else{

            ans.push_back(m[0]);
        }
        cout<<m[0]<<" "<<m[1]<<endl;

    }
    for(int i=0;i<ans.size();i++){
        if(ans[i] == -1){
            cout<<"No data available"<<endl;
        }
        else{cout<<ans[i]<<endl;
        }
    }
    return 0;
}
