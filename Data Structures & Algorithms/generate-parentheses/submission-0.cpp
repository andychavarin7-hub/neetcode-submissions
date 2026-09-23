class Solution {
public:

    std::vector<std::string> result;
    int tpair = 0;

    void genParan(int left, int right, std::string &val){
        if( left>tpair || right > tpair){
            return;
         }
        
        if(left == right && left == tpair){
            result.push_back(val);
            return;
        }


        
        val.push_back('(');
        //std::cout << "S: init string " << val << "= (" << left +1 << "," << right<< ")" << std::endl;
        genParan(left + 1, right, val);
        val.pop_back();

        if( left > right){
            val.push_back(')');
            //std::cout << "F: init string " << val << "= (" << left << "," << right + 1<< ")" << std::endl;
            genParan(left, right + 1, val);
            val.pop_back();
        }

        
    }

    vector<string> generateParenthesis(int n) {
        
        tpair = n;
        std::string val;

        genParan(0,0,val);
        return result;
        
    }
};
