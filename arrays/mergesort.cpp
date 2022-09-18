#include<climits>
#include<iostream>
using namespace std;

void merge(int a[],int p,int q,int r){
  int n1=q-p+1,n2=r-q;
  int l[n1+1],R[n2+1];
  int i,j;
  for(i=0;i<n1;++i)
    l[i]=a[p+i];
  for(j=0;j<n2;++j)
    R[j]=a[q+j+1];
  l[n1]=INT_MAX;
  R[n2]=INT_MAX;
  i=j=0;
  for(int k=p;k<=r;++k)
    if(l[i]<=R[j]){
      a[k]=l[i];
      ++i;
    }else{
      a[k]=R[j];
      ++j;
    }
}

void mergesort(int a[],int p,int r){
  if(p<r){
    int q=(p+r)/2;
    mergesort(a,p,q);
    mergesort(a,q+1,r);
    merge(a,p,q,r);
  }
}

int main(){
  int a[]={6,3,9,5,8,2,7};
  int n=sizeof(a)/sizeof(a[0]);
  mergesort(a,0,n-1);
  for(int x:a){
    cout<<x;
  }
  return 0;
}