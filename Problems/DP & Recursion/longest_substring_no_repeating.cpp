#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int longestSub(string str, string &LSWRC){

	int lastIndex = 0;
	int maxim = 0;
	int currentMax = 0;

	int validLI;


	vector<int> cList(256,-1);


	for(int i=1; i<str.size(); i++){

		if(str[i] == -1 || cList[str[i]] < lastIndex){
			cList[str[i]] = i;
			currentMax++;
			maxim = max(maxim,currentMax);		

			//Save lastIndex valid
			if(maxim == currentMax) validLI = lastIndex;

		}
		else{
			lastIndex = cList[str[i]]+1;
			currentMax = i - lastIndex + 1;
			cList[str[i]] = i;

		}

	}

	LSWRC = str.substr(validLI,maxim);

	return maxim;
}



int main(){


	string str = "TheLongestSubstringWithoutRepeating";
	string LSWRC;

	cout << "The LSWRC is: " << longestSub(str,LSWRC) << " --> " << LSWRC << endl;


	return 0;
}