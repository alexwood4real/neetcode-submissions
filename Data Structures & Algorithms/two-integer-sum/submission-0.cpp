class Solution {
private:
    unordered_map<int, int> umap; /* (num, idx) */
    vector<int> result;

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for( int idx = 0; idx < nums.size(); idx++ )
            {
            int diff = target - nums[ idx ];

            /* check to see if umap contains the diff */
            if( umap.contains( diff ) )
                {
                result.push_back( umap[ diff ] );
                result.push_back( idx );
                return result;
                }

            /* otherwise, add it to the map */
            umap[ nums[ idx ] ] = idx;
            }
    }
};
