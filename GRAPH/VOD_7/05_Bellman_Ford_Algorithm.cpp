
#include <iostream>
#include <vector>
#include <climits>
#include <list>

#define pp pair<int,int>


using namespace std;


vector<list<pp>> graph;

void add_Edge(int src, int des,int wt, bool bi_Dir=true){
    graph[src].push_back({des, wt});
    if(bi_Dir){
        graph[des].push_back({src, wt});
    }
}


vector<int> bellman_ford(int n, int src){
    vector<int> dis(n, 1e8);
    dis[src]=0;

    for(int i=0;i<n-1;i++){
        bool updated = false;

        for(int u=0; u<n;u++){
            for(auto it : graph[u]){
            int v = it.first;
            int wt = it.second;

            if(dis[u]!=1e8 && dis[u]+wt < dis[v]){
                dis[v] = dis[u] + wt;
                updated = true;
            }
        }
        }
        if(!updated) break;
    }

    // checking for the negative cycles

    for(int u =0 ;u<n;u++){
        for(auto it :graph[u]){
            int v = it.first;
            int wt = it.second;

            if(dis[u]!=1e8 && dis[u]+wt < dis[v]){
              return {-1};
            }
        }
    }

    return dis;
}


/*
more intutable

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

vector<long long> bellmanFord(
    int n, int src, vector<Edge>& edges
) {
    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(n, INF);

    dist[src] = 0;

    // Relax all edges up to V-1 times
    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;

        for (auto e : edges) {
            if (dist[e.u] != INF &&
                dist[e.u] + e.wt < dist[e.v]) {

                dist[e.v] = dist[e.u] + e.wt;
                updated = true;
            }
        }

        if (!updated) break;
    }

    // Check for a reachable negative-weight cycle
    for (auto e : edges) {
        if (dist[e.u] != INF &&
            dist[e.u] + e.wt < dist[e.v]) {
            cout << "Negative-weight cycle detected\n";
            return {};
        }
    }

    return dist;
}*/


int main (){

    int m,n;
    cin>>n>>m;
    graph.resize(n,list<pp> ());

    while(m--){
        int a,b,wt;
        cin>>a>>b>>wt;
        add_Edge(a,b,wt);
    }
    int src;
    cout<<"Enter the src:\n";
    cin>>src;

   
}