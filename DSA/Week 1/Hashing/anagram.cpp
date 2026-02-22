class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        //hash map to store frequency of each character
        unordered_map<char,int> count;

        for(char c:s) count[c]++; //counting each character in s and storing in hash map

        //checking the count and removing number from map for string t
        //if it goes to neg then it is not return false

        for(char c:t)
        {
            count[c]--;

            if(count[c]<0) return false;
        }

        return true;


    }
};