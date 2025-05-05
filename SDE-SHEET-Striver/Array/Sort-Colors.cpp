void sortColors(vector<int>&nums){
    int k=0;
    int zero=0;
    int one=0;
    int two=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            zero++;
        }
        if(nums[i]==1){
            one++;
        }
        if(nums[i]==2){
            zero++;
        }
    }
    for(int i=0;i<nums.size();i++)
        {
            if(zero!=0){
                nums[k++]=0;

                zero--;
            }
            else if(one!=0){
                nums[k++]=1;
                one--;
            }
            else if(two!=0){
                nums[k++]=2;
                two--;

            }
        }
}