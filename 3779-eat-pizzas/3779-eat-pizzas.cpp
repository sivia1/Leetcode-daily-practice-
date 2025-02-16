class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size(), days = n/4, index = n-1;
    
        long long totalWeight = 0;

        for (int day = 1; day <= days; day += 2) {
            totalWeight += pizzas[index--];
        }
        index--;
        for(int day = 2; day <= days; day+=2) {
            totalWeight += pizzas[index];
            index -=2;
        }
        return totalWeight;
    }
};