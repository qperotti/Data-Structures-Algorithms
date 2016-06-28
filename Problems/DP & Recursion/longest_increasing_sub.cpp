/*
Given an unsorted array of integers, find the length of longest 
increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore 
the length is 4. Note that there may be more than one LIS combination, 
it is only necessary for you to return the length.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int longestIS(vector<int> const &nums){

	if (nums.size() == 0) return 0;

	int result = 1;
	int res = 1;
	vector<int> LIS(nums.size(),1);
	
	for (int i=1; i<nums.size(); i++){

		for(int j=0; j<i; j++){

			if (nums[j] < nums[i])
				LIS[i] = max(LIS[i],LIS[j]+1);
		}
		result = max(LIS[i],result);
	}

	return result;
}


int main(){

	vector<int> nums{10, 22, 9, 33, 21, 50, 41, 60, 80};

	cout << "The LIS is: " << longestIS(nums) << endl;

	return 0;
}