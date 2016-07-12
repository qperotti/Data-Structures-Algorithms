#include <iostream>
#include <vector>

using namespace std;

class Heap{
	
private:
	vector<int> heap;
	int size;

	void heapify(int);

public:
	Heap(vector<int>);
	void addToHeap(int);
	void printHeap();
	void heapSort(vector<int> &);
	void heapify(int, int, vector<int> &);

};

Heap::Heap(vector<int> vector){
	heap = vector;
	size = heap.size()-1;
	for (int i=(size/2); i>=0; i--) heapify(i);
}

void Heap::heapify(int index){

	int l = index*2+1;
	int r = index*2+2;
	int largest = index;

	if (size >= l && heap[l]>heap[index])
		largest = l;
	else
		largest = index;
	if (size-1 >= r && heap[r]>heap[largest])
		largest = r;
	if (largest!=index){
		int aux = heap[largest];
		heap[largest]=heap[index];
		heap[index]=aux;
		heapify(largest);
	}
}

void Heap::heapify(int index, int size, vector<int> &heap){

	int l = index*2+1;
	int r = index*2+2;
	int largest = index;

	if (size >= l && heap[l]>heap[index])
		largest = l;
	else
		largest = index;
	if (size >= r && heap[r]>heap[largest])
		largest = r;
	if (largest!=index){
		int aux = heap[largest];
		heap[largest]=heap[index];
		heap[index]=aux;
		heapify(largest,heap.size()-1,heap);
	}
}

void Heap::addToHeap(int value){
	heap.insert(heap.begin(),value);
	heapify(0);
}

void Heap::printHeap(){
	for (vector<int>::iterator it=heap.begin(); it!=heap.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void Heap::heapSort(vector<int> &v){

	vector<int> heapS = heap;

	while(!heapS.empty()){
		v.insert(v.begin(),heapS.front());
		heapS.front()=heapS.back();
		heapS.pop_back();
		heapify(0,heapS.size()-1,heapS);
	}
}



int main(){

	std::vector<int> v;

	vector<int> sort;


	v.push_back(4);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(16);
	v.push_back(9);
	v.push_back(10);
	v.push_back(14);
	v.push_back(8);
	v.push_back(7);

	Heap myHeap(v);
	myHeap.printHeap();
	myHeap.heapSort(sort);

	for (int i=0; i<sort.size(); i++) cout << sort[i] << " ";
	cout << endl;



	return 0;
}