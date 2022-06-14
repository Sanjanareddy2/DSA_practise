/*BFS can be used to solve it using the idea of topological sort. If topological sorting is possible, it means there is no cycle and it is possible to finish all the tasks.
BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we have found one. We set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of all its neighbors by 1. This process will be repeated for n (number of nodes) times. If we have not returned false, we will return true.

*/

// A BFS based solution to check if we can finish
// all tasks or not. This solution is mainly based
// on Kahn's algorithm.
#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int> >
make_graph(int numTasks,
		vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites)
		graph[pre.second].insert(pre.first);
	return graph;
}

// Finds in-degree of every vertex
vector<int>
compute_indegree(vector<unordered_set<int> >& graph)
{
	vector<int> degrees(graph.size(), 0);
	for (auto neighbors : graph)
		for (int neigh : neighbors)
			degrees[neigh]++;
	return degrees;
}

// Main function to check whether possible to finish all
// tasks or not
bool canFinish(int numTasks,
			vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph
		= make_graph(numTasks, prerequisites);
	vector<int> degrees = compute_indegree(graph);
	for (int i = 0; i < numTasks; i++) {
		int j = 0;
		for (; j < numTasks; j++)
			if (!degrees[j])
				break;
		if (j == numTasks)
			return false;
		degrees[j] = -1;
		for (int neigh : graph[j])
			degrees[neigh]--;
	}
	return true;
}

int main()
{
	int numTasks = 4;
	vector<pair<int, int> > prerequisites;
	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));
	if (canFinish(numTasks, prerequisites)) {
		cout << "Possible to finish all tasks";
	}
	else {
		cout << "Impossible to finish all tasks";
	}

	return 0;
}
