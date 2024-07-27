#include<iostream>
using namespace std;

#include<vector>
#include<iterator>

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<pair<int, char> >v;

        for(int i = 0; i < indices.size(); i++){
            v.push_back({indices[i], s[i]});
        }

        sort(v.begin(), v.end());

        string ans = "";

        for(auto it : v){
            ans.push_back(it.second);
        }

        return ans;
    }
};