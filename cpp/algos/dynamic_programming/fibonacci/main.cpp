#include <iostream>
#include <unordered_map>


uint64_t fib(uint64_t n, std::unordered_map<uint64_t , uint64_t> &memo){
    if (memo.find(n) != memo.end()){
        return memo[n];
    }

    if (n <= 2){
        return  1;
    }

    uint64_t result_to_cache = fib(n-1, memo) + fib(n-2, memo);
    memo[n] = result_to_cache;

    return result_to_cache;
}


int main() {
    std::unordered_map<uint64_t, uint64_t > memo;

    std::cout << fib(50, memo) << std::endl;
    return 0;
}

