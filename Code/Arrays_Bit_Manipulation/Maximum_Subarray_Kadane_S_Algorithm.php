<?php

function maxSubArray($nums) {
    $currentSum = $nums[0];
    $maxSum = $nums[0];

    for ($i = 1; $i < count($nums); $i++) {
        $currentSum = max($nums[$i], $currentSum + $nums[$i]);
        $maxSum = max($maxSum, $currentSum);
    }

    return $maxSum;
}

// Test the function
$nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
$result = maxSubArray($nums);
echo "Maximum Subarray Sum: " . $result . PHP_EOL;
?>
