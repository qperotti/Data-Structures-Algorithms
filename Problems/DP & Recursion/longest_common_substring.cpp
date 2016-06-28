#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int commonSub(string str1, string str2){

	vector< vector<int> > LCS(str1.size(), vector<int>(str2.size()));

	int maxim = 0;


	for(int i=0; i<str1.size(); i++){

		for(int j=0; j<str2.size(); j++){

			if(str1[i] == str2[j]){

				if (i*j == 0) LCS[i][j] = 1;
				else LCS[i][j] = LCS[i-1][j-1] + 1;

				maxim = max(maxim,LCS[i][j]);

			}
			else LCS[i][j] = 0;
		}
	}

	return maxim;

}




int main(){
	
	string str1 = "TheLongestCommonSubstring";
	string str2 = "HelloWorlCatSummonSubway";

	cout << "The longest common substring is: " << commonSub(str1,str2) << endl;

	return 0;
}