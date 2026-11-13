#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
vector<unordered_map<int, int>> graph;

void add_edge(int src, int des, int weight, bool bi_dir = true)
{
    graph[src].insert({des, weight});
    if (bi_dir)
        graph[des].insert({src, weight});
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto ele : graph[i])
        {
           
            cout << "{" << ele.first << "," << ele.second << "} ";
        }
        cout << endl;
    }
}
int main()
{
    int v;
    cin >> v;
    graph.resize(v, unordered_map<int, int>());

    int e;
    cin >> e;
    while (e--)
    {
        int src, des, weight;
        cin >> src >> des >> weight;
        add_edge(src, des, weight);
    }

    display();
}