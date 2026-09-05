class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.length() != t.length() )
            {
            return false;
            }
        int size = s.length();

        sort( s.begin(), s.end() );
        sort( t.begin(), t.end() );

        for( int idx = 0; idx < size; idx++ )
            {
            if( s[ idx ] != t[ idx ] )
                {
                return false;
                }
            }

        return true;
    }
};
