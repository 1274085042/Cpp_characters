#include<iostream>
using namespace std ;

const int SIZE = 80;

char *left(char const *, int n = 1);
unsigned long left(unsigned long num,unsigned ct);

int main()
{
char const *trip="Hawaii!!";
unsigned long n=123456789;

int i;
char *temp;
for (i=1;i<10;i++)
{
    cout<<left(n,i)<<endl;
    temp=left(trip,i);
    cout<<temp<<endl;
    delete temp;
}
	

	system("pause");
	return 0;
}


char *left(char const *s, int n)
{
	if (n < 0)
		n = 0;
	char *p = new char[n+1];
	int i;
	for (i = 0; i < n&&s[i]; i++)
	{
		p[i] = s[i];
	}
	
	p[i] = '\0';
	return p;
}

unsigned long left(unsigned long num,unsigned ct)
{
    int weishu=1;
    unsigned long n=num;
    if (ct==0 ||num==0)
    {
        return 0;
    } 
    else
    {
        while (n/=10)
        {
            weishu++;
        }
        if (ct<weishu)
        {
            ct=weishu-ct;
            while (ct--)
            {
                num=num/10;
            }
            
        return num;
        }
        else
        {
          return num;
        }
    }
    
}