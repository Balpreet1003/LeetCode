class Solution {
public:

    string findDifferentBinaryString(vector<string>& nums) {
        const int size = nums.size();

        sort(nums.begin(), nums.end());

        int pointer = 0;

        for(int i = 0; i < size; ++i) {
            unsigned long decimalValue = bitset<16>(nums[i]).to_ulong();

            if(decimalValue == pointer)
                pointer++;
            else
                return bitset<16>(pointer).to_string().substr(16 - size);
        }
        return bitset<16>(pointer).to_string().substr(16 - size);
    }
};