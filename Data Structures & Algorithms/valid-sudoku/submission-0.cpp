class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /* arrys to hold values for each row, col, and square */
        bool rows[ 9 ][ 9 ] = {};
        bool cols[ 9 ][ 9 ] = {};
        bool squares[ 9 ][ 9 ] = {};

        /* iterate through the board */
        for( int r = 0; r < 9; r++ )
            {
            for( int c = 0; c < 9; c++ )
                {
                /* if spot is empty, continue */
                if( board[ r ][ c ] == '.' )
                    {
                    continue;
                    }

                /* otherwise, consider the value and square */
                int val = board[ r ][ c ] - '1';
                int sqr = ( ( r / 3 ) * 3 ) + ( c / 3 );

                /* check if that value has been considered for the respective row, col, and sqr */
                if( rows[ r ][ val ]
                 || cols[ c ][ val ]
                 || squares[ sqr ][ val ] )
                    {
                    return false;
                    }

                /* if value has not been considerd, mark as seen and continue */
                rows[ r ][ val ] = true;
                cols[ c ][ val ] = true;
                squares[ sqr ][ val ] = true;
                }
            }
        
        return true;
    }
};
