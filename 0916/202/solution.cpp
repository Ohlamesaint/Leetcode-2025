class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = calculate(n);
        while(slow!=fast && fast!=1) {
            slow = calculate(slow);
            fast = calculate(calculate(fast));
        }
        return fast==1;

    }

private:

    int calculate(int n) {
        int sum = 0;
        while(n!=0) {
            int mod = n%10;
            sum += mod*mod;
            n/=10;
        }
        return sum;
    }
};