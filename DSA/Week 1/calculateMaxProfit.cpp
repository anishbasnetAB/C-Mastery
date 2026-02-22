//leetcode : 121 best time to buy/sell stock
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_price{prices[0]};
        int max_profit{};
        
        for(int i=1; i<prices.size();i++)
        {
            if(prices[i]<=min_price)
            {
                min_price=prices[i];
            }
            else
            {
                max_profit=max(max_profit, prices[i]-min_price); //main logic
            }
        };
        return max_profit;
        
    }
    
};
int main() {
    Solution sol;
    
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices1) << endl; // Expected: 5
    
    vector<int> prices2 = {7,6,4,3,1};
    cout << sol.maxProfit(prices2) << endl; // Expected: 0
    
    return 0;
}