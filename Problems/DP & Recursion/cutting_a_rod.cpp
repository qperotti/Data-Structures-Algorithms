#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;



int cutRod(int price[], int n, int lenght){
	

	vector<int> val(lenght+1,0);

	for(int i=1; i<=lenght; i++){
		for(int j=0; j<i; j++){
			val[i] = max(val[i],val[i-j-1]+price[j]);
		}
	}

	return val.back();
}



int main(){
	
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};

	int lenght = 8;
	
    cout << "Maximum Obtainable Value is " << cutRod(arr, 8, lenght) << endl;

	return 0;
}