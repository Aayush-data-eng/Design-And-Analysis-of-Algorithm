#include <iostream>
#include <vector>
#include <queue>
using namespace std ;

int findSize (vector<vector<int>> &edges) {
	int maxVertex = -1 ;
	for (int i = 0 ; i < edges.size() ; i++) {
		if (edges[i][0] > maxVertex ) maxVertex = edges[i][0] ;
		if (edges[i][1] > maxVertex ) maxVertex = edges[i][1] ;
	}
	return maxVertex+1 ;
}

vector<vector<int>> createMarix (vector<vector<int>> &edges, int order) {
	vector<vector<int>> matrix (order, vector<int> (order, 0)) ;
	
	for (int i = 0 ; i < edges.size() ; i++) {
		int source = edges[i][0] ;
		int destination = edges[i][1] ;
		matrix [source][destination] = 1 ;
		matrix[destination][source] = 1 ;
	}
	return matrix ;
}

void display (vector<vector<int>> &resmatrix) {
	int siz = resmatrix[0].size() ;
	for(int i = 0 ; i < siz ; i++) {
		for (int j = 0 ; j < siz ; j++) {
			cout << resmatrix[i][j] << " " ;
		}
		cout << "\n" ;
	}
}

vector<int> bfsByQueue (vector<vector<int>> &resmatrix, int vertex) {
	int siz = resmatrix[0].size() ; 
	vector<int> result ;
	vector<bool> visited (siz, 0) ;
	queue<int>qu ;
	qu.push(vertex) ;
	visited[vertex] = 1 ;
	while (qu.empty() == false) {
		int node = qu.front() ;
		qu.pop() ;
		result.push_back(node) ;
		for (int i = 0 ; i < siz ; i++) {
			if (resmatrix[node][i] == 1 && visited[i] == false) {
				qu.push(i) ;
				visited[i] = 1 ;
			}
		}
	}
	return result ;
}

int main () {
//	v<ectorvector<int>> edges = {{0,2}, {0,3}, {0,1}, {2,4}} ;
	vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}, {1,3}, {2,3}} ;

	int siz = findSize(edges) ;
	
	vector<vector<int>> resultantMatrix = createMarix (edges, siz) ;
	cout << "The adjacency matrix is represented as:\n" ;
	display(resultantMatrix) ;
	
	vector<int> BFS = bfsByQueue (resultantMatrix, 0) ;
	cout << "This is out BFS traversal: " ;
	for (int i = 0 ; i < siz ; i++) {
		cout << BFS[i] << " " ;
	}
}