#include<iostream>
#include<climits>
using namespace std;

int max(int a,int b){ return (a>b) ? a: b; }

int max(int a,int b,int c){ return max(max(a,b),c); }

int maxCrossingSum(int a[],int l,int m,int h){
  int sum=0, left_sum=INT_MIN;
  for(int i=m;i>=l;--i){
    sum+=a[i];
    if(sum>left_sum)
      left_sum=sum;
  }
  sum=0;
  int right_sum=INT_MIN;
  for(int i=m;i<=h;++i){
    sum+=a[i];
    if(sum>right_sum)
      right_sum=sum;
  }
  return max(left_sum+right_sum-a[m],left_sum,right_sum);
}

int maxSubArraySum(int a[],int l,int h){
  if(l>h)
    return INT_MIN;
  if(l==h)
    return a[l];
  int m=(l+h)/2;
  return max(maxSubArraySum(a,l,m-1),maxSubArraySum(a,m+1,h),maxCrossingSum(a,l,m,h));
}

int main(){
  int a[]={2,3,4,5,8},n=sizeof(a)/sizeof(a[0]),max_sum=maxSubArraySum(a,0,n-1);
  cout<<max_sum;
  return 0;
}