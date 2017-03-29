#include <stdio.h>
#include <string.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int last[255] = {0};
    int left = 0;
    int result = 0;
    int i = 0;

    memset(last, -1, sizeof(last));

    for(i=0; i<len; i++)
    {
        if(last[s[i]] >= left) left = last[s[i]] + 1;
        last[s[i]] = i;
        result = MAX(result, i - left + 1);
    }

    return result;
}

int main(int argc, char **argv)
{
    char *string = "abcabcbb";
    int len = lengthOfLongestSubstring(string);
    printf("%d\n", len);
    return 0;
}
