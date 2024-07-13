// Stack + Sorting + Lambda
class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<int> actualIndices(n);
        // Fill the array from 0 to n-1
        iota(actualIndices.begin(), actualIndices.end(), 0);

        stack<int> st;

        // Sorting with respect to the number line [positions of robots]
        auto lambda = [&](int &i, int &j)
        {
            return positions[i] < positions[j];
        };
        // Array will have the indices according to the positions in the number line
        sort(actualIndices.begin(), actualIndices.end(), lambda);

        for (int &currIdx : actualIndices)
        {
            // If robots are going to the right, then push the index to the stack
            if (directions[currIdx] == 'R')
                st.push(currIdx);
            else
            {
                // Otherwise keep going in the left direction until the current index robot's health is not all consumed
                while (!st.empty() && healths[currIdx] > 0)
                {
                    int topIdx = st.top();
                    st.pop();
                    // If top index robot is having greater health, decrement 1 from it, remove the other one and insert it again
                    if (healths[topIdx] > healths[currIdx])
                    {
                        healths[topIdx] -= 1;
                        healths[currIdx] = 0;
                        st.push(topIdx);
                    }
                    // Else make the health of top robot 0, decrement one from other
                    else if (healths[topIdx] < healths[currIdx])
                    {
                        healths[topIdx] = 0;
                        healths[currIdx] -= 1;
                    }
                    // Both robots are having same health, remove both
                    else
                    {
                        healths[topIdx] = 0;
                        healths[currIdx] = 0;
                    }
                }
            }
        }

        // Return the array of robots if their health is greater than 0
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (healths[i] != 0)
                ans.push_back(healths[i]);
        }
        return ans;
    }
};