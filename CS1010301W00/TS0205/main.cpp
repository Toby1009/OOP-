#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct BigInt
{
    int number[1024];
    int length;
    bool valid;
   BigInt()
   {
       fill(number,number+1024,0);
        length = 0;
        valid = true;
   }
   void add()
   {
        string s;
        cin>>s;
       length = s.size();
       reverse(s.begin(),s.end());
       for(int i=0;i<length;i++)
       {
            if(s[i]<'0'||s[i]>'9')
            {
                valid = false;
                return ;
            }
            number[i] = s[i] - '0';
       }
   }
   void print()
   {
       for(int i=length-1;i>=0;i--)
       {
           cout<<number[i];
       }
   }
};

BigInt Add(const BigInt &lhs,const BigInt &rhs)
{
    BigInt res;
    int l = max(lhs.length,rhs.length);
    int sum=0,carry=0;
    for(int i=0;i<l;i++)
    {
       sum = lhs.number[i] + rhs.number[i] + carry;
       res.number[i] = sum%10;
       carry = sum/10;
    }
    if(carry)
    {
        res.number[l] = carry;
        l++;
    }
    res.length = l;
    return res;
}

int main()
{
   int n;
   cin>>n;
   while(n--)
   {
       BigInt a,b;
       a.add();
       b.add();
       if(!a.valid || !b.valid)
       {
           cout<<"Not a valid number, please try again.";
       }
       else
       {    
           BigInt res;
            res = Add(a,b);
            res.print();
       }
       cout<<endl;
   }
    return 0;
}
