#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

int findSize (vector<vector<int>> &edges) {
	int maxVertex = -1 ;
	for (int i = 0 ; i < edges.size() ; i++) {
		vector<int> edge = edges[i] ;
		if (edge[0] > maxVertex) maxVertex = edge[0] ;
		if (edge[1] > maxVertex) maxVertex = edge[1] ;
	}
	return maxVertex ;
}

vector<vector<int>> adjList (int siz, vector<vector<int>> &edges) {
	vector<vector<int>> adjacencyList (siz+1) ;
	
	for (int i = 0 ; i < edges.size() ; i++) {
		vector<int> edge = edges[i];
		int source = edge[0] ;
		int destination = edge[1] ;
		adjacencyList[source].push_back(destination) ; 
		adjacencyList[destination].push_back(source) ; 
	}
	return adjacencyList ;
}

void display (vector<vector<int>> &adjList) {
	for (int i = 0 ; i < adjList.size() ; i++) {
		cout << "The neighbours of " << i << " is/are: " ;
		for (int j = 0 ; j < adjList[i].size() ; j++) {
			cout << adjList[i][j] << " " ;
		}
		cout << "\n" ;
	}
}

vector<int> bfs (vector<vector<int>> &adjList, int vertex) {
	int siz = adjList.size() ;
	vector<int> res ;
	vector<bool> visited (siz, 0) ;
	queue<int> qu ;
	qu.push(vertex) ;
	visited[vertex] = 1 ;
	while (qu.empty() == false) {
		int node = qu.front() ;
		qu.pop() ;
		res.push_back(node) ;
		for(int i = 0 ; i < adjList[node].size() ; i++) {
			int neigh = adjList[node][i] ;
			if (visited[neigh] == false) {
				qu.push(neigh) ;
				visited[neigh] = true ;
			}
		}
	}
	return res ;
} 

int main () {
//	vector<vector<int>> edges = {{0,2}, {0,3}, {0,1}, {2,4}} ;
	vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}, {1,3}, {2,3}} ;

	int siz = findSize (edges) ;
	vector<vector<int>> list = adjList(siz, edges) ;
	cout << "This is the adjacency list representation: \n" ;
	display (list) ;
	
	vector<int> result = bfs(list, 0) ;
	cout << "The bfs traversal is as follows: " ;
	for (int i = 0 ; i < siz+1 ; i++) {
		cout << result[i] << " " ;
	}
	return 100 ;
}