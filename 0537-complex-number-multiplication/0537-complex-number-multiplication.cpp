class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        
        string real1 = "";
        string real2 = "";

        string img1 = "";
        string img2 = "";

        int i = 0;

        while(num1[i] != '+') real1 += num1[i++];
        i++;
        while(num1[i] != 'i') img1 += num1[i++];
        
        i = 0;

        while(num2[i] != '+') real2 += num2[i++];
        i++;
        while(num2[i] != 'i') img2 += num2[i++];

        int r1 = 0,r2 = 0,i1 = 0,i2 = 0;

        if(real1[0] == '-') {
            real1 = real1.substr(1);
            r1 = -1*stoi(real1);
        }
        else r1 = stoi(real1);
        
        if(real2[0] == '-') {
            real2 = real2.substr(1);
            r2 = -1*stoi(real2);
        }
        else r2 = stoi(real2);

        if(img1[0] == '-') {
            img1 = img1.substr(1);
            i1 = -1*stoi(img1);
        }
        else i1 = stoi(img1);

        if(img2[0] == '-') {
            img2 = img2.substr(1);
            i2 = -1*stoi(img2);
        }
        else i2 = stoi(img2);

        int p1 = (r1*r2)-(i1*i2);
        int p2 = (r1*i2)+(r2*i1);

        return to_string(p1)+"+"+to_string(p2)+"i";

        
    }
};