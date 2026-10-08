class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /* transform the list of nums into a set with no duplicates */
        unordered_set<int> uset( nums.begin(), nums.end() );

        /* iterate through the set */
        int result = 0;
        for( int elm : uset )
            {
            /* if the element is not the start of a sequence, continue */
            if( uset.contains( elm - 1 ) )
                {
                continue;
                }

            /* otherwise, elm is a candidate. count the sequence length */
            int seq = 0;
            int curr = elm;
            while( uset.contains( curr ) )
                {
                seq++;
                curr++;
                }

            /* keep the max value */
            result = max( result, seq );
            }   

        return result;
    }
};