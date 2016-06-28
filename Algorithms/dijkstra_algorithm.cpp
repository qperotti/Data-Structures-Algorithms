#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>
#include <climits>
#include <set>
#include <unordered_set>



using namespace std;

struct node{
	int label;
	vector< pair<node*,int> > neighbors;
	node(int name){label=name;};
};

unordered_map<int,node*> graph;


vector<int> minDist(10,INT_MAX);

void addNode(){

	int origin, dest;
	int cost;
	unordered_map<int,node*>::iterator it;

	cin >> origin;
	cin >> dest;
	cin >> cost;

	it=graph.find(origin);
	if(it==graph.end()){
		node *n = new node(origin);
		graph[origin]= n;
	}

	it=graph.find(dest);
	if(it==graph.end()){
		node *n = new node(dest);
		graph[dest]= n;
	}

	graph[origin]->neighbors.push_back({graph[dest],cost});
	graph[dest]->neighbors.push_back({graph[origin],cost});
}
	

void dijkstra(int source){

	
	set< pair<int,int> > act_vertices;
	unordered_set<int> visited;
	unordered_set<int>::iterator it;

	minDist[source] = 0;
	act_vertices.insert({0,source});
	

	int where, cost;

	while(!act_vertices.empty()){

		where = act_vertices.begin()->second;
		act_vertices.erase(act_vertices.begin());
		visited.insert(where);

		for(const auto &npair : graph[where]->neighbors){
			node *n = npair.first;
			int cost = npair.second;

			it = visited.find(n->label);
			if(it==visited.end()){
				if(minDist[n->label] > minDist[where]+cost){
					act_vertices.erase({minDist[n->label],n->label});
					minDist[n->label] = minDist[where] + cost; 
					act_vertices.insert({minDist[n->label],n->label});
				}
			}
		}
	}
}


int main(){

	freopen("inputG.txt","r",stdin);

	int total;
	cin >> total;

	for(int i=0; i<total; i++){
		addNode();
	}

	dijkstra(0);

	for(int i=0; i<10; i++){

		if(minDist[i]<100) cout << "S" << i << " -> " << minDist[i] << endl;


	}

	return 0;
}