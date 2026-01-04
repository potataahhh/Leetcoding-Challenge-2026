class Solution {
public:

    int func(int num){
        int count=0,sum=0;

        for(int div=1;div*div<=num;div++){
            if(num%div==0){
                int div2=num/div;

                if(div2==div){
                    count+=1;
                    sum+=div;
                }
                else{
                    count+=2;
                    sum+=div2+div;
                }
            }

            if(count>4) return 0;
        }
        return count ==4 ? sum:0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(int &num:nums){
            res+=func(num);
        }
        return res;
    }
};
