#include <iostream>
#include <vector>
using namespace std ;

vector<vector<int>> createGraph (int order, vector<vector<int>> &edges) {
	vector<vector<int>> matrix (order, vector<int> (order, 0)) ;
	for (int i = 0 ; i < edges.size() ; i++) {
		vector<int> edge = edges[i] ;
		int source = edge [0] ;
		int destination = edge [1] ;
		matrix [source][destination] = 1 ;
		matrix [destination][source] = 1 ;
	}
	return matrix ;
}

int main () {
	vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}, {1,3}, {2,3}} ;
	int siz = edges.size() -1 ;
	vector<vector<int>> matRes = createGraph (siz, edges) ;
	
	cout << "Adjacency matrix representation: \n" ;
	for (int i = 0 ; i < siz ; i++) {
		for (int j = 0 ; j < siz ; j ++) {
			cout << matRes[i][j] << " " ;
		}
		cout << "\n" ;
	}
	return 100 ;
}