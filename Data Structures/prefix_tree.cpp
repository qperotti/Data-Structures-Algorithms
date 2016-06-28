#include <iostream>
#include <string>

#define MAX 256

using namespace std;


class Trie{

private:
	struct node{
		int words;
		node *child[MAX];
		//bool end;
	};
	node *root;

	void add(node *, string);
	void newNode(node*&);
	void print(node*,char[],int);


public:
	Trie();
	void addWord(string[],int);
	void printPrefix();

};

Trie::Trie(){
	root = new node;
	root->words = 0;
	//root->end = true;
	for (int i=0; i<MAX; i++)
		root->child[i] = NULL;
}

void Trie::newNode(node *&newNode){

	newNode = new node;
	newNode->words = 1;
	//newNode->end = false;
	for (int i=0; i<MAX; i++)
		newNode->child[i] = NULL;

}

void Trie::add(node *parent, string str){

	int size = str.size();
	int index;

	for (int i=0; i<size; i++){

		index = int(str[i]);

		if (parent->child[index] == NULL)
			newNode(parent->child[index]);
		else
			parent->child[index]->words+=1;

		parent=parent->child[index];

	}
	
	//parent->end=true;


}

void Trie::print(node *parent, char str[], int ind){

	for (int i=0; i<256; i++){

		if(parent->child[i]!=NULL){

			if(parent->child[i]->words==1){
				str[ind]=char(i);
				str[ind+1]='\n';
				cout << "FINAL-> " << str << endl;
			}
			else{
				str[ind]=char(i);
				print(parent->child[i],str,ind+1);
			}
		}
	}


}

void Trie::printPrefix(){

	char myChar[500] = "";
	if (root->words>0)
		print(root,myChar,0);


}

void Trie::addWord(string str[], int total){

	root->words+=total;
	//root->end=false;
	for (int i=0; i<total; i++)
		add(root,str[i]);	
}

int main(){

	string myString[4] = {"zebra", "dog", "duck", "dove"};

	Trie myTrie;

	myTrie.addWord(myString,4);
	myTrie.printPrefix();


	return 0;
}
