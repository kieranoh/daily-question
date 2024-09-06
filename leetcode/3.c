#include <string.h>
int lengthOfLongestSubstring(char* s) {
    int start = 0, result = 0;
    int ascii[256] = {0};

    for (int end = 0; s[end] != '\0'; end++) {
        
        if (ascii[(unsigned char)s[end]] > 0) {
            start = ascii[(unsigned char)s[end]] > start ? ascii[(unsigned char)s[end]] : start;
        }

        int currentLength = end - start + 1;
        if (currentLength > result) {
            result = currentLength;
        }

        ascii[(unsigned char)s[end]] = end + 1;
    }

    return result;
}
