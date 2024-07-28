#include<iostream>
using namespace std;

#include<vector>
#include<iterator>

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        
        int cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
        
        for(auto it : nums){
            
            if(it / 10 == 0){
                cnt1++;
                sum1 += it;
            }
            
            if(it / 10 > 0){
                cnt2++;
                sum2 += it;
            }
            
        }
        
        
        if(sum2 != sum1){
            return true;
        }
        
        return false;
        
    }
};