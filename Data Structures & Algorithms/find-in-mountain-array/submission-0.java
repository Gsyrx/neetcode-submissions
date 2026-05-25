/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */

class Solution {

    public int findInMountainArray(int target, MountainArray mountainArr) {

        int n = mountainArr.length();

        int peak = findPeak(mountainArr, n);

        int left = binarySearchAsc(mountainArr, 0, peak, target);

        if (left != -1) {
            return left;
        }

        return binarySearchDesc(mountainArr, peak + 1, n - 1, target);
    }

    private int findPeak(MountainArray arr, int n) {

        int left = 0;
        int right = n - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (arr.get(mid) < arr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    private int binarySearchAsc(MountainArray arr, int l, int r, int target) {

        while (l <= r) {

            int mid = l + (r - l) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;
            else if (val < target) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }

    private int binarySearchDesc(MountainArray arr, int l, int r, int target) {

        while (l <= r) {

            int mid = l + (r - l) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;
            else if (val > target) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
}