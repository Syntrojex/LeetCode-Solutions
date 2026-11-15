class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // Sab se pehle intervals ko starting point ke mutabiq sort kar diya.
        sort(intervals.begin(), intervals.end());

        // Final merged intervals store karne ke liye naya vector banaya.
        vector<vector<int>> ans;

        // Saare intervals ko one by one traverse karenge.
        for (int i = 0; i < intervals.size(); i++)
        {
            // Agar ans empty hai ya current interval previous interval
            // ke saath overlap nahi karta, toh ise simply insert kar do.
            if (ans.empty() || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                // Agar overlap hai toh previous interval ka start
                // minimum value ke mutabiq update kar do.
                ans.back()[0] = min(ans.back()[0], intervals[i][0]);

                // Previous interval ka end maximum value ke mutabiq update kar do.
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        // Saare overlapping intervals merge hone ke baad final vector return kar do.
        return ans;
    }
};
