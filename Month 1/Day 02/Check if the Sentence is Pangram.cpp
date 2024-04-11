class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26, 0);
        // Storing the frequency of each character 
        for(int i = 0; i < sentence.size(); i++)
            freq[sentence[i] - 'a']++; 
        
        // If any character is missing, return false
        for(int i = 0; i < 26; i++)
            if(freq[i] == 0)
                return false;
        return true;
    }
};
