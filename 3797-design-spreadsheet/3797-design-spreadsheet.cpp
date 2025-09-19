class Spreadsheet {
public:

    unordered_map<string,int>m;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        m[cell] = value;
    }
    
    void resetCell(string cell) {
        m[cell] = 0;
    }
    
    int getValue(string formula) {

        // string c1 = "";

        // for(int i = 1 ; i < formula.size() ; i++) {
        //     if(formula[i] == '+') {
        //         break;
        //     }
        //     else {
        //         c1 += formula[i];
        //     }
        // }

        vector<string>v;

        stringstream ss(formula);

        string temp;

        while(getline(ss,temp,'+')) {
            v.push_back(temp);
        }

       // cout << v[0] << " " << v[1] << endl;

        string c1 = v[0].substr(1);
        string c2 = v[1];
    
        
        char ch = v[1][0];



        if(ch >= 'A' && ch <= 'Z')  {

            char ch2 = c1[0];

            if(ch2 >= 'A' && ch2 <= 'Z') {
                return m[c1]+m[c2];
            }
            else {
                int num = stoi(c1);
                return num+m[c2];
            }
        }
        else {
            char ch2 = c1[0];
            if(ch2 >= 'A' && ch2 <= 'Z') {
                int num =  stoi(v[1]);
                return m[c1]+num;
            }
            else {
                int n1 = stoi(c1);
                int n2 = stoi(c2);
                return n1+n2;
            }
        }
        
       
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */