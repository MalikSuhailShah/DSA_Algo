// leetCode - 841

// the set of keys inside the room tells us the neighbours of the room considering it as a graph
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> vis(n, false);
        vis[0] = true;

        queue<int> qu;
        qu.push(0);

        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto neighbour : rooms[node]){
                if(not vis[neighbour]){
                    vis[neighbour] = true;
                    qu.push(neighbour);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i]!=true) return false;
        }
        return true;
    }
};

int main()
{


}
