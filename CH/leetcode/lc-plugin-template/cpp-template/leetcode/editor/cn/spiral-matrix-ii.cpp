/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30300
 *
 * [59] 螺旋矩阵 II
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int startX = 0, startY = 0;
        int offset = 1;
        int count = 1;
        int loop = n / 2;
        int mid = n / 2;
        int i, j;
        while (loop--)
        {
            i = startX;
            j = startY;
            // to right
            for (j = startY; j < startY + n - offset; j++)
            {
                arr[startX][j] = count++;
            }
            // to down
            for (i = startX; i < startX + n - offset; i++)
            {
                arr[i][j] = count++;
            }
            // to left
            for (; j > startY; j--)
            {
                arr[i][j] = count++;
            }
            // to left
            for (; i > startX; i--)
            {
                arr[i][j] = count++;
            }
            startX++;
            startY++;
            offset += 2;
        }
        if (n % 2)
        {
            arr[mid][mid] = count++;
        }
        return arr;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    solution.generateMatrix(3);
}

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
