
use std::io::{self, Read};

fn merge_sort(nums: &mut [i64], ans: &mut i64) {
    let n = nums.len();

    if n <= 1 {
        return;
    }

    let mid = n / 2;

    // 递归处理左右两半
    merge_sort(&mut nums[..mid], ans);
    merge_sort(&mut nums[mid..], ans);

    let mut helper: Vec<i64> = Vec::with_capacity(n);

    let mut left = 0;
    let mut right = mid;

    while left < mid && right < n {
        if nums[left] < nums[right] {
            // 左边这个数小于右半区剩余的所有数
            *ans += (n - right) as i64;

            helper.push(nums[left]);
            left += 1;
        } else {
            helper.push(nums[right]);
            right += 1;
        }
    }

    // 处理剩余元素
    helper.extend_from_slice(&nums[left..mid]);
    helper.extend_from_slice(&nums[right..n]);

    // 把归并结果复制回原数组
    nums.copy_from_slice(&helper);
}

fn main() {
    // 读取标准输入
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut iter = input.split_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();

    let mut nums: Vec<i64> = Vec::with_capacity(n);

    for i in 0..n {
        let x: i64 = iter.next().unwrap().parse().unwrap();

        let idx = (i + 1) as i64;
        nums.push(x - idx * idx);
    }

    let mut ans: i64 = 0;

    merge_sort(&mut nums, &mut ans);

    println!("{}", ans);
}
