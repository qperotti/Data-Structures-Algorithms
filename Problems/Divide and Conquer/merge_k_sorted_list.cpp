#include <iostream>
#include <vector>

using namespace std;

#define K 4
#define N 4


vector<int> merge(vector<int> arr1, vector<int> arr2){

	vector<int> aux;
	int a;

	while( !arr1.empty() && !arr2.empty()){

		a = arr1.front() < arr2.front() ? arr1.front() : arr2.front();
		aux.push_back(a);
		arr1.front() < arr2.front() ? arr1.erase(arr1.begin()) : arr2.erase(arr2.begin());

	}



	if(arr1.empty()){
		while(!arr2.empty()){
			aux.push_back(arr2.front());
			arr2.erase(arr2.begin());
		}
	}
	else{
		while(!arr1.empty()){
			aux.push_back(arr1.front());
			arr1.erase(arr1.begin());
		}
	}

	return aux;

}

vector<int> mergeArrays(vector< vector<int> > vArr){


	int size;
	vector<int> aux;

	size = vArr.size();

	while(size > 1){

		aux = merge(vArr[0],vArr[1]);
		vArr.erase(vArr.begin(),vArr.begin()+2);

		vArr.push_back(aux);
		size = vArr.size();
	}

	return vArr[0];

}




int main(){
	

		int arr[N][K]= { {1,5,9,13},
					 {2,6,10,14},
					 {3,7,11,15},
					 {4,8,12,16}};


	vector< vector<int> >  vArr(N,vector<int>(K));
	vector<int> merge;

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){

			vArr[i][j] = arr[i][j];
		}
	}



	merge = mergeArrays(vArr);


	for (auto n : merge) cout << n << " ";


	return 0;
}