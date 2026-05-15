#include <iostream>
using namespace std;
int sumofarr(int size, int arr[])
{
	if (size==0)
	{
		return 0;
	}
	return arr[size-1]+sumofarr(size-1,arr);
}

int main()
{
	const int size=2;
	int arr[size]={6,7};
	int sum=sumofarr(size,arr);
	cout<<"the sum of array using recursion is "<<sum;
	cout<<"\n";
	return 0;
}