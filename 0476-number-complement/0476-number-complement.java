class Solution {
    public int findComplement(int num) {
        String s = Integer.toString(num,2);
        String res = "";
        for(int i = 0 ; i < s.length() ; i++) {
            if(s.charAt(i) == '0') res+='1';
            else res+='0';
        }
        return Integer.parseInt(res,2);
    }
}