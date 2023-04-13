/************************************************************************
 * File: main.cpp
<<<<<<< HEAD
 * Author: ·¨¶v¦w
 * Create Date: 2023-04-12
 * Editor: ·¨¶v¦w
 * Update Date:2023-04-13
 * Description: Big int operation
=======
 * Author: æ¥Šéˆžå®‰
 * Create Date: 2023-04-12
 * Editor: æ¥Šéˆžå®‰
 * Update Date:2023-04-12
 * Description: Draw and print out the canvas.
>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
 ************************************************************************/
#define MAX 1024
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
<<<<<<< HEAD
//BigInt struct is use to input and save  large number and print the large number
=======

>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
struct BigInt
{
    int num[MAX];
    int length;
    bool valid;
<<<<<<< HEAD
    //init BigInt struct 
    BigInt()
    {
        fill(num, num + MAX + 1, 0);
        length = 0;
        valid = true;
    }
    //Intent:check number valid or not ,and string to int array
    //Pre:input string
    //Post:should not output
    void  input(string& s)
    {
        length = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < length; i++)
        {   
            //checkt number valid or not,if not valid ,valid  = false
            if (s[i] < '0' || s[i] > '9')
            {
                valid = false;
                return;
=======

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
>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
            }
            num[i] = s[i] - '0';
        }
    }
<<<<<<< HEAD
    //Intent:print the large number
    //Pre:should not input 
    //Post:print the large number
    void print()
    {
        for (int i = length - 1; i >= 0; i--)
        {
            cout << num[i];
        }
    }
};
//Intent:sum the two number and return BigInt result
//Pre:input two BigInt and sum 
//Post:return BigInt
BigInt bSum(BigInt const& lhs, BigInt const& rhs)
{
    int l = max(lhs.length, rhs.length);
    int sum = 0;
    int carry = 0;
    BigInt res;
    //sum two number
    for (int i = 0; i < l; i++)
=======

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
>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
    {
        sum = lhs.num[i] + rhs.num[i] + carry;
        res.num[i] = sum % 10;
        carry = sum / 10;
    }
<<<<<<< HEAD
    //if carry is up to 0 ,sum carry
    if (carry)
=======
    if(carry)
>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
    {
        res.num[l] = carry;
        l++;
    }
    res.length = l;
    return res;
}
<<<<<<< HEAD
//Intent:Dif the two number and return BigInt result
//Pre:input two BigInt and dif 
//Post:return BigInt
BigInt bDif(BigInt const& lhs, BigInt const& rhs)
{
    int l = max(lhs.length, rhs.length);
    int borrow = 0;
    BigInt res;
    for (int i = 0; i < l; i++)
    {
        res.num[i] = lhs.num[i] - rhs.num[i] - borrow;
        if (res.num[i] < 0)
        {
            borrow = 1;
=======

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
>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
            res.num[i] += 10;
        }
        else
        {
            borrow = 0;
        }
    }
<<<<<<< HEAD
    //if have 0 in the head , length --
    for (int i = l - 1; i >= 1 && res.num[i] == 0; i--)
=======
    for(int i=l-1;i>=0&&res.num[i]==0;i--)
>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
    {
        l--;
    }
    res.length = l;
    return res;
}
<<<<<<< HEAD
//Intent:Product the two number and return BigInt result
//Pre:input two BigInt and Product 
//Post:return BigInt
BigInt bPro(BigInt const& lhs, BigInt const& rhs)
{
    int l = lhs.length + rhs.length;
    BigInt res;
    int sum = 0, carry = 0;
    for (int i = 0; i < rhs.length; i++)
    {
        for (int j = 0; j < lhs.length; j++)
        {
            sum = res.num[i + j] + lhs.num[j] * rhs.num[i];
            res.num[i + j] = sum % 10;
            res.num[i + j + 1] += sum / 10;
        }
    }
    //if have 0 in the head , length --
    for (int i = l - 1; i >= 1 && res.num[i] == 0; i--)
=======

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
>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
    {
        l--;
    }
    res.length = l;
    return res;
}

int main()
{
<<<<<<< HEAD
    string x, y;
    //input two string until eof
    while (cin >> x >> y)
    {   
        //check the dif result is negative or not
        bool negative = false;
        //check the two number size ,keep x aways bigger then y
        if (x.size() < y.size() || x.size() == y.size() && x < y)
        {
            swap(x, y);
            negative = true;
        }
        BigInt a, b, res;
        //input two number convert to BigInt struct
        a.input(x);
        b.input(y);
        //sum two number
        res = bSum(a, b);
        //print two number
        res.print();
        cout << endl;
        //dif two number 
        res = bDif(a, b);
        //if have negative print "-"
        if (negative)cout << "-";
        //print dif
        res.print();
        cout << endl;
        //product two number
        res = bPro(a, b);
        //print product
        res.print();
        cout << endl;
    }
}
=======
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
>>>>>>> 2881880c2dfe3bdc326ae80781884b09518483af
