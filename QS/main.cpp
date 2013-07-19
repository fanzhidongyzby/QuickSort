#include<iostream>
using namespace std;

void quicksort1(int a[],int m,int n)
{
	if(m>=n)return;
	int i=m,v=a[m],t;
	for(int j=m+1;j<=n;j++)
	{
		if(a[j]<v)
		{
			i++;
			t=a[i];a[i]=a[j];a[j]=t;
		}
	}
	t=a[i];a[i]=a[m];a[m]=t;
	quicksort1(a,m,i-1); 
	quicksort1(a,i+1,n);
}

void quicksort2(int a[],int m,int n)
{
	if(m>=n)return;
	int p=m,v=a[p];
	int i=m,j=n;
	while(i<j)
	{
		while(a[j]>=v&&j>i)--j;
		if(i<j){a[p]=a[j];p=j;}
		while(a[i]<v&&i<j)++i;
		if(i<j){a[p]=a[i];p=i;}
	}
	a[p]=v;
	quicksort2(a,m,p-1);
	quicksort2(a,p+1,n);
}


int main()
{
	int a1[]={213,325,123,3,5,23234,2323,54,6};
	quicksort1(a1,0,8);
	for(int i=0;i<9;i++)
		cout<<a1[i]<<" ";
	cout<<endl;
	int a2[]={213,325,123,3,5,23234,2323,54,6};
	quicksort1(a2,0,8);
	for(int i=0;i<9;i++)
		cout<<a2[i]<<" ";
	cout<<endl;
	return 0;
}