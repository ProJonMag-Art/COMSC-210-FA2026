
// COMSC-210 | Lab 29 | Jonvianney Maglasang
 
// Started November 12, 2026 at 7:10 PM
// Finished November 12, 2026 at 
 
// Neural Network Architecture Analyzer
// Each graph node is a layer/block in a small neural network with skip
// connections (like a simplified ResNet). Each edge is a connection between
// two layers, and its weight is the connection strength. Weights are stored
// as integers in units of 0.01 (so 12 means 0.12).
// The graph is undirected: the same connection carries activations forward
// AND gradients backward during training.
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
 
using namespace std;
 
const int SIZE = 9;
 
// Name of the layer that each node number represents
const string layerNames[SIZE] = 
{
    "Input Layer",          // 0
    "Normalization Layer",  // 1
    "Bias Unit",            // 2
    "Residual Block",       // 3
    "Hidden Layer 1",       // 4
    "Dropout Layer",        // 5
    "Attention Layer",      // 6
    "Hidden Layer 2",       // 7
    "Output Layer"          // 8
};
 
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
 
    // Print the graph's adjacency list as a network topology
    void printNetwork() 
    {
        cout << "Neural Network Architecture Topology:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < SIZE; i++) 
        {
            cout << "Node " << i << " (" << layerNames[i] << ") connects to:" << endl;
            for (Pair v : adjList[i])
                cout << "Node " << v.first << " (" << layerNames[v.first]
                     << ") - Weight: " << v.second / 100.0 << endl;
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
        vector<int> parent(SIZE, -1), parentWeight(SIZE, 0);
 
        cout << "Signal Path Trace (DFS) from " << label(start)
             << " to " << label(target) << ":" << endl;
        cout << "Purpose: Tracing one deep signal/gradient path through the network" << endl;
        cout << "===============================================================" << endl;
 
        // Recursively prints the path of travelled nodes
        bool found = dfsHelper(start, target, visited, parent, parentWeight);
        printResult(found, target, parent, parentWeight);
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
        vector<int> parent(SIZE, -1), parentWeight(SIZE, 0), depth(SIZE, 0);
        queue<int> q;
 
        cout << "Forward-Pass Layer Inspection (BFS) from " << label(start)
             << " to " << label(target) << ":" << endl;
        cout << "Purpose: Analyzing layers by depth (connections away from the source)" << endl;
        cout << "====================================================================" << endl;
 
        visited[start] = true;
        q.push(start);
 
        bool found = false;
 
        // Loop through queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << "Checking " << label(node) << " [Depth " << depth[node] << "]" << endl;
 
            // Check if node is found
            if (node == target) 
            {
                cout << "  ** Target reached **" << endl;
                found = true;
                break;
            }
 
            // Add unchecked neighbors to queue
            for (Pair neighbor : adjList[node]) 
            {
                if (!visited[neighbor.first]) 
                {
                    visited[neighbor.first] = true;  // mark when queued
                    parent[neighbor.first] = node;
                    parentWeight[neighbor.first] = neighbor.second;
                    depth[neighbor.first] = depth[node] + 1;
                    q.push(neighbor.first);
                    cout << "Next layer: " << label(neighbor.first)
                         << " - Weight: " << neighbor.second / 100.0 << endl;
                }
            }
        }
        printResult(found, target, parent, parentWeight);
        return found;
    }

    // Shortest path from 'start' to 'target' using Dijkstra's algorithm.
    // Direction is ignored (the graph is undirected) and the path with the
    // lowest total weight is chosen. Returns true if target is reachable.
    bool shortestPath(int start, int target) 
    {
        if (!validNode(start) || !validNode(target)) 
        {
            cout << "Invalid start or target node." << endl;
            return false;
        }
 
        const int INF = 1000000;  // stands in for "no route found yet"
        vector<int> dist(SIZE, INF);
        vector<int> parent(SIZE, -1), parentWeight(SIZE, 0);
        vector<bool> finalized(SIZE, false);
 
        // Min-heap of (total distance so far, node), smallest distance first
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
 
        cout << "Shortest-Route Analysis (Dijkstra) from " << label(start)
             << " to " << label(target) << ":" << endl;
        cout << "Purpose: Finding the route with the lowest total weight (direction ignored)" << endl;
        cout << "========================================================================" << endl;
 
        dist[start] = 0;
        pq.push(make_pair(0, start));
        bool found = false;
 
        while (!pq.empty()) 
        {
            Pair top = pq.top();
            pq.pop();
            int d = top.first;
            int node = top.second;
 
            // Skip outdated queue entries for nodes already finalized
            if (finalized[node]) { continue; }
            finalized[node] = true;
 
            cout << "Finalizing " << label(node) << " [Distance " << d / 100.0 << "]" << endl;
 
            if (node == target) 
            {
                cout << "  ** Target reached **" << endl;
                found = true;
                break;
            }
 
            // Check whether going through this node gives a cheaper route to a neighbor
            for (Pair neighbor : adjList[node]) 
            {
                int next = neighbor.first;
                int newDist = d + neighbor.second;
 
                if (!finalized[next] && newDist < dist[next]) 
                {
                    dist[next] = newDist;
                    parent[next] = node;
                    parentWeight[next] = neighbor.second;
                    pq.push(make_pair(newDist, next));
                    cout << "Cheaper route to " << label(next)
                         << " - Distance: " << newDist / 100.0 << endl;
                }
            }
        }
        printResult(found, target, parent, parentWeight);
        return found;
    }
 
