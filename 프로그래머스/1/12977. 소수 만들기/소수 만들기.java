class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int n = nums.length;

        // 1. 서로 다른 3개의 숫자를 선택 (중복 없이)
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    
                    // 2. 합이 소수인지 판별
                    if (isPrime(sum)) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }

    // 소수 판별 메서드
    private boolean isPrime(int num) {
        if (num < 2) return false;
        // 제곱근까지만 확인하여 성능 최적화
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}