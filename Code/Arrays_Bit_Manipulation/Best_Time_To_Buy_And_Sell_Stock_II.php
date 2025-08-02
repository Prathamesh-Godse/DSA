<?php

function maxProfit($prices) {
    $profit = 0;
    for ($i = 1; $i < count($prices); $i++) {
        if ($prices[$i] > $prices[$i - 1]) {
            $profit += $prices[$i] - $prices[$i - 1];
        }
    }
    return $profit;
}

// Example usage
$prices = [7, 1, 5, 3, 6, 4];
echo "Max Profit: " . maxProfit($prices) . "\n";

?>
