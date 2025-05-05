



void merge(vector<int>&nums1,int m,vector<int>&nums2,int n){
    int N = m - 1;     
    int M = n - 1;    
    int k = m + n - 1; 
    while (N >= 0 && M >= 0) {
        if (nums1[N] > nums2[M]) {
            nums1[k] = nums1[N];
            N--;
        } else {
            nums1[k] = nums2[M];
            M--;
        }
        k--;
    }

    // If there are remaining elements in nums2, place them in nums1
    while (M >= 0) {
        nums1[k] = nums2[M];
        M--;
        k--;
    }
}