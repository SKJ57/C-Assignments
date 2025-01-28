/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(*returnSize*sizeof(int));

    for (int i=0; i<numsSize; i++){
        for (int j=i+1; j<numsSize; j++){
            if (nums[i]+ nums[j] == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    free(result);
    return 0;
}

int main(){
    int numsSize;
    printf("Enter the size of array = ");
    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize*sizeof(int));
    printf("Enter elements for your array = ");
    for(int i=0; i<numsSize; i++){
        scanf("%d", &nums[i]);
    }

    int target;
    printf("Enter your target value = ");
    scanf("%d", &target);

    int returnSize;
    int* indices = twoSum(nums, numsSize, target, &returnSize);

    if(indices!= 0){
        printf("Indices: [%d, %d]", indices[0], indices[1]);
        free(indices);
    } else{
        printf("No solution was found");
    }

    getchar();
    getchar();

    free(nums);
    return 0;

}
