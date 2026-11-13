#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;

bool cmp(pair<float,pair<int,int>> & a, pair<float,pair<int,int>> & b){
    return a.first>b.first;
}

float fractionalKnapsack(vector<pair<int, int>> & arr, int w){
    //int n=arr.size();
    vector<pair<float, pair<int,int>>> ans;
    for(int i=0;i<arr.size();i++){
        int weight=arr[i].first;
        int profit=arr[i].second;
        float r=(1.0*profit)/(1.0*weight);
        ans.push_back({r,{weight,profit}});
    }

    sort(ans.begin(),ans.end(),cmp);
    float maxProfit=0;
    for(int i=0;i<ans.size();i++){
        int weight=ans[i].second.first;
        int profit=ans[i].second.second;
        float r=ans[i].first;
        if(weight<=w){
            maxProfit+=1.0*profit;
            w-=weight;
        }else{
            maxProfit+=(float)(w*r);
            w=0;
            break;
        }
    }

    return maxProfit;
}

float FractionalKnapsack2(vector<pair<int, int>> &arr, int w)
{
    //Fractional  Knapsack using heaps
    priority_queue<pair<float, int>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        int weight = arr[i].first;
        int profit = arr[i].second;
        if (weight > 0)
        {
            float r = (float)profit / weight;
             pq.push({r,weight});
        }
    }

    float maxProfit = 0;

    while (w > 0 && pq.size() > 0)
    {
        int weight = pq.top().second;
        float r = pq.top().first;
        pq.pop();
        if (weight <= w)
        {
            maxProfit += weight * r;
            w = w - weight;
        }
        else
        {
            maxProfit += w * r;
            w = 0;
            break;
        }
    }

    return maxProfit;
}
int main()
{
    int w;
    cout << "Enter the capacity of the knapsack:" << endl;
    cin >> w;
    int n;
    cout << "Enter the number of the objects:" << endl;
    cin >> n;
    vector<pair<int, int>> v;
    cout << "enter the weight and profits of the object:" << endl;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pair<int, int> p = {x, y};
        v.push_back(p);
    }

    cout<<"Max profit will be:"<<FractionalKnapsack2(v,w)<<endl;

    cout<<"Max profit will be:"<<fractionalKnapsack(v,w)<<endl;
}