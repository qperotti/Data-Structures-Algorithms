#include <iostream>

using namespace std;

class LinkedList{

private:

	struct node{
		int value;
		node *next;
		node *prev;	
	};
	
	node *head;

public:
	
	LinkedList();
	void addItem(int v);
	void deleteitem(int v);
	void addItemSort(int v);
	void showAll();

};

LinkedList::LinkedList(){
	head = NULL;
}

void LinkedList::addItem(int v){

	node *n;
	node *aux;

	n = new node;
	n->value=v;
	n->next=NULL;
	n->prev=NULL;

	if (head==NULL)
		head=n;
	else{
		aux = head;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next=n;
		n->prev=aux;
	}
}

void LinkedList::addItemSort(int v){

	node *nodePtr;
	node *prevPtr;
	node *n;

	n = new node;
	n->value=v;
	n->next=NULL;
	n->prev=NULL;

	if (head==NULL)
		head=n;
	else{
			
		nodePtr = head;
		prevPtr=NULL;
		while (nodePtr->next != NULL && v>nodePtr->value){
			prevPtr=nodePtr;
			nodePtr=nodePtr->next;
		}

		if (nodePtr->value>v){
			if (nodePtr==head){
				head=n;
				head->next=nodePtr;
				nodePtr->prev=head;
			}
			else{
				prevPtr->next=n;
				n->prev=prevPtr;
				n->next=nodePtr;
				nodePtr->prev=n;
			}
		}
		else{
			nodePtr->next=n;
			n->prev=nodePtr;
		}
	}
}

void LinkedList::deleteitem(int v){

	node *nodePtr;
	node *prevPtr;

	if(head){

		nodePtr=head;
		prevPtr=NULL;

		while (nodePtr->next!=NULL && nodePtr->value!=v){
			prevPtr = nodePtr;
			nodePtr=nodePtr->next;
		}

		if (nodePtr->value == v){

			if (nodePtr==head){
				node *temp;
				temp=nodePtr;

				nodePtr=nodePtr->next;
				nodePtr->prev=NULL;

				head=nodePtr;
				delete temp;
			}

			else{


				if (nodePtr->next!=NULL){
					node *temp = nodePtr;
					nodePtr = nodePtr->next;

					prevPtr->next = nodePtr;
					nodePtr->prev = prevPtr;

					delete temp;
				}
				else{
					prevPtr->next=NULL;
					delete nodePtr;
				}
			}
		}
	}
}

void LinkedList::showAll(){

	node *aux;

	if(head){

		aux=head;

		while(aux){
			cout << aux->value << " ";
			aux = aux->next;
		}
		cout << endl;
	}
}


int main(){
	
	LinkedList myList1;
	LinkedList myList2;
	LinkedList myList3;




	myList1.addItem(7);
	myList1.addItem(1);
	myList1.addItem(6);

	myList2.addItem(5);
	myList2.addItem(9);
	myList2.addItem(2);

	myList3.head=myList3.ex5(myList1.head,myList2.head);

	myList1.showAll();
	myList2.showAll();





	return 0;
}

