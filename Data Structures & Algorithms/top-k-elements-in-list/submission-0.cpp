class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /* count the freq of all elements */
        unordered_map<int, int> freq_map;
        for( auto& num : nums )
            {
            freq_map[ num ]++;
            }

        /* bucket to count all the numbers */
        vector<vector<int>> bucket( nums.size() + 1 );
        for( const auto& [ num, freq ] : freq_map )
            {
            bucket[ freq ].push_back( num );
            }

        /* count the numbers with the highest frequency */
        vector<int> result;
        for( int f = bucket.size() - 1; f >= 0 && result.size() < k; f-- )
            {
            for( int num : bucket[ f ] )
                {
                result.push_back( num );

                if( result.size() == k )
                    {
                    break;
                    }
                }
            }
        
        return result;
    }
};
