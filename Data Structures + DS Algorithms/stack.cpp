#include <iostream>

using namespace std;

class Stack{
	
private:

	struct node{
		int value;
		node *next;
	};

	node *top;

public:

	Stack(){top = nullptr;}
	void push(int);
	int topStack();
	void pop();
	bool empty();
	void printStack();

};

void Stack::push(int n){

	node *element = new node;
	element->value = n;
	element->next = nullptr;

	if(top){
		element->next = top;
		top = element;
	}
	else top = element;
}

int Stack::topStack(){
	if(!top) return -1;
	return top->value;
}

void Stack::pop(){

	if(top){
		node *aux = top;
		top = top->next;
		delete aux;
	}
	else printf("The Stack is empty.\n");
}

bool Stack::empty(){
	return top;
}


void Stack::printStack(){

	node *ptr = top;

	while(ptr){
		printf("%d ",ptr->value);
		ptr = ptr->next;
	}
	cout << endl;

}

int main(int argc, char **argv){

	Stack myStack;

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);

	//printf("SDFDFS\n");

	myStack.printStack();
	cout << "-> " << myStack.topStack() << endl;

	myStack.pop();
	myStack.pop();
	myStack.push(1);

myStack.printStack();
	cout << "-> " << myStack.topStack() << endl;


	return 0;
}



