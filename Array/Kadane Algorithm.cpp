// Leetcode Maximum Sub Array Sum

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int i : nums)
        {
            currSum += i;

            maxSum = max(currSum, maxSum);

            if (currSum < 0)
            {
                currSum = 0;
            }
        }

        return maxSum;
    }
};

/*
Kadane's Algorithm ek Dynamic Programming approach hai.

currSum me phele arr[0] tak k indexes ka sum aya hum ne max se comapre kr k max rkh liya k ab tak ka maximum kitna chal rhaa ha 
aise hi jaise jaise indexes age brhen ge waise waise currSum me arr k us specific idnex tak ak sum ho ga

suppsoe arry ah 4 elements ki 
currSum me phele arr[0] aya max se commpare howa or obvious wohi max Sum ban gaya 
ab arr[1] tak ka currSum me aya or max me ab tak ak max pra ho ga aise end tak kam done 

Agar currSum negative ho jaye, toh usay 0 kar dete hain,
kyunke negative sum ko aage carry karna kisi future subarray ke
sum ko faida nahi dega.

Important:
maxSum ko INT_MIN se initialize karte hain, 0 se nahi,
kyunke agar array mein saare numbers negative hon toh bhi
humein sabse bara negative number return karna hota hai.

Example:
[-2, -3, -1]

Answer = -1

Time Complexity: O(n)
Space Complexity: O(1)
*/
