class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        long long min = enemyEnergies[0];
        if(currentEnergy < min) return 0;
        long long total = 0;
        for(int i = 1 ; i < enemyEnergies.size() ; i++) total+=enemyEnergies[i];
        total+=currentEnergy;
        long long points = total/min;
        return points;
    }
};