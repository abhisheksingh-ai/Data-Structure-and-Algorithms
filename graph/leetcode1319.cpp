
//Approach-> Find the number of distributed clusters using DFS.

class Solution {
public:

    void buildGrpah(vector<vector<int>>& connections, vector<vector<int>>& graph){
        for(auto &v: connections){
            int a = v[0];
            int b = v[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    void dfs(int node, vector<int>& visited, vector<vector<int>>& graph, int& size){
        // visit the node first
        visited[node] = 1;
        // add into the components 
        size+=1;
        // visits its neighbour nodes 
        for(auto v: graph[node]){
            if(visited[v]==0){
              dfs(v, visited, graph, size);
            }
        }
    }

    vector<int> findComponents(int n, vector<vector<int>>& graph){
        vector<int>componentSize;
        //All nodes are unvisited right now 
        vector<int>visited(n, 0);

        for(int node = 0; node < n; node++){
            if (visited[node] == 0){
                // this will store all connected nodes in this component 
                int size = 1;
                //Yes this node is unvisited now so visit using dfs 
                dfs(node, visited, graph, size);
                //now add this component in final result 
                componentSize.push_back(size);
            }
        }
        return componentSize;

    }

    int makeConnected(int n, vector<vector<int>>& connections){
        if(connections.size() < n-1){
            return -1;
        }
        //Initialize graph
        vector<vector<int>> graph(n, vector<int>());
        //build the graph
        buildGrpah(connections, graph);
        // this function will give me the connected components
        vector<int> components = findComponents(n, graph);
        // total distributed clusters 
        int clusters = components.size();

        return clusters-1;
    }
};
