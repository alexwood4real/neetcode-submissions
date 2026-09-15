class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int idx;
        
        /* consider the prefix */
        int prefix = 1;
        for( idx = 0; idx < nums.size(); idx++ )
            {
            result.push_back( prefix );
            prefix *= nums[ idx ];
            }

        /* consider the postfix */
        int postfix = 1;
        for( idx = nums.size() - 1; idx >= 0; idx-- )
            {
            result[ idx ] *= postfix;
            postfix *= nums[ idx ]; 
            }

        return result;
    }
};
