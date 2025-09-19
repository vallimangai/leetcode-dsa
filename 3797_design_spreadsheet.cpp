class Spreadsheet {
public:
    map<string,int>mp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp.erase(cell);
    }
    
    int getValue(string formula) {
        auto fin=formula.find("+");
        string a=formula.substr(1,fin-1);
        string b=formula.substr(fin+1,formula.size());
        int ai,bi;
        if(isdigit(a[0])){
            ai=stoi(a);
        }else{
            ai=mp[a];
        }
        if(isdigit(b[0])){
            bi=stoi(b);
        }else{
            bi=mp[b];
        }
        return ai+bi;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */