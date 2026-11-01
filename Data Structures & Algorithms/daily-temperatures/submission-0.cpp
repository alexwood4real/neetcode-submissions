class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<int> stk;
        int idx;
        int size = temperatures.size();
        vector<int> result( size, 0 );

        /* index through the temperatures */
        for( idx = 0; idx < size; idx++ )
            {
            /* get current temperature */
            int curr_temp = temperatures[ idx ];

            /* pop stack while not empty AND current temperature is greater than top temperature */
            while( !stk.empty()
             && curr_temp > temperatures[ stk.top() ] )
                {
                int top_idx = stk.top();
                stk.pop();
                result[ top_idx ] = idx - top_idx;
                } /* end of while-loop */

            /* push current temp idx for warmer day */
            stk.push( idx );
            } /* end of for-loop */

        /* return result */
        return result;  
    }
};
