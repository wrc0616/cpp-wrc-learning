//滑动窗口法
class Solution {
public:
    bool is_Vowel(char &v){
            return v == 'a'||
            v == 'e'||
            v == 'i'||
            v == 'o'||
            v == 'u';
        }
    int maxVowels(string s, int k) {
        //计算滑动窗口内元音的个数
        int count=0;
        //返回k窗口内的元音个数
        int res = 0;
        for(int i= 0;i<k;i++)
        {
            count = count + is_Vowel(s[i]);
        }
        res = count;
        for(int i = k ;i<s.size();i++)
        {
            count = count+is_Vowel(s[i])-is_Vowel(s[i-k+1]);
            res = max(count,res);
        }
        return res;
    }
};
