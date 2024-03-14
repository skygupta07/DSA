/*


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map <int,int> mp;
        int result = 0;
        for (int i=0; i<answers.size(); i++){
            if (!mp[answers[i]+1]){
                result += answers[i]+1;
                if (answers[i]==0) continue;    // corner case-> rabbit saying mere alawa koi aur nahi..
                mp[answers[i]+1] = 1;   //initially 1 se value map kari..1 base count start kara..
            }
            else{
                mp[answers[i]+1]++;         // koi nayi value mili hogi..
                int key = answers[i]+1;
                int val = mp[key];
                if (key == val){    // we found all the rabbits of that group now eliminate or stop counting
                                        // that group...
                    mp.erase(key);  // jab key value same ho jae tab map mai se hata dena 
                
                }
            }
        }
        return result;
        
    }
};


*/

/*

unordered map will track that whether any or how many rabbit has claimed a color and and a number yet...
*/