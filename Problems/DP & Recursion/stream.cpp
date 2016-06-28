#include <iostream>
#include <sstream>
#include <queue>

using namespace std;


int streamNums(istringstream stream){

	priority_queue<int> max;
	priority_queue< int, vector<int>, greater<int> > min;

	int tmp;

	while(!stream.eof()){

		stream >> tmp;

		if(max.size()==0) max.push(tmp);
		if(min.size()==0) min.push(tmp);

		if(tmp < max.top()) max.push(tmp);
		else min.push(tmp);

		if(abs(max.size()-min.size()) > 1){

			if(max.size() > min.size()){
				min.push(max.top());
				max.pop();
			}
			else{
				max.push(min.top());
				min.pop();
			}
		}
	}

	if(max.size() > min.size()) return max.top();
	else if(min.size() > max.size()) return min.top();
	else return(max.)
}


int main(){

	string myStream = "8 5 2 9 6 3 7 4 1 10";
	istringstream stream(myString);
	
	cout << streamNums(stream) << endl; 



	return 0;
}