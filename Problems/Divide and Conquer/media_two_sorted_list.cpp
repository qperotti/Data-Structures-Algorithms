#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int median(int arr1[], int l1, int r1, int arr2[], int l2, int r2){
	

	if( ((r1-l1) == 1) &&  ((r1-l1) == 1) )
		return (max(arr1[l1],arr2[l2])+min(arr1[r1],arr2[r2]))/2; 

	int m1 = (l1+r1)/2;
	int m2 = (l2+r2)/2;

	if (arr1[m1] == arr2[m2])
		return arr1[m1];

	if (arr1[m1] < arr2[m2])
		return median(arr1,m1,r1,arr2,l2,m2);
	else
		return median(arr1,l1,m1,arr2,m2,r2);

}

int findMedian(int arr1[], int arr2[], int size1, int size2){
	
	return median(arr1,0,size1-1,arr2,0,size2-1);
}


int main(){
	
	int arr1[] = {1,3,5,7,9,11};
	int arr2[] = {2,4,6,8,10,12};

	cout << "The median is: " << findMedian(arr1,arr2,6,6) << endl;

	return 0;
}