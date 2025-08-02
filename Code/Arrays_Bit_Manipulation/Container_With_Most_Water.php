<?php

class Solution {
    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $left = 0;
        $right = count($height) - 1;
        $maxWater = 0;

        while ($left < $right) {
            $h = min($height[$left], $height[$right]);
            $w = $right - $left;
            $area = $h * $w;
            if ($area > $maxWater) {
                $maxWater = $area;
            }

            if ($height[$left] < $height[$right]) {
                $left++;
            } else {
                $right--;
            }
        }

        return $maxWater;
    }
}

// Test case
$sol = new Solution();
$height = [1, 8, 6, 2, 5, 4, 8, 3, 7];
echo "Maximum water that can be contained: " . $sol->maxArea($height) . PHP_EOL;
