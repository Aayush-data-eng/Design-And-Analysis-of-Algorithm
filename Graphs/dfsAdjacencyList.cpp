#include <iostream>
#include <vector>
using namespace std ;

int findSize (vector<vector<int>> &edges) {
	int maxVertex = -1 ;
	for (int i = 0 ; i < edges.size() ; i++) {
		if (edges[i][0] > maxVertex) maxVertex = edges[i][0] ;
		if (edges[i][1] > maxVertex) maxVertex = edges[i][1] ;
	}
	return maxVertex+1 ;
}

vector<vector<int>> adjList (int siz, vector<vector<int>> &edges) {
	vector<vector<int>> adjacencyList (siz) ;
	
	for (int i = 0 ; i < edges.size() ; i++) {
		vector<int> edge = edges[i];
		int source = edge[0] ;
		int destination = edge[1] ;
		adjacencyList[source].push_back(destination) ; 
		adjacencyList[destination].push_back(source) ; 
	}
	return adjacencyList ;
}

void displayAdj (vector<vector<int>> &adjacencyList) {
	for (int i = 0 ; i < adjacencyList.size() ; i++) {
		cout << "Neighbour/s of " << i << " is/are: " ;
		for (int j = 0 ; j < adjacencyList[i].size() ; j++) {
			cout << adjacencyList[i][j] << " ";
		}
		cout << "\n" ;
	}
}

void dfs (vector<vector<int>> &adjacencyList, int node, vector<int> &res, vector<bool> &visited) {
	res.push_back(node) ;
	visited[node] = true ;
	for (int i = 0 ; i < adjacencyList[node].size() ; i++) {
		int neighbour = adjacencyList[node][i] ;
		if (visited[neighbour] == false) {
			dfs (adjacencyList, neighbour, res, visited) ;
		}
	}
	return ;
}

int main () {
	vector<vector<int>> edges = {{0,2}, {0,3}, {0,1}, {2,4}} ;
	int siz = findSize (edges) ;
	
	vector<vector<int>>adjacencyList = adjList (siz, edges) ;
	vector<bool> visited (siz, 0) ;
	vector<int> resultant ;
	
	cout << "Our Adjacency List is represented as: \n" ;
	displayAdj(adjacencyList) ;
	
	dfs (adjacencyList, 0, resultant, visited) ;
	
	cout << "\nThe dfs traversal is as follows: " ;
	for (int i = 0 ; i < siz ; i++) {
		cout << resultant[i] << " " ;
	}
	return 100 ;
}