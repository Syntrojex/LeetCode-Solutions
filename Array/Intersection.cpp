class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Sirf yeh 2 lines add ki hain arrays ko line se lagane ke liye
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0;
        int j = 0;

        // Aapka hi logic: loop tab tak chalega jab tak dono bounds ke andar hain
        while (i < nums1.size() && j < nums2.size()) 
        {
            if (nums1[i] == nums2[j]) {
                // Sirf yeh check lagaya taaki duplicate numbers result mein do baar na jayein
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            // Agar match nahi milta, to jo chota number hai usko aage badhao
            else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};



intersection fo arrays
