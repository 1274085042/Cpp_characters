#include "brass.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const std::string &f, const long &a, const double &b)
{
	fullname = f;
	accnum = a;
	balance = b;
}
void Brass::Deposit(double amt)				
{
	if (amt < 0)
	{
		cout << "Negative deposit not allowed;"
			<< "deposit is cancelled.\n";
	}
	else
	{
		balance += amt;
	}
}
void Brass::Withdraw(double a)   
{
	//set up ###.## format
	format initiaState = setFormat();
	precis prec = cout.precision(2);

	if (a < 0)
	{
		cout << "Withdraw amount must be positve ;"
			<< "Withdraw cancelled.\n";
	}
	else if (a <= balance)
	{
		balance -= a;
	}
	else
	{
		cout << "Withdraw amount of $" << a << " exceeds your balance.\n" << "Withdraw cancelled.\n";
	}
}
double Brass::Balance() const
{
	return balance;
}
void Brass::Viewacct() const			//��ʾ�˻���Ϣ
{
	//set up ###.## format   
	format initiaState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client:" << fullname << endl;
	cout << "Account Number:" << accnum << endl;
	cout << "Balance:$" << balance << endl;
	restore(initiaState, prec);                //restore original format
 }

BrassPlus::BrassPlus(const std::string &f, const long &a, const double &b, const double &m, const double &r):Brass(f,a,b)
{
	maxloan = m;
	rate = r;
	owesbank = 0.0;
}
BrassPlus::BrassPlus(const Brass &b, const double &m, const double &r) :Brass(b)
{
	maxloan = m;
	rate = r;
	owesbank = 0.0;
}
void BrassPlus::Viewacct() const
{
	
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::Viewacct();								
	cout << "Maximum loan:$" << maxloan << endl;
	cout << "Owed to bank:$" << owesbank << endl;
	cout.precision(3);				
	cout << "Loan rate:" << 100 * rate << "%\n";
	restore(initialState, prec);     
}
void BrassPlus::Withdraw(double a)
{
	//set up ###.## format   
	format initialState = setFormat();
	precis prec = cout.precision(2);

	//double b = Balance();
	if (a < Balance())        
	{
		Brass::Withdraw(a);
	}
	else if (a <= Balance() + maxloan - owesbank)		
	{
		double advance = a - Balance();     
		owesbank += advance*(1 + rate);
		cout << "Bank advance :$" << advance << endl;
		cout << "Finance charge :$" << advance*rate << endl;
		Deposit(advance);
		Brass::Withdraw(a);
	}
	else
	{
		cout << "Credit limit exceed. Transaction cancelled.\n";
	}
	restore(initialState, prec);
}
void BrassPlus::Resetmax(double m)		
{
	maxloan = m;
}
void BrassPlus::Resetrate(double r)			
{
	rate = r;
}
void BrassPlus::Resetowes()
{
	owesbank = 0.0;
}

format setFormat()
{
	
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}
void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}