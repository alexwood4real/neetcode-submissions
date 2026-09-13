class Solution {
public:

    string encode(vector<string>& strs) {
        /* parse through the vector of strings */
        string e_str = "";
        for( string str : strs )
            {
            /* encode the string <size>#<string>*/
            int size = str.length();
            e_str += to_string( size ) + "#" + str;
            }

        return e_str;
    }

    vector<string> decode(string s) {
        vector<string> d_strs;
        int i = 0;
        while( i < s.length() )
            {
            /* parse the string for the length up to # */
            int j = i;
            while( s[ j ] != '#' )
                {
                j++;
                } /* end of inner while-loop */

            /* extract the size of the string */
            string s_len = s.substr( i, j );
            int i_len = stoi( s_len );

            /* extract the word and add it to the list */
            string word = s.substr( j + 1, i_len );
            d_strs.push_back( word );

            /* iterate */
            i = j + word.length() + 1;
            } /* end of outer while-loop */

        return d_strs;
    }
};
