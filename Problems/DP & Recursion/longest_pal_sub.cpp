#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void palindromSub(string str){

	int size = str.size();
	
	vector< vector <int> > table(size,vector<int>(size));

	for(int i=0; i<size; i++) table[i][i] = 1;

	for(int k=2; k<=size; k++){

		for(int i=0; i<size-k+1; i++){

			int j = i+k-1;

			if(str[i] == str[j] && k == 2)
				table[i][j] = 2;
			else if(str[i] == str[j])
				table[i][j] = 2 + table[i+1][j-1];
			else
				table[i][j] = max(table[i+1][j],table[i][j-1]);

		}
	}

	cout << "Length is: " << table[0][size-1] << endl;

}



int main(){

	string str = "BBABCBCAB";

	palindromSub(str);

	return 0;
}
