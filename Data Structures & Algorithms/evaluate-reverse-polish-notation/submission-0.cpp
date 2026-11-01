#include <cassert>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int res = 0;
        int idx = 0;
        string tok = " ";
        int n1, n2;

        /* perform n1 op n2 s.t. nums = [..., n1, n2] <- head */
        /* thus, nums = [..., (n1 op n2)] <- head */
        while( idx < tokens.size() )
            {
            /* get the token */
            tok = tokens[ idx ];

            /* perform op */
            if( tok == "+" )
                {
                n2 = nums.top();
                nums.pop();
                n1 = nums.top();
                nums.pop();
                nums.push( n1 + n2 );
                }
            else if( tok == "-")
                {
                n2 = nums.top();
                nums.pop();
                n1 = nums.top();
                nums.pop();
                nums.push( n1 - n2 );
                }
            else if( tok == "*" )
                {
                n2 = nums.top();
                nums.pop();
                n1 = nums.top();
                nums.pop();
                nums.push( n1 * n2 );
                }
            else if( tok == "/" )
                {
                n2 = nums.top();
                nums.pop();
                n1 = nums.top();
                nums.pop();
                assert( n2 != 0 );
                nums.push( n1 / n2 );
                }
            else
                {
                /* tok is an int not op, push to stack */
                nums.push( stoi( tok ) );
                }

            /* increment to next token */
            idx++;
            } /* end of while-loop */

        res = nums.top();
        nums.pop();
        assert( nums.empty() );
        return res;
    }
};
