// LCM of multiple values

long long lcm_multiple(const std::vector<int>& numbers) {
    if (numbers.empty()) return 1; // LCM of an empty set is 1
    
    return std::accumulate(numbers.begin() + 1, numbers.end(), (long long)numbers[0], std::lcm<long long, long long>);
}
