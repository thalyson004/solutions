class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        int mx = 105;
        vector<set<string>> remain = vector<set<string>>(mx);
        map<string, vector<int>> G;

        vector<string> ans;

        for(int i = 0; i < recipes.size(); i++){

            for(string ingredient: ingredients[i]){
                if(!G.count(ingredient)) G[ingredient] = vector<int>();

                G[ingredient].push_back(i);
                remain[i].insert(ingredient);
            }
        }

        queue<string> ready;
        for(string supply : supplies){
            ready.push(supply);
        }

        while(ready.size()){
            string current = ready.front(); ready.pop();

            for(int id: G[current]){
                remain[id].erase(current);
                if(remain[id].size() == 0) {
                    ready.push(recipes[id]);
                    ans.push_back(recipes[id]);
                }
            }
        }

        return ans;
    }
};
