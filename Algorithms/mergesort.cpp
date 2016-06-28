#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int left, int mid, int right){

	vector<int> aux;
	int lindex = left;
	int rindex = mid+1;

	while(lindex <= mid && rindex <=right){

		if(nums[lindex] < nums[rindex]){
			aux.push_back(nums[lindex]);
			lindex++;
		}
		else{
			aux.push_back(nums[rindex]);
			rindex++;
		}
	}

	while(lindex <= mid){aux.push_back(nums[lindex]); lindex++;}

	while(rindex <= right){aux.push_back(nums[rindex]); rindex++;}
	
	for(int i=left; i<=right; i++) nums[i] = aux[i-left];



}


void split(vector<int> &nums, int left, int right){

	if (left < right){
		int mid = (left + right)/2;

		split(nums,left,mid);
		split(nums,mid+1,right);
		merge(nums,left,mid,right);
	}
}



void mergeSort(vector<int> &nums){

	int size = nums.size();

	split(nums,0,size-1);

}



int main(){

	vector<int> nums = {8,5,12,1,50,500,36,95,78,3};

	mergeSort(nums);

	for(int i=0; i<nums.size(); i++) cout << nums[i] << " ";
	printf("\n");


	return 0;
}