#include <iostream>
#include <algorithm>

using namespace std;


int multiplication(int a, int b){

	if(a == 0 || b == 0) return 0;

	if (a > b)
		return multiplication(a,b-1) + a;
	else
		return multiplication(a-1,b) + b;
}

int main(){

	
	cout << multiplication(5000,800) << endl;


	return 0;

}