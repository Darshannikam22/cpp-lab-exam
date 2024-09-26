/*Write a program create employee class with members variable as EmpId,Name of Employee and
Salary. For 10 Employees
Print list of all employees.
Print list of employee who got heights salary.*/
#include<iostream>
using namespace std;
class employee{
	private:
		int EmpId;
		string name;
		float salary,sal;
	public:
		void get(int EmpId,string name,float salary){
			this->EmpId=EmpId;
			this->name=name;
			this->salary=salary;
		}
		void set(){
			cout<<"\n EmpId:"<<EmpId<<"\tName:"<<name<<"\t Salary:"<<salary<<endl;
		}
		int sal_ary(){

			return salary;
		}
};
int main(){
	employee obj[10];

	int id,max=0;
	
	string na;
//	cin>>na;
	float sal;
//	cin>>sal;
//	cout<<"\nlist of employee";
	for(int i=0;i<10;i++){
		cout<<"\n Enter Id,Name,Salary\n";
		cin>>id>>na>>sal;
		obj[i].get(id,na,sal);
	}
	for(int i=0;i<10;i++){
		obj[i].set();
			}
	for(int i=0;i<10;i++){
		if(obj[i].sal_ary()>max){
			max=obj[i].sal_ary();
//			obj[i].set();
		}
	}
//		obj[i].set();

	cout<<"\n maximum salary is:"<<max;
	
	
}