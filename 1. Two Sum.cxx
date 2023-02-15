// Author : Eric
// Lang.  : C++
// Date   : 2023/02/11
// Note   : Eric First submitssion 
// Time   : O(n^2)
// Space  : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }    
};

// Author : Eric
// Lang.  : C++
// Date   : 2023/02/14
// Note   : unordered_map
// Time   : O(n)
// Space  : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return {i, map[target - nums[i]]};
            }
            else {
                map[nums[i]] = i;
            }
        }
        return {};
    }
};

// Author : Eric
// Lang.  : C++
// Date   : 2023/02/14
// Note   : two pointer + sort
// Time   : O(nlogn)
// Space  : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp, ans; 
        temp = nums;
	    
        sort(temp.begin(), temp.end());  // O(nlogn)

        int i = 0;
        int j = temp.size() - 1;

        while (i < j) {   // O(n)
            if (temp[i] + temp[j] > target)
                j--;
            else if (temp[i] + temp[j] < target)
                i++;
            else
                break;
        }

        int have_i = 1, have_j = 1;

        for (int k = 0; k < nums.size(); k++) { // O(n)
            if ((have_i) && (nums[k] == temp[i])) {
                ans.push_back(k);
                have_i = 0;
            }
            else if ((have_j) && (nums[k] == temp[j])) {
                ans.push_back(k);
                have_j = 0;
            }
            if (!have_i && !have_j)
                break;
        }

        return ans;
    }
};
