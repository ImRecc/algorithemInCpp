// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*无需二次确认：二分查找的 left <= right 和 right = mid（而非 mid-1）确保检查所有可能位置。
当 isBadVersion(mid) = true，保留 mid（right = mid），继续搜左边，找到更早的坏版本。
最终 left 收敛到第一个坏版本，无需额外调用 isBadVersion(mid-1)。
*/
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2; // 防溢出
            if (isBadVersion(mid)) {
                right = mid; // 保留 mid，搜左边
            } else {
                left = mid + 1; // 搜右边
            }
        }
        return left; // 第一个坏版本
    }
};
