class Solution {
private: 
    unordered_map<string, vector<string>> umap;
    vector<vector<string>> result;

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /* iterate through the list of words */
        for( auto& word : strs )
            {
            /* sort the word to create a key, and store it */
            string key = word;
            sort( key.begin(), key.end() );
            umap[ key ].push_back( word );
            }

        /* store the words in each key */
        for( auto& [ key, words ] : umap )
            {
            result.push_back( words );
            }

        return result;
    }
};
