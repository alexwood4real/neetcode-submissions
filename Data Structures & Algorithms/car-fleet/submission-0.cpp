class Solution {
private:
    struct Car_Info_T
        {
        int pos;
        int spd;
        int idx;
        float time;
        };

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /* local variables */
        vector<Car_Info_T> car_info;
        Car_Info_T car;
        stack<float> stk;
        int idx;

        /* store car info */
        for( idx = 0; idx < position.size() && idx < speed.size(); idx++ )
            {
            /* store info */
            car.pos = position[ idx ];
            car.spd = speed[ idx ];
            car.idx = idx;
            car.time = (float)( target - position[ idx ] ) / speed[ idx ];

            /* add car to list */
            car_info.push_back( car );
            } /* end of for-loop */

        /* sort based on descending position */
        sort( car_info.begin(), car_info.end(), []( const Car_Info_T &c1, const Car_Info_T &c2 ) {
            return c1.pos > c2.pos;
        } );

        /* count the number of fleets */
        for( idx = 0; idx < car_info.size(); idx++ )
            {
            /* a fleet will form iff the car ahead has a time >= the car behind it */
            if( stk.empty() 
             || car_info[ idx ].time > stk.top() )
                {
                /* if curr car time <= top of stack, joins the same fleet; otherwise, new fleet forms */
                stk.push( car_info[ idx ].time );
                }
            } /* end of for-loop */

        /* return result */
        return stk.size();
    }
};
