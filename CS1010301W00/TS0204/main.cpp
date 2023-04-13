#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Employee
{
    string name;
    string salary;
    string bonus;
};

int main()
{
    int n;
    while(cin>>n)
    {
       int nameL =0,salaryL = 0,bonusL = 0;
      vector<Employee> em(n);
      for(int i=0;i<n;i++)
      {
          cin>>em[i].name>>em[i].salary>>em[i].bonus;
          nameL = max(nameL,(int)em[i].name.size()); 
          salaryL = max(salaryL,(int)em[i].salary.size());
          bonusL = max(bonusL,(int)em[i].bonus.size());
      }
      for(int i=0;i<n;i++)
      {
          cout<<setw(nameL)<<em[i].name<<"|";
          cout<<setw(salaryL+2)<<em[i].salary<<"|";
          cout<<setw(bonusL+2)<<em[i].bonus<<endl;
      }
    }
    return 0;
}
