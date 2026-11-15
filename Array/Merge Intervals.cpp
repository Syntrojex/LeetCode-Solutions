class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // Sab se pehle intervals ko unke starting points ke mutabiq
        // ascending order mein sort kar diya.
        sort(intervals.begin(), intervals.end());

        // Ab adjacent intervals ko compare karenge.
        for (int i = 1; i < intervals.size();)
        {
            // Previous interval ka end current interval ke start se
            // bara ya equal hai toh dono intervals overlap karte hain.
            if (intervals[i - 1][1] >= intervals[i][0])
            {
                // Dono intervals mein se jo start sab se chhota hai,
                // usay previous interval ka start bana diya.
                intervals[i - 1][0] = min(intervals[i - 1][0],
                                          intervals[i][0]);

                // Dono intervals mein se jo end sab se bara hai,
                // usay previous interval ka end bana diya.
                intervals[i - 1][1] = max(intervals[i - 1][1],
                                          intervals[i][1]);

                // Current interval merge ho chuka hai,
                // isliye usay vector se remove kar diya.
                intervals.erase(intervals.begin() + i);

                // i++ nahi karenge kyunke next interval isi index par
                // shift ho chuka hai aur usay dobara check karna hai.
            }
            else
            {
                // Agar overlap nahi hai toh next interval par chale jao.
                i++;
            }
        }

        // Saare overlapping intervals merge hone ke baad
        // final vector return kar diya.
        return intervals;
    }
};
