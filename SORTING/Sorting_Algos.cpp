#include<iostream>
using namespace std;


// BUBBLE SORT :-  It compares adjacent element in every pass. In ith pass , 
// last i elements are sorted as largest element from unsorted part is placed 
// at its correct position in every pass. (Stable)
// Time complexity :- O(n^2), Auxiliary Space :- O(1)
void bubble_sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}


// SELECTION SORT :- Find minimum element in the unsorted part of array 
// and put it in the beginning of the unsorted part, left part is sorted 
// and right is unsorted. (Unstable)
// It never makes more than O(n) swaps and can be useful when memory 
// write is a costly operation.
// Time complexity :- O(n^2) , Auxiliary Space :- O(1)
void selection_sort(int arr[],int n)
{
	int minin;
	for(int i=0;i<n-1;i++)
	{
		minin = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minin])
				minin = j;
		}
		swap(arr[i],arr[minin]);
	}
}


// INSERTION SORT :- Array is split in sorted and unsorted part, first value
// from unsorted part is placed at its correct position in sorted part. 
// (Stable & online)
// Time complexity :- O(n^2) best :- O(n), Auxiliary Space :- O(1)
void insertion_sort(int arr[],int n)
{
	int key,j;
	for(int i=1;i<n;i++)
	{
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}


// MERGE SORT :- Array is divided into two halves, till the size becomes one,
// then it keep merging the array in sorted manner using a temporary array. (Stable)
// T(n) = 2T(n/2) + θ(n) 
// Time complexity :- θ(nLogn) , Auxiliary Space :- O(n)
void merge(int arr[],int n,int l,int mid,int r)
{
	int i=l,j=mid+1,k=0;
	int temp[r-l+1];
	while(i<=mid && j<=r)
	{
		if(arr[i]<=arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=mid)
		temp[k++] = arr[i++];
	while(j<=r)
		temp[k++] = arr[j++];
	for(int i=0;i<k;i++)
		arr[l++] = temp[i];
}

void merge_sort(int arr[],int n,int l,int r)
{
	if(l>=r)
		return;
	int mid = (l+r)/2;
	merge_sort(arr,n,l,mid);
	merge_sort(arr,n,mid+1,r);
	merge(arr,n,l,mid,r);
}


// QUICK SORT :- 
// Time complexity :- θ(nLogn) , Auxiliary Space :- O(n)
int partition(int arr[],int n,int l,int r)
{
	int pivot = arr[r], i = l-1;
	for(int j=l;j<=r-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}

void quick_sort(int arr[],int n,int l,int r)
{
	if(l>=r)
		return;
	int pi = partition(arr,n,l,r);
	quick_sort(arr,n,l,pi-1);
	quick_sort(arr,n,pi+1,r);
}


//HEAP SORT
void heapify(int arr[],int n,int i)
{
	int largest = i,l = 2*i+1,r = 2*i+2;
	if(l<n && arr[l]>arr[largest])
		largest = l;
	if(r<n && arr[r]>arr[largest])
		largest = r;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}

void heap_sort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);

	for(int i=n-1;i>0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	quick_sort(arr,n,0,n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}