/*
拷贝构造函数：对象初始化，使用一个传入对象来创建一个新的对象
赋值运算符：将对象赋值给一个已经存在的对象

调用的是拷贝构造函数还是赋值运算符，主要是看是否有新的对象实例产生。
如果产生了新的对象实例，那调用的就是拷贝构造函数；
如果没有，那就是对已有的对象赋值，调用的是赋值运算符
*/


#include <iostream>

using namespace std;

class Person
{
    private:
    int age;
    string name;

    public:
    Person(int a,const string &n)
    {

        age=a;
        //name=new char(strlen(n));
        name=n;
    }
    //拷贝构造函数
    Person(Person *p)
    {
        cout<<"copy constructor."<<endl;
        age=(*p).age;
        name=(*p).name;

    }

    //赋值运算符
    Person & operator=(Person &p)
    {
        cout<<"asign."<<endl;
        age=p.age;
        name=p.name;
        //return *this;
    }

    void show()
    {
        cout<<name<<endl;
    }

};

int main()
{
Person p0 (14,"qin");
p0.show();
Person p1(&p0);
//p1.show();
Person p2(1,"long");
p2=p1;
p2.show();
return 0;
}