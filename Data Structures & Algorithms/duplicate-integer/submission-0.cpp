class Solution {
private:
    unordered_map<int, int> umap; /* (key, count) */
public:
    bool hasDuplicate(vector<int>& nums) {
        for( int idx = 0; idx < nums.size(); idx++ )
            {
            if( umap.contains( nums[ idx ] ) )
                {
                return true;
                }
            umap[ nums[ idx ] ]++;
            }

        return false;
    }
};