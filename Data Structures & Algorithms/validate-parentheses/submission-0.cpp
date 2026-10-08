class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int idx;

        /* edge case: 1 char */
        if( s.length() == 1 )
            {
            return false;
            }

        /* otherwise, iterate through the string */
        for( idx = 0; idx < s.length(); idx++ )
            {
            if( s[ idx ] == '('
             || s[ idx ] == '['
             || s[ idx ] == '{' )
                {
                /* if the char is an opener, add to the stack */
                stk.push( s[ idx ] );
                }
            else 
                {
                /* edge case: empty stack */
                if( stk.empty() )
                    {
                    return false;
                    }

                /* otherwise, consider the top of the stack for the respective closing */
                switch( s[ idx ] )
                    {
                    case ')':
                        {
                        /* if the top of the stack is '(', pop. otherwise, invalid */
                        if( stk.top() == '(' )
                            {
                            stk.pop();
                            break;
                            }
                        return false;
                        }

                    case ']':
                        {
                        /* if the top of the stack is '[', pop. otherwise, invalid */
                        if( stk.top() == '[' )
                            {
                            stk.pop();
                            break;
                            }
                        return false;
                        }

                    case '}':
                        {
                        /* if the top of the stack is '{', pop. otherwise, invalid */
                        if( stk.top() == '{' )
                            {
                            stk.pop();
                            break;
                            }
                        return false;
                        }

                    default:
                        {
                        /* invalid closing */
                        return false;
                        }
                    }
                } /* end of if-else statement */
            } /* end of for-loop */

        /* if the stack is empty, then valid; otherwise, invalid */
        return stk.empty();
    }
};
