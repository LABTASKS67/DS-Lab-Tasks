#include <iostream>
using namespace std;
int maxinarr(int arr[], int n)
{
	if (n==1)
	{
		return arr[0];
	}
	int maxints = maxinarr(arr, n - 1);
	return (arr[n - 1] > maxints) ? arr[n - 1] : maxints;
}
int main()
{
	const int s = 5;
	int arra[s]={2,51,7,19,3};
	int maxint= maxinarr(arra, s);
	cout<<"max int is "<<maxint;
}