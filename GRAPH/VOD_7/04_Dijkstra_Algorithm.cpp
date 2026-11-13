// dijkstra works only for non negative node weights

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <queue>
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

unordered_map<int,int> dijkstra(int n,int src){
    priority_queue<pp, vector<pp> , greater<pp>> pq;
    unordered_map<int,int> mp;

    unordered_set<int> visited;
    vector<int> via(n);

    pq.push({0,src});
    for(int i=0;i<n;i++){
        mp[i]=INT_MAX;
    }

    mp[src]=0;

    while(!pq.empty()){
        pp curr = pq.top();

        int currNode = curr.second;
        int currWeight = curr.first;

        if(visited.count(currNode)){
            pq.pop();
            continue;
        }

        pq.pop();
        visited.insert(currNode);

        for(auto neighbour : graph[currNode]){
            int NeighbourNode = neighbour.first;
            int NeighbourWeight = neighbour.second;

            if(!visited.count(NeighbourNode) and 
            mp[NeighbourNode] > NeighbourWeight + mp[currNode])
            {
                pq.push({NeighbourWeight + mp[currNode], NeighbourNode});
                mp[NeighbourNode] =NeighbourWeight + mp[currNode];
                via[NeighbourNode] = currNode;
            }
        }
    }

    return mp;
}

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

    unordered_map<int,int> sp = dijkstra(n, src);
    cout<<"Shortest Distance from source to all Node ar : \n";

    for(auto curr : sp){
        cout<<curr.first<<" "<<curr.second<<"\n";
    }

    int des;
    cout<<"Enter the destination: ";
    cin>>des;

    cout<<"Shortest distance of des from src :"<< sp[des]<<"\n";



}