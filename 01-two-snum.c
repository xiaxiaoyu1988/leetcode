int *last;
int *last_index;

void add_last(int l, int index, int numsSize)
{
    // printf("add_last, index=%d, num=%d\n", index, l);
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(last[i] == -1)
        {
            last[i] = l;
            last_index[i] = index;
            break;
        }
    }
}

int find_last(int l, int numsSize)
{
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(last[i] == l)
        {
            return last_index[i];
        }
    }
    return -1;
}

void clear_last(int numsSize)
{
   int i = 0;
    for(i = 0; i < numsSize; i++)
    {
       last[i] = -1;
       last_index[i] = -1;
    }  
    
}

void print_last(int numsSize)
{
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
       printf("last[%d]=%d, last_index[%d]=%d |", i, last[i], i, last_index[i]);
    }
    printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    last = calloc(numsSize, sizeof(int));
    last_index = calloc(numsSize, sizeof(int));
    memset(last, -1, sizeof(int)*numsSize);
    memset(last_index, -1, sizeof(int)*numsSize);
    
    // clear_last();
    int *res;
    res = (int*)calloc(2, sizeof(int));
    int i = 0;
    int j = 0;
    int last = -1;
    int last_index = -1;
    for(i=0; i < numsSize; i++)
    {
        //   print_last(numsSize);
           last_index = find_last(nums[i], numsSize);
        //   printf("i=%d, num=%d, last_index=%d\n", i, nums[i], last_index);
           if( last_index != -1)
           {
              
            //   memcpy(res, last_index, 1);
            //   memcpy(res+1, i, 1);
                res[0] = last_index;
                res[1] = i;
                break;
           }
           else
           {
               add_last(target - nums[i], i, numsSize);
           }
    }
    return res;
}