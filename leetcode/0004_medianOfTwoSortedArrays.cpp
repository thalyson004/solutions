class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int n = nums1.size(), m = nums2.size();
        int k = (n+m-1)/2;
        
        if(n+m == 0){
            return 0.0;
        }
        
        while(i+j < k){
            int id1 = i+((k-1-i-j)/2);
            int id2 = j+((k-1-i-j)/2);
            
            if(id1 >= n) j = id2+1;
            else if(id2 >= m) i = id1+1;
            else{
                if(nums1[id1]<nums2[id2]) i = id1+1;
                else j = id2+1;
            }
        }
        
        double ans = 0.0;
        
        if( (i==n?INT_MAX:nums1[i]) < (j==m?INT_MAX:nums2[j]) ){
            ans += nums1[i++];   
        }else{
            ans += nums2[j++];
        }
        
        if( (n+m)%2 == 0 ){
            if( (i==n?INT_MAX:nums1[i]) < (j==m?INT_MAX:nums2[j]) ){
                ans = (ans+nums1[i++])/2;   
            }else{
                ans = (ans+nums2[j++])/2;   
            }
        }
        
        return ans;
    }
};
