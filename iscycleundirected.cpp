/*Run a DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph. 
DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. 
A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in the tree produced by DFS. 
To find the back edge to any of its ancestors keep a visited array and if there is a back edge to any visited node
 then there is a loop and return true.*/

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
 
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
 
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[*i]) {
            if (isCyclicUtil(*i, visited, v))
                return true;
        }
 
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
            return true;
    }
    return false;
}
 
// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{
 
    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++) {
 
        // Don't recur for u if
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}
 