
// COMSC-210 | Lab 29 | Jonvianney Maglasang

// Started November 12, 2026 at 7:10 PM
// Finished November 12, 2026 at 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 7;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates alias 'Pair' for the pair<int,int> data type

class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges) {
        // resize the vector to hold SIZE elements of type vector<Edge>
        adjList.resize(SIZE);

        // add edges to the directed graph
        for (auto &edge: edges) {
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
    void printGraph() {
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << i << " --> ";
            for (Pair v : adjList[i])
                cout << "(" << v.first << ", " << v.second << ") ";
            cout << endl;
        }
    }

    // Depth-first search from 'start' looking for 'target'.
    // Prints the order nodes are visited; returns true if target is found.
    bool dfs(int start, int target) {
        if (!validNode(start) || !validNode(target)) {
            cout << "Invalid start or target node." << endl;
            return false;
        }
        vector<bool> visited(SIZE, false);
        cout << "DFS visit order: ";
        bool found = dfsHelper(start, target, visited);
        cout << endl;
        cout << (found ? "Found " : "Did not find ") << target
             << " starting from " << start << endl;
        return found;
    }
 
    // Breadth-first search from 'start' looking for 'target'.
    // Prints the order nodes are visited; returns true if target is found.
    bool bfs(int start, int target) {
        if (!validNode(start) || !validNode(target)) {
            cout << "Invalid start or target node." << endl;
            return false;
        }
        
        vector<bool> visited(SIZE, false);
        queue<int> q;
 
        visited[start] = true;
        q.push(start);
 
        cout << "BFS visit order: ";
        bool found = false;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
 
            if (node == target) {
                found = true;
                break;
            }
            for (Pair neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;  // mark when queued
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
        cout << (found ? "Found " : "Did not find ") << target << " starting from " << start << endl;
        return found;
    }

private:
    bool validNode(int n) { return n >= 0 && n < SIZE; }
 
    bool dfsHelper(int node, int target, vector<bool> &visited) 
    {
        visited[node] = true;
        cout << node << " ";
 
        if (node == target)  {return true; }
 
        for (Pair neighbor : adjList[node]) 
        {
            if (!visited[neighbor.first]) 
            {
                if (dfsHelper(neighbor.first, target, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,1,12},{0,2,8},{0,3,21},{2,3,6},{2,6,2},{5,6,6},{4,5,9},{2,4,4},{2,5,5}
    };

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();

    return 0;
}
