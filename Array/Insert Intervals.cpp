class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval)
    {
        // Sab se pehle index ko intervals.size() rakha.
        // Iska matlab hai ke agar newInterval kisi bhi existing interval
        // se pehle fit nahi hota, toh usay end mein insert karna hai.
        int index = intervals.size();

        for (int i = 0; i < intervals.size(); i++)
        {
            // Agar newInterval ka start current interval ke start se chhota hai,
            // toh iska matlab hai ke newInterval current interval se pehle aayega.
            if (newInterval[0] < intervals[i][0])
            {
                // Jis position par newInterval fit hota hai,
                // us position ka index save kar liya.
                index = i;
                break;
            }
        }

        // Ab newInterval ko uski correct position par insert kar diya.
        // begin() vector ki starting position hoti hai.
        // begin() + index se humein woh position milti hai jahan insert karna hai.
        intervals.insert(intervals.begin() + index, newInterval);

        // Ab insertion ke baad overlapping intervals ko merge karna hai.
        // i = 1 se start kiya kyunke hum current interval ko uske previous
        // interval ke saath compare karenge.
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

                // Ab current interval previous interval mein merge ho chuka hai,
                // isliye current interval ko vector se remove kar diya.
                intervals.erase(intervals.begin() + i);

                // Yahan i++ nahi kiya kyunke erase ke baad next interval
                // automatically isi index par shift ho jata hai.
                // Isliye isi index par dobara comparison hoga.
            }
            else
            {
                // Agar overlap nahi hai toh current interval ko change
                // karne ki zaroorat nahi, ab next interval par chale jao.
                i++;
            }
        }

        // Jab saare overlapping intervals merge ho jayenge,
        // toh final updated intervals vector return kar denge.
        return intervals;
    }
};
