#include<iostream>
using namespace std;

#include<vector>
#include<iterator>
#include<queue>
class Solution {
public:

    #define P pair<int, int>

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>>adj;

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>d1(n + 1, INT_MAX);
        vector<int>d2(n + 1, INT_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 1});

        while(!pq.empty()){

            int timePassed = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(n == node && d2[n] != INT_MAX)
                return d2[n];


            int div = timePassed/change;

            if(div % 2 == 1){
                timePassed = change * (div + 1);
            }

            for(auto it : adj[node]){
                if(timePassed + time < d1[it]){
                    d2[it] = d1[it];
                    d1[it] = timePassed + time;
                    pq.push({timePassed + time, it});
                } else if (d2[it] > timePassed + time && d1[it] != timePassed + time){
                    d2[it] = timePassed + time;
                    pq.push({timePassed + time, it});
                }
            }

        }

        return -1;
    }
};