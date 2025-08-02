<?php

function maxProfit($prices) {
    $minPrice = PHP_INT_MAX;
    $maxProfit = 0;

    foreach ($prices as $price) {
        if ($price < $minPrice) {
            $minPrice = $price;
        } elseif ($price - $minPrice > $maxProfit) {
            $maxProfit = $price - $minPrice;
        }
    }

    return $maxProfit;
}

// Console input
echo "Enter stock prices separated by space: ";
$input = trim(fgets(STDIN));
$prices = array_map('intval', explode(' ', $input));

$result = maxProfit($prices);
echo "Maximum profit: " . $result . PHP_EOL;
