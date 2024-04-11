class Solution {
public:
    string finalString(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++) 
        {
            // If found 'i' reverse the string otherwise add to answer
            if(s[i] != 'i') 
                ans += s[i];
            else
                reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};
