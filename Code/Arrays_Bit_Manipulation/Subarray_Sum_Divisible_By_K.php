<?php

class Solution {
    function subarraysDivByK($nums, $k) {
        $remainderCount = [];
        $remainderCount[0] = 1;

        $prefixSum = 0;
        $count = 0;

        foreach ($nums as $num) {
            $prefixSum += $num;
            $remainder = (($prefixSum % $k) + $k) % $k;

            if (isset($remainderCount[$remainder])) {
                $count += $remainderCount[$remainder];
            }
            $remainderCount[$remainder] = ($remainderCount[$remainder] ?? 0) + 1;
        }

        return $count;
    }
}

// Test
$sol = new Solution();
$nums = [4, 5, 0, -2, -3, 1];
$k = 5;
$result = $sol->subarraysDivByK($nums, $k);
echo "Number of subarrays divisible by $k is: $result\n";
