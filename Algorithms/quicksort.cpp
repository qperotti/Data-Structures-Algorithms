
#include <iostream>


using namespace std;



int partition(int a[], int start, int end){

	int pivot = a[(start+end)/2];

	while (start<=end){

		while(a[start]<pivot) start++;

		while(a[end]>pivot) end--;

		if (start<=end){

			int aux = a[start];
			a[start] = a[end];
			a[end] = aux;
			start++;
			end--;
		}

	}

	return start;

}



void quicksort(int a[], int s, int l){
	
	int pivot = partition(a,s,l);
	if (s<pivot-1) quicksort(a,s,pivot-1);
	if (l>pivot) quicksort(a,pivot,l);
	

}

int main(){

	int a[]={52,14,63,21,89,74,565,10,1,3};

	quicksort(a,0,9);

	for (int i=0; i<10; i++) cout << a[i] << " " << endl;


	return 0;
}