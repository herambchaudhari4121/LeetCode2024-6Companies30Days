#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hash map to store frequency signature as key
        unordered_map<string, vector<string>> anagramGroups;

        for (const auto& str : strs) {
            // Build frequency count (26 letters)
            vector<int> freq(26, 0);
            for (char c : str) {
                freq[c - 'a']++;
            }

            // Convert frequency vector into a unique string key
            string key;
            for (int count : freq) {
                key += "#" + to_string(count);
            }

            // Add string to its group
            anagramGroups[key].push_back(str);
        }

        // Collect results
        vector<vector<string>> result;
        for (auto& [key, group] : anagramGroups) {
            result.push_back(move(group));
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case (no user input)
    vector<string> words = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = sol.groupAnagrams(words);

    // Print results
    for (auto& group : result) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    return 0;
}
