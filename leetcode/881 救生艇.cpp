class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left=0;
        //最后的数组的引用要减一
        int right = people.size()-1;
        int number=0;
        //使用sort函数进行数组的排序，从小到大排
        sort(people.begin(),people.end());
        while(left<=right)
        {
            if(people[left]+people[right]>limit)
            {
                right--;
            }
            else
            {
                left++;
                right--;
            }

            number++;
        }
        return number;
    }
};
