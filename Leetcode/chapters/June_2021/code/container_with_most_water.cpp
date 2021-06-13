#include <iostream>
#include <vector>

using namespace std;

/* the brutal force takes O(n^2) which is too slow that I cannot
    even pass the leetcode
*/
int brutal_force(vector<int> &height)
{
    int max = 0, turn;

    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            turn = min(height[i], height[j]) * (j - i);
            if (turn > max)
            {
                max = turn;
            }
        }
    }

    return max;
}

// linear O(n)
int two_pointer(vector<int> &height)
{
    /*
        The intuition is that the area is determine by the 
        shorter line and the distance between i,j.

        We start at two sides, and move closer and closer.
        At each time, if i is the shorter line, we test 
        (i+1,j); otherwise (i,j-1).
    */
    int i = 0, j = height.size() - 1, max = 0, turn;
    while (i < j)
    {
        turn = min(height[i], height[j]) * (j - i);
        if (turn > max)
        {
            max = turn;
        }
        if(height[i]<height[j]){
            i=i+1;
        }
        else{
            j=j-1;
        }
    }

    return max;

    /*
        More formally, at each pair(i,j), there is only 
        two possibilities:

        1. i,j are the biggest possible pair

        2. biggest container is among [i+1,j] or [i,j-1]

            we judicously choose to keep the longer one.
        

        This is kinda loop invariant.

        Then the biggest container for array [0,n]
        is either (0,n) itself, or the biggest among 
        [i+1,j] or [i,j-1].

        Suppose, we pick the smaller one, we cannot are both
        decreasing the width and height, it is unlikely to 
        find a biggest than current pair.
    */

}