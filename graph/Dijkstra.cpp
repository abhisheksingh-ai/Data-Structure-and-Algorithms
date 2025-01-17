#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;
//graph


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > graph(n + 1);
    for (int i = 0; i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        //u----->v, weight is w
        graph[u].push_back({v, w});
    }
    vector<int> dist(n + 1, 1e9);
    dist[1] = 0;
    vector<bool> visited(n + 1, 0);

    //priority queue
    priority_queue<pair<int, int>> pq; //{-dist , weight}
    pq.push({-dist[1], 1}); //now push its neighbour

    while(!pq.empty()){
        int curr = pq.top().second; // i got the curr node
        pq.pop();

        if(visited[curr] == 1) continue;

        visited[curr] = 1;

        for(auto it: graph[curr]){
            int v = it.first;
            int w = it.second;

            if(dist[v] > dist[curr] + w){//edge relaxation
                dist[v] = dist[curr] + w;
                pq.push({-dist[v], v});
            }
        }
    }

    //printing the distance
    for (int i = 1; i <= n;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}
