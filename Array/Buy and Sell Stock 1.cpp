class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int result = 0;
        int currMin = prices[0];

        for (int i = 0; i < prices.size(); i++)
        {
            // Ab tak ki minimum price currMin mein rakhein.
            // Agar aaj ki price is se kam hai toh currMin update kar dein.
            currMin = min(currMin, prices[i]);

            // Aaj sell karne par kitna profit hoga, woh check karein.
            // result mein hamesha maximum profit hi store rahega.
            result = max(result, prices[i] - currMin);
        }

        return result;
    }
};

/*
Approach:
- currMin mein ab tak ki minimum price store karte hain,
  taake stock lowest price par buy kar sakein.
- Har din ki price ko selling price consider karke profit nikalte hain.
- result mein har baar maximum profit store hota hai.
- End par result mein poore array ka maximum possible profit hota hai.
- Yani minimum price par buy aur uske baad kisi din sell karke
  jo maximum profit mil sakta hai, woh return hota hai.

Time Complexity: O(n)
Space Complexity: O(1)
*/
