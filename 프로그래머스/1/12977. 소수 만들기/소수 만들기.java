class Solution {
    private int answer = 0;
    private int[] nums;

    public int solution(int[] nums) {
        this.nums = nums;
        
        // n개 중 3개를 뽑는 DFS 시작
        // dfs(시작 인덱스, 현재까지 뽑은 개수, 현재까지의 합)
        dfs(0, 0, 0);
        
        return answer;
    }

    private void dfs(int start, int count, int sum) {
        // 1. 기저 조건: 3개를 모두 뽑았을 때
        if (count == 3) {
            if (isPrime(sum)) {
                answer++;
            }
            return;
        }

        // 2. 재귀 호출: 현재 인덱스 이후의 숫자들을 하나씩 선택
        for (int i = start; i < nums.length; i++) {
            dfs(i + 1, count + 1, sum + nums[i]);
        }
    }

    private boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}