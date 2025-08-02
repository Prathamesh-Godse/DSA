#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxWater = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int w = right - left;
        int area = h * w;
        if (area > maxWater)
            maxWater = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, size);
    printf("Maximum water that can be contained: %d\n", result);

    return 0;
}
