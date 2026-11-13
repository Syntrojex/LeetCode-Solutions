class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        // Har next index ka left product, previous index ke left product ×
        // previous element hota hai.
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            left[i] = product;

            // agle element k liye left product nikala abhi wale index k product
            // x previous product
            product *= nums[i];
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            right[i] = product;

            product *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};

/*Approach:
Sab se phele sawal smjhao sawal ye kahta ha k us index ki value k ilawa baqi
sari array ka product ho ga or wo ans me us index pr place ho ga

hum ne ye kai k phele har idnex ko prka us se left k jitne elemnts the un ka
product nikala wo akise nikala wo aise nikala k hum ne product 1 consider kr
liya 0 index se phele ka left product kio k koi elemnt hota hi nhi 0 se phele ab
socha k agar 1 index k liey nikalna ho left to product x 0th index ki value hona
chhaiye aise krte krte left agaya right agaya

end pr answer me us index ka left ro right product mulitply kr k rkh diya

*/
