#include<iostream>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

void swap_p(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}
int partition_k(double arr[], lli l, lli r, double x)
{

    lli i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap_p(&arr[i], &arr[r]);


    i = l;
    for (lli j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap_p(&arr[i], &arr[j]);
            i++;
        }
    }
    swap_p(&arr[i], &arr[r]);
    return i;
}

double findMedian(double arr[], lli n)
{
    sort(arr,arr+n);
    return arr[n/2];
}


double medianofmed(double arr[], lli l, lli r, lli k)
{
    if (k > 0 && k <= r - l + 1)
    {
        lli n = r-l+1;


        lli i;
        double median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }


        double medOfMed = (i == 1)? median[i-1]:
                                 medianofmed(median, 0, i-1, i/2);



        lli pos = partition_k(arr, l, r, medOfMed);


        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return medianofmed(arr, l, pos-1, k);


        return medianofmed(arr, pos+1, r, k-pos+l-1);
    }


    return INT_MAX;
}





int main(){
  lli t;
  cin>>t;
  vector<double>answ;
  for(lli i=0;i<t;i++){
    lli k;
    cin>>k;
    double arr[k];
    for(lli j=0;j<k;j++){
        lli x,y;
        cin>>x>>y;
        arr[j]= sqrt((x*x)+(y*y));

    }
    double ans=medianofmed(arr,0,k-1,(k+1)/2);

     answ.push_back(ans);
  }
  for(lli i=0;i<t;i++){

    cout<<answ[i]<<endl;
  }




}