private:
    bool validNode(int n) { return n >= 0 && n < SIZE; }
 
    // Layer name plus node number, e.g. "Input Layer (Node 0)"
    string label(int n) { return layerNames[n] + " (Node " + to_string(n) + ")"; }
 
    bool dfsHelper(int node, int target, vector<bool> &visited,
                   vector<int> &parent, vector<int> &parentWeight) 
    {
        // Updates visited vector
        visited[node] = true;
 
        // Prints node contents
        cout << "Inspecting " << label(node) << endl;
 
        if (node == target)  
        {
            cout << "  ** Target reached **" << endl;
            return true; 
        }
 
        // Shows every connection the signal could take from this layer
        for (Pair neighbor : adjList[node]) 
        {
            if (!visited[neighbor.first])
                cout << "  → Signal may propagate to " << label(neighbor.first)
                     << " - Weight: " << neighbor.second / 100.0 << endl;
        }
 
        // If neighbors haven't been visited yet
        for (Pair neighbor : adjList[node]) 
        {
            if (!visited[neighbor.first]) 
            {
                // Remembers how we got to this neighbor so the path can be rebuilt
                parent[neighbor.first] = node;
                parentWeight[neighbor.first] = neighbor.second;
 
                // Recursively run dfsHelper to eventually find a target or return false
                if (dfsHelper(neighbor.first, target, visited, parent, parentWeight)) { return true; }
            }
        }
        return false;
    }
 
    // Rebuilds the path from the parent links and prints a summary
    void printResult(bool found, int target, const vector<int> &parent,
                     const vector<int> &parentWeight) 
    {
        cout << "---------------------------------------------------------------" << endl;
        if (!found) 
        {
            cout << "No path found to " << label(target) << "." << endl;
            return;
        }
 
        vector<int> path;
        int total = 0;
        for (int n = target; n != -1; n = parent[n]) 
        {
            path.push_back(n);
            total += parentWeight[n];
        }
        reverse(path.begin(), path.end());
 
        cout << "Path found (" << path.size() - 1 << " connections): ";
        for (size_t i = 0; i < path.size(); i++)
            cout << layerNames[path[i]] << (i + 1 < path.size() ? " -> " : "");
        cout << endl;
        cout << "Total path weight: " << total / 100.0 << endl;
    }
};
 
int main() 
{
    // Shows weights with two decimal places (12 -> 0.12)
    cout << fixed << setprecision(2);
 
    // Creates a vector of graph edges/weights
    vector<Edge> edges = 
    {
        // (x, y, w) —> connection between layer x and layer y with strength w/100
        {0,1,12},{0,2,8},{0,3,21},{8,5,3},{4,3,8},{5,4,2},{1,4,13},{3,7,4},{4,8,19},{8,1,1},{7,6,26},{6, 4, 6}
    };
 
    // Creates graph
    Graph graph(edges);
 
    // Prints adjacency list representation of graph
    graph.printNetwork();
    cout << endl;
 
    graph.dfs(2, 8);
    cout << endl;
    graph.bfs(0, 5);
    cout << endl;
    for(int i = 0; i < SIZE; i++)
    {
        graph.shortestPath(0, i);
        cout << endl;
    }
 
    return 0;
}
