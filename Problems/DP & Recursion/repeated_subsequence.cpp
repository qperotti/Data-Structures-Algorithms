#include <iostream>
#include <vector>

using namespace std;


int repeatedSub(string str){

	vector< vector<int> > LCS(str.size(), vector<int>(str.size()));
	int result = 0;

	for(int i=0; i<str.size(); i++){

		for(int j=0; j<str.size(); j++){

			if(str[i] == str[j] && i!=j){

				if(i*j == 0) LCS[i][j] = 1;
				else LCS[i][j] = LCS[i-1][j-1] + 1;
				result = max(result,LCS[i][j]);

			}
			else{

				if(i == 0 || j == 0){
					if(i == 0 && j == 0)
						LCS[i][j] = 1;
					else
						LCS[i][j] = i > j ? LCS[i-1][j] : LCS[i][j-1];
				}
				else
					LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			}
		}
	}
	return result;
}


int main(){

	string str = "axxxxy";

	cout << "The longest repeated substring is: " << repeatedSub(str) << endl;

	return 0;
}









