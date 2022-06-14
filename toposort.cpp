/*Find whether it is possible to finish all tasks or not from given dependencies


Solution: We can consider this problem as a graph (related to topological sorting) problem. All tasks are nodes of the graph and if task u is a prerequisite of task v, we will add a directed edge from node u to node v. Now, this problem is equivalent to detecting a cycle in the graph represented by prerequisites. If there is a cycle in the graph, then it is not possible to finish all tasks (because in that case there is no any topological order of tasks). Both BFS and DFS can be used to solve it.
Since pair is inconvenient for the implementation of graph algorithms, we first transform it to a graph. If task u is a prerequisite of task v, we will add a directed edge from node u to node v.
Prerequisite : Detect Cycle in a Directed Graph
Using DFS For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor… and so on. If it meets a node which was visited in the current process of DFS visit, a cycle is detected and we will return false. Otherwise it will start from another unvisited node and repeat this process till all the nodes have been visited. Note that you should make two records: one is to record all the visited nodes and the other is to record the visited nodes in the current DFS visit.
The code is as follows. We use a vector visited to record all the visited nodes and another vector onpath to record the visited nodes of the current DFS visit. Once the current visit is finished, we reset the onpath value of the starting node to false.*/

// CPP program to check whether we can finish all
// tasks or not from given dependencies.
#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int> > make_graph(int numTasks,
			vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites)
		graph[pre.second].insert(pre.first);
	return graph;
}

// A DFS based function to check if there is a cycle
// in the directed graph.
bool dfs_cycle(vector<unordered_set<int> >& graph, int node,
			vector<bool>& onpath, vector<bool>& visited)
{
	if (visited[node])
		return false;
	onpath[node] = visited[node] = true;
	for (int neigh : graph[node])
		if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
			return true;
	return onpath[node] = false;
}

// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites);
	vector<bool> onpath(numTasks, false), visited(numTasks, false);
	for (int i = 0; i < numTasks; i++)
		if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
			return false;
	return true;
}

int main()
{
	int numTasks = 4;

	vector<pair<int, int> > prerequisites;

	// for prerequisites: [[1, 0], [2, 1], [3, 2]]

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
