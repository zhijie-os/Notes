import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class three_sum {

    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);

        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length&&nums[i]<=0; i++) {
            if(i==0||nums[i-1]!=nums[i]){
                two_sum(nums,i,-nums[i],res);
            }
        }
    }

    public static void two_sum(int[] nums, int i, int target, List<List<Integer>> res) {
        
        int or = i, j=nums.length-1, sum;
        while(i<j){
            sum = nums[i]+nums[j];

            if(sum==target){
                res.add(Arrays.asList(nums[or],nums[i++],nums[j--]));
                while(i<j&&nums[i]==nums[i-1]){
                    i++;
                }
            }

            if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
    }

}