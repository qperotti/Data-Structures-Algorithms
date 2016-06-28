#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


string makePermutation(string word, char last, int j){

	string s(1,last);

	word = word.insert(j,s);

	return word;
}


vector<string> permutation(string str){

	vector<string> myVector;

	if(str.size() == 1){
		myVector.push_back(str);
		return myVector;
	}


	string reminder = str.substr(0, str.size()-1);
	vector<string> words = permutation(reminder);

	char last = str.back();

	for (auto i = words.begin(); i<words.end(); i++){

		for( int j = 0; j <= (*i).size(); j++ ){

			string s = makePermutation(*i,last,j);
			myVector.push_back(s);
		}
	}

	return myVector;
}



int main(){


	std::vector<string> v;

	v = permutation("abc");

	cout << endl;

	for (auto i = v.begin(); i<v.end(); i++) cout << *i << endl;

	

	return 0;

}