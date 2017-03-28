#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target)
{
    int *ret = (int *)calloc(2, sizeof(int));

    int i, j;
    for(i=0; i<numsSize; ++i)
    {
        for(j=i+1; j<numsSize; ++j)
        {
            int diff = target - nums[j];
            if(diff == nums[i])
            {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }

    return ret;
}

int main(int argc, char **argv)
{
    int array[] = {3, 2, 3};
    int target = 6;

    int *result = twoSum(array, sizeof(array)/sizeof(array[0]), target);
    if(result != NULL)
        printf("index1=%d, index2=%d\n", result[0], result[1]);

    free(result);
    return 0;
}
