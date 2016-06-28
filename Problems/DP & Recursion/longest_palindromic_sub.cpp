#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void palindromSub(string str){

	int size = str.size();
	int maxim = 1, index=0;
	vector< vector<bool> > table(size,vector<bool>(size,false));

	for(int i=0; i<size; i++) table[i][i] = true;

	for(int i=0; i<size-1; i++){
		if (str[i] == str[i+1]){
			table[i][i+1] = true;
			maxim = 2;
			index = i;
		}
	}

	for(int k=3; k<=size; k++){

		for(int i=0; i<size-k+1; i++){

			int j = i+k-1;

			if(str[i] == str[j] && table[i+1][j-1] == true){
				table[i][j] = true;
				if(k > maxim){
					maxim = k;
					index = i;
				}
			}
		}
	}

	cout << "\nPalindorm -> " << str.substr(index,maxim) << "\n";
	cout << "Length is: " << maxim << endl;

}



int main(){

	string str = "forgeeksskeegfor";

	palindromSub(str);

	return 0;
}
