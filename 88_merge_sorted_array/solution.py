class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        index = m + n - 1
        m-=1
        n-=1
        while(index >=0):
            if(m==0):
                nums1[index] = nums2[n]
                n -= 1
            elif(n==0):
                break
            elif(nums1[m] > nums2[n]):
                nums1[index] = nums1[m];
                m-=1
            else:
                nums1[index] = nums2[n]
                n-=1
            index -= 1

