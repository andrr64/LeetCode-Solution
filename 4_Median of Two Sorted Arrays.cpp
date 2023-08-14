#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedVect = mergedVectore(nums1, nums2);
        
        int totalSize = mergedVect.size();
        if (totalSize % 2 == 1) {
            return static_cast<double>(mergedVect[totalSize / 2]);
        } else {
            int mid1 = mergedVect[(totalSize - 1) / 2];
            int mid2 = mergedVect[totalSize / 2];
            return static_cast<double>(mid1 + mid2) / 2.0;
        }
    }

    vector<int> mergedVectore(vector<int>& nums1, vector<int>& nums2){
        vector<int> merged;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
    
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        return merged;
    }
};
