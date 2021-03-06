
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <cmath>


class Solution
{
    public:
        int numSquares(int n) {
            int               i,  sqrt;
            std::vector<int>  squares, dp(n+1, n+1);

            if (n < 0) {
                return 0;
            }

            sqrt = std::sqrt(n);
            squares.resize(sqrt);
            for (i = 1; i <= sqrt; i++) {
                squares[i-1] = std::pow(i, 2);
            }

            /*
             * the same as leetcode-322 coin change
             */

            dp[0] = 0;
            for (i = 1; i <= n; i++) {
                for (auto s : squares) {
                    if (s <= i) {
                        dp[i] = std::min(dp[i], dp[i-s]+1);
                    }
                }
            }

            return dp[n];
        }
};


/*
 * Iterative Deepening Depth First Search
 */

class Solution2
{
    public:
        int numSquares(int n) {
            int  nnumbers;

            for (nnumbers = 1; /* void */; nnumbers++) {
                if (dfs(n, nnumbers)) {
                    return nnumbers;
                }
            }

            return 0;
        }

    private:
        bool dfs(int rest, int nnumbers) {
            int  i, square;

            if (nnumbers == 0) {
                return !rest;
            }

            for (i = std::sqrt(rest); i >= 1; i--) {
                square = i * i;
                if (square * nnumbers < rest) {
                    break;
                }

                if (dfs(rest - square, nnumbers - 1)) {
                    return true;
                }
            }

            return false;
        }
};


int
main(int argc, char **argv)
{
    Solution2  ans;
    int        number;

    number = 100000;
    printf("ans(%d): %d\n", number, ans.numSquares(number));

    return 0;
}
