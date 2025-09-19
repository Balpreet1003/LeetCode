class Spreadsheet {
    vector<vector<int>>sheet;
    pair<int,int> getIndex(string cell){
        int col=cell[0]-'A';
        int row=0;
        for(int i=1;i<cell.size();i++){
            row=(10*row)+(cell[i]-'0');
        }
        return {row, col};
    }
public:
    Spreadsheet(int rows) {
        sheet.resize(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [row, col]=getIndex(cell);
        sheet[row][col]=value;
    }
    
    void resetCell(string cell) {
        auto [row, col]=getIndex(cell);
        sheet[row][col]=0;
    }
    
    int getValue(string formula) {
        string s1="", s2="";
        for(int i=1;i<formula.length();i++){
            if(isalnum(formula[i])){
                s1+=formula[i];
            }
            else{
                s2=s1;
                s1="";
            }
        }
        int val1=isalpha(s1[0]) ? sheet[getIndex(s1).first][getIndex(s1).second] : stoi(s1);
        int val2=isalpha(s2[0]) ? sheet[getIndex(s2).first][getIndex(s2).second] : stoi(s2);
        return val1+val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */