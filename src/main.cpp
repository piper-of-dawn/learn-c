
#include <vector>
#include "unordered_map"
#include "../include/utils.h" // Include your custom header file
using namespace std;

vector<int> two_sum(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            return vector<int>({left + 1, right + 1});
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return vector<int>({-1, -1});
};


bool valid_anagram (string l, string r) {
    unordered_map<char, int> freq;
    if (l.length() != r.length()) {
        return false;
    }
    for (char c: l) {
        freq[c]++;
    }
    for (char c: r) {
        freq[c]--;
    }

    for (const auto& [_, value] : freq) {
        if (value != 0) {
            return false;
        }
    }
    return true;
}




int main()
{
    vector<int> test = {1, 2, 3, 4, 5};
    int target = 3;
    print_vector(two_sum(test, target));
    string t = "carrace";
    string s = "racecar";
    cout << valid_anagram(t, s) << endl;
    t = "carrape";
    s = "racecar";
    cout << valid_anagram(t, s) << endl;
}
// g++ -I../include src/main.cpp src/utils.cpp -o program | ./program
