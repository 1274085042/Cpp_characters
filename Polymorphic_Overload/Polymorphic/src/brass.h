#ifndef BRASS_H_
#define BRASS_H_

# include <string>
# include <iostream>

class Brass
{
   	private:
		std::string fullname;
		long accnum;			
		double balance;		
public:
		Brass(const std::string &f = "null",const long &a = -1, const double &b = 0.0);
		void Deposit(double amt);
		virtual void Withdraw(double a);   
		double Balance() const;
		virtual void Viewacct() const;			
		virtual ~Brass()   //虚析构函数，如果析构函数不是虚的，则只调用指针类型的析构函数。即如果Brass指针
		                   //指向的是一个BrassPlus对象，也只能调用Brass析构函数，如果析构函数是虚的，指针指向的是
						   //BrassPlus对象，将调用BrassPlus的析构函数，然后调用基类的析构函数。
						   //因此使用虚析构函数，可以确保释放派生对象时，按正确的顺序调用析构函数。
		{
			std::cout << "~Brass()" << std::endl;  
		};

};

class BrassPlus:public Brass
{
   private:
	double maxloan;   
	double rate;			
	double owesbank;	
public:
	BrassPlus(const std::string &f = "null", const long &a = -1, const double &b = 0.0, const double &m = 500, const double &r = 0.11125);
	BrassPlus(const Brass &b, const double &m = 500, const double &r = 0.11125);
	virtual void Viewacct() const;
	virtual void Withdraw(double a);
	void Resetmax(double m);		
	void Resetrate(double r);			
	void Resetowes();
	~BrassPlus() 
	{
		std::cout << "~BrassPluss()" << std::endl;
	};

};

#endif 