/*Write a C++ program to accpet worker information Worker_Name, No_Of_Hours_Worked,
Pay_Rate and Salary. Write necessary functions to calculate and display the salary of Worker. (Use
Default values for Pay_Rate Rs. 500 per hours)*/
#include<iostream>
using namespace std;
class worker{
	private:
		string worker_name;
		float no_of_hrs;
		float salary=0;
		
		public:
			float r=500;
			void get_data(string worker_name,float no_of_hrs,float salary=0)
			{
				this->worker_name=worker_name;
				this->no_of_hrs=no_of_hrs;
				salary=no_of_hrs=no_of_hrs*r;
				this->salary=salary;
			}
				
			void set()
			{
			cout<<"\n Worker Name is "<<worker_name<<"\nHe working for "<<no_of_hrs<<"hrs.";
				cout<<" His salary is"<<salary;
			}
			
		
};
int main(){
	worker w;
	w.get_data("Darshan",40);
	w.set();
}