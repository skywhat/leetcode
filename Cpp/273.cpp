#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> smallNum={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
    vector<string> Tens={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    vector<string> largeNum={"","Thousand","Million","Billion"};
    string numberToWords(int num) {
        if(num==0)
            return smallNum[0];
        string res;
        int i=0;
        while(num>0){
            if(num%1000!=0)
                res=help(num%1000)+largeNum[i]+" "+res;
            i++;
            num/=1000;
        }
        int cnt=0;
        for(int i=res.size()-1;i>=0;--i){
            if(res[i]==' ')
                cnt++;
            else
                break;
        }
        return res.substr(0,res.size()-cnt);
    }
    string help(int num){
        if(num==0)
            return "";
        if(num<=20)
            return smallNum[num]+" ";
        if(num<100)
            return Tens[num/10]+" "+help(num%10);
        else
            return smallNum[num/100]+" Hundred "+help(num%100);
    }
};



class Solution2{
public:
	string numberToWords(int num){
		if(num==0)
			return "Zero";
		unordered_map<int,string> m;
		vector<string> nums1={
			"zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
			"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"
		};
		vector<string> nums2={"","","","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety","Hundred"};
		for(int i=0;i<=20;++i)		
			m[i]=nums1[i];
		for(int i=3;i<=10;++i)
			m[10*i]=nums2[i];
		for(int i=21;i<=99;++i){
			if(m[i]==""){
				m[i]=m[i-i%10]+" "+m[i%10];
			}
		}
		vector<string> LargeNum={"","Thousand","Million","Billion"};
		string res;
		int cnt=0,n=num;
		vector<int> num_sep;
		while(n/1000){
			n/=1000;
			cnt++;
		}
		for(int i=cnt;i>0;i--){
			int divisor=pow(1000,i);
			num_sep.push_back(num/divisor);
			num=num%divisor;
		}
		if(num>0)
			num_sep.push_back(num);

		for(int i=0;i<num_sep.size();++i){
			if(num_sep[i]>=100)
				res+=" "+m[num_sep[i]/100]+" "+m[100];
			num_sep[i]%=100;
			if(num_sep[i]>0)
				res+=" "+m[num_sep[i]];
			res+=" "+LargeNum[cnt--];
		}
		res.erase(res.begin());		
		res.erase(--res.end());
		return res;
	}
};

int main(){
	Solution s;
	string res=s.numberToWords(1234567);
	cout<<res<<endl;
	return 0;
}


