#include "./src/brass.h"
#include <iostream>

const int CLIENT = 2;

int main()
{
	{
		using std::cout;
		using std::endl;
		using std::cin;

		/*
		Brass piggy("Poreclot", 381299, 4000.00);
		BrassPlus hogy("Horario", 382288, 3000);
		piggy.Viewacct();
		cout << endl;
		hogy.Viewacct();
		cout << endl;
		cout << "Depositing $1000 into the hogy account:\n";
		hogy.Deposit(1000);
		cout << "New balance :$" << hogy.Balance() << endl;
		cout << "Withdraw $4200 from the piggy account:\n";
		piggy.Withdraw(4200);
		cout << "piggy balance :$" << piggy.Balance() << endl;
		cout << "Withdraw $4200 from the hogy account:\n";
		hogy.Withdraw(4200);
		hogy.Viewacct();
		*/

		Brass *clients[CLIENT];
		std::string temp;
		long tempnum;
		double tempbal;
		char kind;

		for (int i = 0; i < CLIENT; i++)
		{
			cout << "Enter  client's name:";
			getline(cin, temp);
			cout << "Enter client's account number:";
			cin >> tempnum;
			cout << "Enter opening balance :$";
			cin >> tempbal;
			cout << "Enter 1 for Brass Account or 2 for BrassPlus Account:";
			while (cin >> kind && (kind != '1' && kind != '2'))
			{
				cout << "Enter either 1 or 2 :";
			}
			if (kind == '1')
			{
				clients[i] = new Brass(temp, tempnum, tempbal);
			}
			else
			{
				double tmax, trate;
				cout << "Enter the overdraft limit :$";
				cin >> tmax;
				cout << "Enter the interest rate as a decimal fraction:";
				cin >> trate;
				clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
			}
			while (cin.get() != '\n')
			{
				continue;
			}
		}
		cout << endl;
		for (int i = 0; i < CLIENT; i++)
		{
			clients[i]->Viewacct();   //指针指向的是什么类型的对象，就调用什么类型的方法
			cout << endl;
		}
		for (int i = 0; i < CLIENT; i++)
		{
			delete clients[i];
			
		}
	}
	system("pause");
	return 0;
}