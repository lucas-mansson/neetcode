class Solution {
public:
    int climbStairs(int n) {
        return dfs(n, 0);
    }

    int dfs(int n, int stepsTaken){
        if(stepsTaken > n){
            return 0;
        }

        if(stepsTaken == n){
            return 1;
        }

        return dfs(n, stepsTaken + 1) + dfs(n, stepsTaken + 2);
    }
};
