#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;


struct vertex{
	string name;
	list< pair<int,vertex*> > adj;
	vertex(string n){name = n;} 
};

class GraphAdj{

private:
	typedef unordered_map<string,vertex*> gmap;
	typedef unordered_map<string,vertex*>::const_iterator iterator;
	typedef unordered_set<string>::iterator itSet;

	gmap graph;

	void DFStraversal(string&, unordered_set<string>&);

public:
	void addVertex(string&);
	void addEdge(string&, string&, int);
	void DFSrecursive(string);
	void DFSiterative(string);
	void BFS(string);

};

void GraphAdj::addVertex(string &name){

	iterator it=graph.find(name);

	if (it==graph.end()){
		vertex *v = new vertex(name);
		graph[name]=v;
	}
	else cout << "The node already exist.\n";

}

void GraphAdj::addEdge(string &origin, string &destination, int cost){

	iterator itO = graph.find(origin);
	if (itO == graph.end()){
		vertex *v = new vertex(origin);
		graph[origin] = v;
	}

	iterator itD = graph.find(destination);
	if(itD == graph.end()){
		vertex *v = new vertex(destination);
		graph[destination] = v;
	}

	vertex *v = graph[origin];
	v->adj.push_back(make_pair(cost,graph[destination]));

	// FOR UNDIRECTED GRAPH
	//v = graph[destination];
	//v->adj.push_back(make_pair<cost,origin>);

}


void GraphAdj::DFStraversal(string &node, unordered_set<string> &visited){

	visited.insert(node);
	itSet it;

	cout << node << "\n";

	for(auto const& node : graph[node]->adj){

		it = visited.find(node.second->name);
		if(it == visited.end())
			DFStraversal(node.second->name,visited);
	}
}

void GraphAdj::DFSrecursive(string node){

	unordered_set<string> visited;
	DFStraversal(node,visited);
}

void GraphAdj::DFSiterative(string node){

	string vertex;
	unordered_set<string> visited;
	stack<string> myStack;
	itSet it;

	visited.insert(node);
	myStack.push(node);


	while(!myStack.empty()){

		vertex = myStack.top();
		cout << vertex << "\n";
		myStack.pop();

		for(auto const& node : graph[vertex]->adj){
			
			it = visited.find(node.second->name);
			if(it == visited.end()){
				visited.insert(node.second->name);
				myStack.push(node.second->name);
			}
			
		}
	}
}

void GraphAdj::BFS(string node){

	unordered_set<string> visited;
	queue<string> myQueue;
	string vertex;
	itSet it;

	visited.insert(node);
	myQueue.push(node);


	while(!myQueue.empty()){

		vertex = myQueue.front();
		cout << vertex << "\n";
		myQueue.pop();

		for(auto const &node : graph[vertex]->adj){

			it = visited.find(node.second->name);
			if(it == visited.end()){
				visited.insert(node.second->name);
				myQueue.push(node.second->name);
			}
		}
	}
}


int main(int argc, char **argv){


    freopen("input.txt", "r", stdin);

    int total;
    string orig, dest;
    GraphAdj myGraph;

    cin >> total;

    for (int i=0; i<total; i++){
    	cin >> orig;
    	cin >> dest;
    	myGraph.addEdge(orig,dest,0);
    }

    myGraph.DFSiterative("S0");
    cout << endl;
    myGraph.DFSrecursive("S0");
    cout << endl;
    myGraph.BFS("S0");


	return 0;
}