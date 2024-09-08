class Solution {
public:
string bin(string s) {
    int num = stol(s);
    string b = "";
    while(num) {
        b+=(num%2)+'0';
        num/=2;
    }
    reverse(b.begin(),b.end());
    return b;
}
    string convertDateToBinary(string date) {
        string year;
        year+=date[0];
        year+=date[1];
        year+=date[2];
        year+=date[3];
        string month;
        month+=date[5];
        month+=date[6];
        string day;
        day+=date[8];
        day+=date[9];
        string res = bin(year)+"-"+bin(month)+"-"+bin(day);
        return res;
    }
};