#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int commonSub(string str1, string str2){


	vector< vector<int> > LCS(str1.size(), vector<int>(str2.size()));
	int result = 0;


	for(int i=0; i<str1.size(); i++){

		for(int j=0; j<str2.size(); j++){

			if(str1[i] == str2[j]){

				if(i*j == 0) LCS[i][j] = 1;
				else LCS[i][j] = LCS[i-1][j-1] + 1;
				result = max(result,LCS[i][j]);
			}
			else{

				if(i == 0 || j == 0){
					if(i == 0 && j == 0) LCS[i][j] = 1;
					else LCS[i][j] = i > j ? LCS[i-1][j] : LCS[i][j-1];
				}
				else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			}
		}
	}

	return result;
}




int main(){

	string str2 = "AGGTAB";
	string str1 = "GXTXAYB";

	cout << "The longest common substring is: " << commonSub(str1,str2) << endl;

	return 0;
}
