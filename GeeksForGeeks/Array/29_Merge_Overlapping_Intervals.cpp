#include <bits/stdc++.h>
using namespace std;

/*
    Intervals : {{1,3},{2,4},{5,7},{6,8}}
    Output: {{1,4},{5,8}}

    Approach:
    1. Sort interval based on increasing order of starting time.
    2. Push the first element to stack.
    2. For each interval do the following
        a. If the current interval does not overlap with stack top, push it.
        b. If overlaps, then update TOS endtime = ending time of current interval,
    3. At the end, stack contains the merged intervals.
 */

