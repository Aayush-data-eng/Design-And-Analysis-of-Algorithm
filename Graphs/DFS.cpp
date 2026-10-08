#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

int findSize (vector<vector<int>> &edges) {
	int maxVertex = -1 ;
	for (int i = 0 ; i < edges.size() ; i++) {
		if (edges[i][0] > maxVertex) maxVertex = edges[i][0] ;
		if (edges[i][1] > maxVertex) maxVertex = edges[i][1] ;
	}
	return maxVertex + 1 ;
}

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

void diaplay (vector<vector<int>> &matres) {
	cout << "Adjacency matrix representation: \n" ;
	for (int i = 0 ; i < matres[0].size() ; i++) {
		for (int j = 0 ; j < matres[0].size() ; j ++) {
			cout << matres[i][j] << " " ;
		}
		cout << "\n" ;
	}
}

void dfs (vector<vector<int>> &matres, int vertex, vector<bool> &visited, vector<int> &res) {
	res.push_back(vertex) ;
	visited[vertex] = true ;
	
	for ( int i = 0 ; i < matres[0].size() ; i++) {
		if (matres[vertex][i] == 1 && visited[i] == false) {
			dfs (matres, i, visited, res) ;
		}
	}
	return ;
}

void dfsByStack (vector<vector<int>> &matres, int vertex, vector<bool> &visited, vector<int> &res) {
	int siz = matres[0].size() ;
	stack<int> st ;
	st.push(vertex) ;
	visited[vertex] = 1 ;
	while (!st.empty()) {
		int node = st.top() ;
		st.pop() ;
		res.push_back(node) ;
		for (int i = siz ; i >=0 ; i--) {
//			int neigh = matres[node][i] ;
			if (matres[node][i] == 1 && visited[i] == false) {
				st.push(i) ;
				visited[i] = 1 ;
			}
		}
	}
}

int main () {
//	vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}, {1,3}, {2,3}} ;
	vector<vector<int>> edges = {{0,2}, {0,3}, {0,1}, {2,4}} ;
	int siz = findSize(edges);
	
	vector<vector<int>> matRes = createGraph (siz, edges) ;
	diaplay(matRes) ;
	cout << "\n" ;
	
	int len = matRes[0].size() ;
	
	vector<int> res ;
	vector<bool> visited (len , 0) ;
	
//	dfs (matRes, 0, visited, res) ;
	dfsByStack (matRes, 0, visited, res) ;
	cout << "The required DFS treaverasal is: " ; 
	for (int i = 0 ; i < len ; i++) {
		cout << res[i] << " " ;
	}
	return 100 ;
}