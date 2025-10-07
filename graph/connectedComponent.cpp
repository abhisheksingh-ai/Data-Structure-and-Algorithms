#include<iostream>

using namespace std;

vector<vector<int>> buildGraph(int v,vector<vector<int>> &edges) {
    vector<vector<int>> graph(v + 1, vector<int>()); // [[],[],...6[]]
    for(auto &edge: edges){
        int u = edge[0];
        int v = edge[1];
        // u---v node
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

void dfs(vector<vector<int>> &graph, int node, vector<int>& visited, vector<int> &component){
    // visit the node
    visited[node] = 1;

    // add in component
    component.push_back(node);

    //visit its neighbour
    for(auto u: graph[node]){
        if(visited[u] == 0){
            dfs(graph, u, visited, component);
        }
    }
}

vector<vector<int>> getConnectedComp(int v,vector<vector<int>> &edges){
    //graph or adj list 
    vector<vector<int>> graph = buildGraph(v, edges);

    // to store the result
    vector<vector<int>> res;

    //visited array
    vector<int> visited(v + 1, 0);

    for (int node = 1; node < v + 1; node++){

        // if this node has not been visited, then visit this and all its neighbour nodes
        if(visited[node] == 0){

            // collect all node that are connected to it
            vector<int> component;

            // call dfs
            dfs(graph, node, visited, component);

            res.push_back(component);
        }
    }
    return res;
}

int main(){
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 5}};
    int v = 5;
    vector<vector<int>> result = getConnectedComp(v, edges);
    
    for(auto v: result){
        for(auto u:v){
            cout << u << ", ";
        }
        cout << endl;
    }
    return 0;
}
