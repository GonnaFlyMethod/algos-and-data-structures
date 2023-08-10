#include <iostream>
#include <vector>
#include <unordered_map>


bool can_reach_target(int target, std::vector<int> &nums, std::unordered_map<int,bool> &memo){
    if (memo.find(target) != memo.end()) {
        return memo[target];
    }

    if (target == 0){
        return true;
    }

    if (target < 0){
        return false;
    }

    for (int i = 0; i < nums.size() ;i++){
        int remain = target - nums[i];

        if (can_reach_target(remain, nums, memo)){
            return true;
        }
    }

    return false;
}

int main() {
    int target = 8;
    std::vector<int> sequence = {9,42, 90, 91, 93, 94, 8, 71, 72, 73, 74, 75};

    std::unordered_map<int, bool> memo;

    std::cout << can_reach_target(target, sequence, memo) << std::endl;
    return 0;
}

