#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;

int findMaximum(int arr[],int n)
{
	int maximum=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>maximum)
		{
			maximum=arr[i];
		}
	}

	return maximum;
}

void ABooksSolution(int arr[], int n)
{
	int *listArray=new int[n];
	unordered_map <int,int> m;
	int maximum=findMaximum(arr,n);

	for(int i=0;i<n;i++)
	{
		m[arr[i]]=0;
	}

	for(int i=0;i<n;i++)
	{
		m[arr[i]]++;
	}

	for(int i=0;i<n;i++)
	{
		listArray[i]=(-m[maximum]);
	}

	int smaller=0;

	listArray[0]=n-m[arr[0]];
	smaller+=m[arr[0]];

	for(int i=1;i<n;i++)
	{
		if(arr[i]==arr[i-1])
		{
			listArray[i]=listArray[i-1];
		}
		else if(arr[i]!=maximum)
		{
			listArray[i]=n-m[arr[i]]-smaller;
			smaller+=m[arr[i]];
		}
		else
		{
			listArray[i]=0;
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<listArray[i]<<" ";
	}
	cout<<endl;
	
	delete []listArray;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int arr[n];

		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		ABooksSolution(arr, n);
	}


	return 0;
}