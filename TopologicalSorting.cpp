//Topological Sort
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<queue>

using namespace std;
bool adjecent(vector<int>* vertice,int** adj, string str) {
	int pos = str.find(" ");
	int start = 0;
	int vertex = 0;

	if (pos != string::npos) {
		vertex = stoi(str.substr(start, pos));
		start = pos + 1;
		if (vertex == 0) return 1;
	}
	else return 1;

	while (pos != string::npos) {
		pos = str.find(" ");
		int temp= stoi(str.substr(start, pos))-1;
		vertice[vertex-1].push_back(temp);
		adj[vertex - 1][temp] = 1;
		start = pos + 1;
	}
	return 0;
}

void topologicalSort(vector<int>* vertice,int** adj, int n) {
	int* indegree = new int[n];
	indegree[0]=0;

	priority_queue<int, vector<int>, greater<int>> Q;

	for (int i = 0; i < n; i++) {
		indegree[i] = vertice[i].size();
	}
	//cout << "hek" << endl;
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0) Q.push(i);

	while (!Q.empty()) {
		int u = Q.top();
		cout << u+1 << " ";
		Q.pop();

		for (int i = 0; i < n; i++) {
			if (adj[i][u]) {
				if (--indegree[i] == 0) Q.push(i);
			}
		}
	}
	cout << endl;
	return;
}
int main() {
	string filename = "input_1.txt";
	ifstream ifs(filename);
	
	if (ifs) {
		int n;
		ifs >> n;

		vector<int>* vertice = new vector<int> [n];
		
		int** adj = new int*[n];
		for (int i = 0; i < n; i++)
			adj[i] = new int[n];

		adj[0][0] = 0;
		
		while (ifs) {
			
			string str = "";
			getline(ifs, str);
			bool flag =adjecent(vertice,adj, str);
			if (flag) break; //flag indicates it enter 0 at the end or not
		}
		topologicalSort(vertice,adj,n);
		//cout << "where";
		
	}
	else cout << "Error open file" << endl;

	return 0;
}