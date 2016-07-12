#include <iostream>

using namespace std;

class LinkedList{

private:
	struct node{
		int val;
		node *next;
	};

	node *head;

	void split(node *head, node *&a, node *&b);
	void merge(node *&head, node *&a, node *&b);
	void mergeSort(node *&head);


public:
	LinkedList(){head=NULL;};
	void addNode(int val);
	void addSorted(int val);
	void deleteNode(int val);
	void sortList();
	void reverseList();
	void printList();

};


void LinkedList::addNode(int val){

	node *n;
	n = new node;

	n->val = val;
	n->next=NULL;

	if(head==NULL)
		head=n;
	else{

		node * ptr;
		ptr = head;

		while(ptr->next != NULL)
			ptr=ptr->next;
		ptr->next=n;
	}
}

void LinkedList::addSorted(int val){

	node *n = new node;
	n->val = val;

	node *ptr, *prev;
	ptr = head;
	prev = NULL;

	while(ptr != NULL){
		if(ptr->val > val) break;
		prev = ptr;
		ptr=ptr->next;
	}
	
	if(ptr == head) head = n;
	else prev->next = n;
	n->next = ptr;


}

void LinkedList::deleteNode(int val){


	if(head!=NULL){

		node  *ptr;
		node *prev;
		ptr = head;
		prev = NULL;

		while(ptr!=NULL){
			if(ptr->val==val) break;
			prev=ptr;
			ptr=ptr->next;
		}

		if(ptr!=NULL){

			if(ptr == head) head = ptr->next;
			else prev->next = ptr->next;

			delete ptr;
		}
	}
}

void LinkedList::printList(){

	node *ptr;
	ptr=head;

	while(ptr){
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << "\n";
}

void LinkedList::split(node *head, node *&a, node *&b){


	if(head == NULL || head->next == NULL){
		a=head;
		b=NULL;
	}
	else{
		node *fast, *slow;
		fast = head->next;
		slow = head;

		while(fast!=NULL){
			fast = fast->next;
			if(fast!=NULL){
				fast = fast->next;
				slow = slow->next;
			}
		}

		a=head;
		b=slow->next;
		slow->next=NULL;
	}
}

void LinkedList::merge(node *&head, node *&a, node*&b){

	if(a==NULL || b==NULL){
		if(a==NULL) head = b;
		if(b==NULL) head = a;
	}
	else{


		node *aux;

		if(a->val < b->val){
			aux = a;
			a = a->next;
		}
		else{
			aux = b;
			b = b->next;
		}

		head = aux;


		while(a!=NULL && b!=NULL){
			if(a->val < b->val){
				aux->next = a;
				a = a->next;
			}
			else{
				aux->next = b;
				b = b->next;
			}
			aux = aux->next;
		}

		while(a!=NULL){			
			aux->next = a;
			a = a->next;
			aux = aux->next;
		}
		while(b!=NULL){			
			aux->next = b;
			b = b->next;
			aux = aux->next;
		}

	}
}

void LinkedList::mergeSort(node *&head){

	if(head==NULL || head->next==NULL)
		return;

	node *a, *b;

	split(head,a,b);
	mergeSort(a);
	mergeSort(b);

	merge(head,a,b);
}



void LinkedList::sortList(){
	mergeSort(head);
}

void LinkedList::reverseList(){

	if(head){

		node *ptr, *prev, *aux;
		ptr=head;
		prev=NULL;

		while(ptr){

			aux=ptr->next;
			ptr->next=prev;
			prev=ptr;
			ptr=aux;
		}

		head=prev;
	}
}


int main(int argc, char **argv){

	LinkedList list;

	list.addNode(60);
	list.addNode(50);
	list.addNode(30);
	list.addNode(20);
	list.addNode(10);
	list.addNode(5);

	list.printList();
	list.sortList();
	list.printList();
	list.reverseList();
	list.printList();
		list.reverseList();
	list.printList();
	list.addSorted(22);
		list.printList();

	return 0;
}







