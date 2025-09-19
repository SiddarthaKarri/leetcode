class Spreadsheet {
    unordered_map<string, int> az;
    int rows;
    int haha(string si) {
        if (isdigit(si[0]))
            return stoi(si);
        return az.count(si) ? az[si] : 0;
    }

public:
    Spreadsheet(int rows) { 
        this->rows = rows; 
    }

    void setCell(string cell, int value) {
        az[cell] = value; 
    }

    void resetCell(string cell) {
        az[cell] = 0; 
    }

    int getValue(string formula) {
        if (formula[0] != '=')
            return stoi(formula);
        stringstream sid(formula.substr(1));
        string m1, m2;
        getline(sid, m1, '+');
        getline(sid, m2);
        return haha(m1) + haha(m2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */