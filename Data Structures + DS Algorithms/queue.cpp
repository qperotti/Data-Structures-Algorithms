#include <iostream> 

using namespace std;

class Queue{
	
private:
	struct node{
		int value;
		node *next;
	};

	node *tail;
	node *front;

public:

	Queue(){tail=nullptr;front=nullptr;}
	void push(int);
	int frontQ();
	void pop();
	bool empty();
	void printQueue();
};

void Queue::push(int n){

	node *element = new node;
	element->value = n;
	element->next = nullptr;

	if(front){
		tail->next = element;
		tail = element;
	}
	else{
		front = element;
		tail = element;
	}
}

int Queue::frontQ(){
	if (front) return front->value;
	else return -1;
}

void Queue::pop(){

	if (front){
		node *aux = front;
		front = front->next;
		delete aux;
	}
	else printf("The Queue is empty.\n");
}

bool Queue::empty(){
	return front;
}

void Queue::printQueue(){

	node *ptr = front;
	while(ptr){
		cout << ptr->value << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int main(int argc, char ** argv){

	Queue myQueue;

	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(5);
	myQueue.printQueue();

	myQueue.pop();
	myQueue.pop();

myQueue.printQueue();
	myQueue.push(23);
myQueue.printQueue();

cout << myQueue.frontQ() << " " << myQueue.empty() << "\n";
	return 0;
}