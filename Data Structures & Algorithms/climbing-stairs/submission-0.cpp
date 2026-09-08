class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> combo;

        if( n< 2){
            return n;
        }

        combo.push_back(0);
        combo.push_back(1);
        combo.push_back(2);

        for(auto it =3 ; it <=n; ++it){
            combo.push_back(combo[it-1] + combo[it-2]);
        }
        return combo.back();
    }
};
