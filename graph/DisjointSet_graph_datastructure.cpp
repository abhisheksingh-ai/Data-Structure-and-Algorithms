#include<iostream>

using namespace std;

class DisjointSet{
    public:
        // Data members
        vector<int> rank, parent;

        //constructor
        DisjointSet(int n){
            rank.resize(n+1);
            parent.resize(n + 1);
            for (int i = 1; i < n; i++){
                parent[i] = i;
            }
        }

        // find ultimate parent and do path compression
        int findUPar(int node){
            if (node == parent[node]){
                // root node
                return node;
            }
            // path compression
            return parent[node] = findUPar(parent[node]);
        }

        //UnionByRank. --> Addition of new edges based on rank 
        void UnionByRank(int u, int v){
            //1. find ultimate parent
            int ultp_u = findUPar(u);
            int ultp_v = findUPar(v);

            if (ultp_u == ultp_v) return;

            // Check the ranks of its ultimate parent
            int rank_ultp_u = rank[ultp_u];
            int rank_ultp_v = rank[ultp_v];

            // cases on which we will add the edges 
            if(rank_ultp_u > rank_ultp_v){
                rank[ultp_u]++;
                parent[ultp_v] = ultp_u;
            }else if(rank_ultp_u > rank_ultp_v){
                rank[ultp_v]++;
                parent[ultp_u] = ultp_v;
            }
            else
            {
                rank[ultp_u]++;
                parent[ultp_v] = ultp_u;
            }
        }
};

int main(){
    DisjointSet ds(7);

    ds.UnionByRank(1, 2);
    ds.UnionByRank(3,4);
    ds.UnionByRank(4,7);
    ds.UnionByRank(5,6);
    ds.UnionByRank(1, 2);

    // check wheather 3 and 4 are in same component
    if(ds.findUPar(3) == ds.findUPar(6)){
        cout << "Same component" << endl;
    }else{
        cout << "Different component" << endl;
    }

    return 0;
}
