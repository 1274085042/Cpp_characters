printtuple.h   
重载运算符<<用来打印tuple
```
#include "printtuple.h"  
tuple<int, float, string> t1(41, 6.3, "nico");  
cout << t1 << endl;
```