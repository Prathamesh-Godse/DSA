#include <stdio.h>
#include <string.h>

void readStrings(char *mainStr, char *patternStr, char *replaceStr) {
    printf("Enter the main string: ");
    fgets(mainStr, 100, stdin);
    mainStr[strcspn(mainStr, "\n")] = '\0'; // Remove newline character
    printf("Enter the pattern string: ");
    fgets(patternStr, 100, stdin);
    patternStr[strcspn(patternStr, "\n")] = '\0'; // Remove newline character
    printf("Enter the replace string: ");
    fgets(replaceStr, 100, stdin);
    replaceStr[strcspn(replaceStr, "\n")] = '\0'; // Remove newline character
}

int findPattern(char *mainStr, char *patternStr, int *positions) {
    int mainLen = strlen(mainStr);
    int patternLen = strlen(patternStr);
    int count = 0;
    for (int i = 0; i <= mainLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (mainStr[i + j] != patternStr[j])
                break;
        }
        if (j == patternLen) {
            positions[count++] = i;
        }
    }
    return count;
}

void replacePattern(char *mainStr, char *replaceStr, int *positions, int count, int patternLen, char *resultStr) {
    int mainLen = strlen(mainStr);
    int replaceLen = strlen(replaceStr);
    int replaceIndex = 0, mainIndex = 0, resultIndex = 0;
    while (mainIndex < mainLen) {
        if (mainIndex == positions[replaceIndex]) {
            for (int i = 0; i < replaceLen; i++) {
                resultStr[resultIndex++] = replaceStr[i];
            }
            mainIndex += patternLen; // Increment by pattern length
            replaceIndex++;
        } else {
            resultStr[resultIndex++] = mainStr[mainIndex++];
        }
    }
    resultStr[resultIndex] = '\0';
}

int main() {
    char mainStr[100], patternStr[100], replaceStr[100], resultStr[100];
    int positions[100], count;

    readStrings(mainStr, patternStr, replaceStr);
    count = findPattern(mainStr, patternStr, positions);

    if (count > 0) {
        int patternLen = strlen(patternStr); // Get pattern length
        replacePattern(mainStr, replaceStr, positions, count, patternLen, resultStr);
        printf("Pattern replaced successfully.\nNew string: %s\n", resultStr);
    } else {
        printf("Pattern not found in the main string.\n");
    }

    return 0;
}
