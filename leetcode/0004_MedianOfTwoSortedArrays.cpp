class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sum;
        int i=0, j=0;
        int l1=nums1.size(),l2=nums2.size();
        while( i<l1 and j<l2 ){
            if( nums1[i] < nums2[j] ){
                sum.push_back( nums1[i] );
                ++i;
            }else{
                sum.push_back( nums2[j] );
                ++j;
            }
        }
        while( i<l1 ){
            sum.push_back( nums1[i] );
            ++i;
        }
        while( j<l2 ){
            sum.push_back( nums2[j] );
            ++j;
        }
        double ans = (sum[ sum.size()/2 ]+sum[ (sum.size()-1)/2 ])/2.0;
        return ans;
    }
};
