#include <iostream>
#include <vector>
#include <list>
#include <utility> 
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;


struct node{
	string name;
	bool visited;
	list<node*> nodes;
	node(string n){name = n;} 
};

unordered_map <string,node*> myGraph;
unordered_set<string> visited;

typedef unordered_map <string,node*>::iterator iterator_graph;
typedef unordered_set<string>::iterator iterator_set;

void addNode(string origen, string destination){

	iterator_graph it;

	it = myGraph.find(origen);
	if(it == myGraph.end()){
		node *n = new node(origen);
		myGraph[origen] = n;
	}

	it = myGraph.find(destination);
	if(it == myGraph.end()){
		node *n = new node(destination);
		myGraph[destination] = n;
	}

	myGraph[origen]->nodes.push_back(myGraph[destination]);
	myGraph[destination]->nodes.push_back(myGraph[origen]);

}


void DFS(string nodeName){

	cout << nodeName << " ";

	visited.insert(nodeName);
	iterator_set it;

	for(auto node : myGraph[nodeName]->nodes){
		it = visited.find(node->name);
		if(it == visited.end())	
			DFS(node->name);
	}
}

void BFS(string nodeName){

	queue<string> myQueue;
	string name;
	iterator_set it;

	myQueue.push(nodeName);
	visited.insert(nodeName);

	while(myQueue.empty() == false){

		name = myQueue.front();
		cout << name << " ";
		myQueue.pop();

		for(auto node : myGraph[name]->nodes){

			it = visited.find(node->name);
			if(it == visited.end()){
				visited.insert(node->name);
				myQueue.push(node->name);
			}
		}
	}
}

void DFSiterative(string nodeName){

	stack<string> myStack;
	iterator_set it;
	string name;

	myStack.push(nodeName);
	visited.insert(nodeName);

	while(!myStack.empty()){

		name = myStack.top();
		cout << name << " ";
		myStack.pop();

		for(auto node : myGraph[name]->nodes){

			it = visited.find(node->name);
			if(it == visited.end()){
				visited.insert(node->name);
				myStack.push(node->name);
			}
		}
	}
}


int main(){

	freopen("input.txt","r",stdin);//redirects standard input

	
	vector< pair<list<int>,bool> > myGraph(5);
	string origen, destination;

	for(int i=0; i<5; i++){
		cin >> origen;
		cin >> destination;
		addNode(origen,destination);
	}

	DFS("S0");cout << endl;
	visited.clear();
	BFS("S0");cout << endl;
	visited.clear();
	DFSiterative("S0");cout << endl;


	return 0;
}