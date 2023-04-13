/************************************************************************
 * File: main.cpp
 * Author: 楊鈞安
 * Create Date: 2023-04-12
 * Editor: 楊鈞安
 * Update Date:2023-04-12
 * Description: Draw and print out the canvas.
 ************************************************************************/
#define MAX 1024
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct BigInt
{
    int num[MAX];
    int length;
    bool valid;

    BigInt()
    {
        fill(num,num+MAX+1,0);
        length = 0;
        valid = true;
    }
    void  input(string& s)
    {
        length = s.size();
        reverse(s.begin(),s.end());
        for(int i=0;i<length;i++)
        {
            if(s[i] < '0' || s[i] > '9')
            {
                valid = false;
                return ;
            }
            num[i] = s[i] - '0';
        }
    }

    void print()
    {
        for(int i=length-1;i>=0;i--)
        {
            cout<<num[i];
        }
    }
};
BigInt bSum(BigInt const &lhs,BigInt const &rhs)
{
    int l = max(lhs.length,rhs.length);
    int sum = 0;
    int carry = 0;
    BigInt res;
    for(int i=0;i<l;i++)
    {
        sum = lhs.num[i] + rhs.num[i] + carry;
        res.num[i] = sum % 10;
        carry = sum / 10;
    }
    if(carry)
    {
        res.num[l] = carry;
        l++;
    }
    res.length = l;
    return res;
}

BigInt bDif(BigInt const &lhs,BigInt const &rhs)
{   
    int l = max(lhs.length,rhs.length);
    int borrow = 0;
    BigInt res;
    for(int i=0;i<l;i++)
    {
        res.num[i] = lhs.num[i] - rhs.num[i] - borrow;
        if(res.num[i]<0)
        {
            borrow  = 1;
            res.num[i] += 10;
        }
        else
        {
            borrow = 0;
        }
    }
    for(int i=l-1;i>=0&&res.num[i]==0;i--)
    {
        l--;
    }
    res.length = l;
    return res;
}

BigInt bPro(BigInt const &lhs,BigInt const &rhs)
{  
    int l = lhs.length + rhs.length; 
    BigInt res;
    int sum = 0,carry = 0;
    for(int i=0;i<rhs.length;i++)
    {   
        for(int j=0;j<lhs.length;j++)
        {
            sum = res.num[i+j] +  lhs.num[j] * rhs.num[i];
            res.num[i+j] = sum % 10;
            res.num[i+j+1]+= sum / 10;
        }
    }
    for(int i=l-1;i>=0&&res.num[i]==0;i--)
    {
        l--;
    }
    res.length = l;
    return res;
}

int main()
{
    string x,y;
    while(cin>>x>>y)
    {   
        if(x.size()<y.size()||x.size()==y.size()&&x<y)
        {
            swap(x,y);
        }
        BigInt a,b,res;
        a.input(x);
        b.input(y);
        res = bSum(a,b);
        res.print();
        cout<<endl;
        res = bDif(a,b);
       res.print();
        cout<<endl;
        res = bPro(a,b);
        res.print();
        cout<<endl;
    }
}
