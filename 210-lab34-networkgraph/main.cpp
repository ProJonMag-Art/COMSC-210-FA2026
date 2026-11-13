
// COMSC-210 | Lab 29 | Jonvianney Maglasang

// Started November 12, 2026 at 7:10 PM
// Finished November 12, 2026 at 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 9;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates alias 'Pair' for the pair<int,int> data type

class Graph 
{
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges) 
    {
        // resize the vector to hold SIZE elements of type vector<Edge>
        adjList.resize(SIZE);

        // add edges to the directed graph
        for (auto &edge: edges) 
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            // for an undirected graph, add an edge from dest to src also
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    // Print the graph's adjacency list
    void printGraph() 
    {
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < adjList.size(); i++) 
        {
            cout << i << " --> ";
            for (Pair v : adjList[i])
                cout << "(" << v.first << ", " << v.second << ") ";
            cout << endl;
        }
    }

    // Depth-first search from 'start' looking for 'target'.
    // Prints the order nodes are visited; returns true if target is found.
    bool dfs(int start, int target) 
    {
        // If either inputted nodes are invalid
        if (!validNode(start) || !validNode(target)) 
        {
            cout << "Invalid start or target node." << endl;
            return false;
        }

        vector<bool> visited(SIZE, false);
        cout << "DFS visit order: ";

        // Recursively prints the path of travelled nodes
        bool found = dfsHelper(start, target, visited);
        cout << endl;
        cout << (found ? "Found " : "Did not find ") << target << " starting from " << start << "\n" << endl;
        return found;
    }
 
    // Breadth-first search from 'start' looking for 'target'.
    // Prints the order nodes are visited; returns true if target is found.
    bool bfs(int start, int target) 
    {
        if (!validNode(start) || !validNode(target)) 
        {
            cout << "Invalid start or target node." << endl;
            return false;
        }

        vector<bool> visited(SIZE, false);
        queue<int> q;
 
        visited[start] = true;
        q.push(start);
 
        cout << "BFS visit order: ";
        bool found = false;

        // Loop through queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
 
            // Check if node is found
            if (node == target) 
            {
                found = true;
                break;
            }

            // Add unchecked neighbors to queue
            for (Pair neighbor : adjList[node]) 
            {
                if (!visited[neighbor.first]) 
                {
                    visited[neighbor.first] = true;  // mark when queued
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
        cout << (found ? "Found " : "Did not find ") << target << " starting from " << start << "\n" << endl;
        return found;
    }

private:
    bool validNode(int n) { return n >= 0 && n < SIZE; }
 
    bool dfsHelper(int node, int target, vector<bool> &visited) 
    {
        // Updates visited vector
        visited[node] = true;

        // Prints node contents
        cout << node << " ";
 
        if (node == target)  {return true; }
 
        // If neighbors haven't been visited yet
        for (Pair neighbor : adjList[node]) 
        {
            if (!visited[neighbor.first]) 
            {
                // Recursively run dfsHelper to eventually find a target or return false
                if (dfsHelper(neighbor.first, target, visited)) { return true; }
            }
        }
        return false;
    }
};

int main() 
{
    // Creates a vector of graph edges/weights
    vector<Edge> edges = 
    {
        // (x, y, w) —> edge from x to y having weight w
        {0,1,12},{0,2,8},{0,3,21},{8,5,3},{4,3,8},{5,4,2},{1,4,13},{3,7,4},{4,8,19},{8,1,1},{7,6,26},{6, 4, 6}
    };

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();

    graph.dfs(0, 5);
    graph.bfs(0, 5);
    graph.dfs(2, 8);

    return 0;
}
