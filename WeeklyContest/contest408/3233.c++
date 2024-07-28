#include<iostream>
using namespace std;

#include<vector>
#include<iterator>
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n = 100000;

        vector<bool> v(n + 1, true);
        v[0] = false;
        v[1] = false;
        vector<int> ans;

        for (int i = 2; i * i <= n; i++) {
            if (v[i] == true) {
                for (int j = i * i; j <= n; j += i) {
                    v[j] = false;
                }
            }
        }
        int cnt1 = 0;

        for(int i = 0; i <= n; i++) {
            if (v[i]) {
                if ((long long) i* (long long) i >= l && (long long)i* (long long)i <= r) {
                    cnt1++;
                }
            }
        }

        return r - l + 1 - cnt1;
    }
};
