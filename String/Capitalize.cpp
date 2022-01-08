class Solution {
public:
    string capitalizeTitle(string t) {
         transform(begin(t),end(t),begin(t),::tolower);
        istringstream ss(t);
        string w,res;
        while(ss>>w){
            if(w.size()>2) w[0]=toupper(w[0]);
            res+=w+" ";
        }
        res.pop_back();
        return res;
    }
};