#include<iostream>
using namespace std;

int partition(int a[], int beg, int end)
{
	int pivot = a[end];
	int start = beg;
	for(int i=beg; i<end; i++)
	{
		if(a[i] <= pivot)
		{
			//swap smallest elements with bigger elements
			int temp = a[start];
			a[start] = a[i];
			a[i] = temp;
			start++;
		}
	}

	//swap pivot element
	int temp = a[start];
	a[start] = a[end];
	a[end] = temp;

	//return pivot index
	return start;
}

void quick_sort(int a[], int beg, int end)
{
	if(beg < end)
	{
		int pivot = partition(a, beg, end);
		quick_sort(a, beg, pivot-1);
		quick_sort(a, pivot+1, end);
	}
}

int main()
{
	int a[100];
	int n;

	cin>>n;
	
	for(int i=0; i<n; i++)
	  cin>>a[i];

	quick_sort(a, 0, n-1);

	for(int i=0; i<n; i++)
		cout<<a[i];

	return 0;
}
