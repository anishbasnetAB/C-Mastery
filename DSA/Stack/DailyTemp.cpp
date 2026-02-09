class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);  // Initialize with all 0s
        stack<int> st;  // Stack to store indices
        
        for(int i=0; i<n; i++)
        {
            // While current temp is warmer than temp at stack top
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex;
            }
            
            // Push current index onto stack
            st.push(i);
        }
        
        return result;
    }
};