package chapters.June_2021.code;

import java.util.HashMap;
import java.util.Map;

public class two_sum {
    // suppose nums is sorted
    public int[] two_pointer(int[] nums, int target) {
        int i = 0, j = nums.length - 1, sum;

        while (i < j) {
            sum = nums[i] + nums[j];
            if (sum == target) {
                return new int[] { i, j };
            }
            if (sum < target) {
                i++;
            } else {
                j++;
            }
        }

        return new int[] {};
    }

    public int[] hash_map(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement) && map.get(complement) != i) {
                return new int[] { i, map.get(complement) };
            }
        }

        return new int[] {};
    }
}
