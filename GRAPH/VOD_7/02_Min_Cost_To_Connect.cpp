// leetcode 1584 : https://leetcode.com/problems/min-cost-to-connect-all-points/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Edge{
        int src;
        int des;
        int cost;
    };

    static bool cmp(Edge e1, Edge e2){
        return e1.cost<e2.cost;
    }

    int find(vector<int> & parent , int x){
        return parent[x]=(parent[x]==x)?x:find(parent, parent[x]);
    }

    void Union(vector<int> & parent , vector<int> & ranks, int a, int b){
        a = find(parent, a);
        b = find(parent, b);

        if(a==b){
            return ;
        }

        if(ranks[a]>ranks[b]){
            ranks[a]++;
            parent[b]=a;
        }
        else{
            ranks[b]++;
            parent[a]=b;
        }
    }

    long long int krushkal(vector<Edge> &graph, int n){

        sort(graph.begin(), graph.end(), cmp);

        vector<int> parent(n);
        vector<int> rank(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int edge_count =0;
        int i =0;
        long long int ans =0;

        while(edge_count<n-1 and i<graph.size()){

            auto curr = graph[i];
            int srcPar = find( parent, curr.src);
            int desPar = find( parent, curr.des);

            if(srcPar!=desPar){
                //include edge as this will include make cycle
                Union(parent, rank, srcPar, desPar);
                ans += (long long int)curr.cost;
                edge_count++;
            }
            i++;
        }

        return ans;

    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<Edge> graph;
        // treating index as a node
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int cost = abs(points[i][0]-points[j][0])
                            + abs(points[i][1]-points[j][1]);
                graph.push_back({i,j,cost});
            }
        }

        return krushkal(graph, n);
        
    }
};


int main (){

}