class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string encodedVal;

        /* payload header consiting of 2 quads, 8 bytes */
        /* consist of start word and lenght | startword | size | */
        /* if dealing w/actual system we we choose some endianess to abide by here */
        for (auto& item : strs) {
            uint8_t sz = 5;
            std:cout << "str size is " << item.size() << std::endl;
            sz +=item.size();
            for (int i = 0; i < 4; ++i){ 
                encodedVal.push_back(0xa6);
            }
                
            encodedVal.push_back(sz);
            /*push the size back here*/

            for (auto c : item) encodedVal.push_back(c);
        }

        return encodedVal;
    }

    vector<string> decode(string s) {
        std::cout << "serialized val: " << s << std::endl;
        std::vector<std::string> decodedStr;
        std::string syncWord;
        std::string syncVal;

        for (int i = 0; i < 4; ++i) syncVal.push_back(0xa6);

        int headerSz = 0;
        uint8_t sz = 0;
        std::string item;
        for (auto c : s) {
            /*search for header and size */
            /*12 bytes to header*/
            if (headerSz < 4) {
                syncWord.push_back(c);
                headerSz++;
            } else if (headerSz < 5) {
                sz = c;
                headerSz++;
            } else if (syncWord != syncVal) {
                /*break, something wrong happened*/
                break;
            } else {
                item.push_back(c);
                headerSz++;
            }
        
            if (((headerSz > 5) & (headerSz >=sz))|| sz==5) {
                    sz = 0;
                    decodedStr.push_back(item);
                    syncWord.clear();
                    item.clear();
                    headerSz = 0;
            } 
        }

        return decodedStr;
    }
};
