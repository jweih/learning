#include "Test.h"

int main(void){

	//Test t(10);
	////带一个参数的构造函数，充当的是普通构造函数
	//t=20;//将20这个整数赋值给t对象
	////1，调用转换构造函数将20这个整数转换成类类型(生成一个临时对象）
	////2，将临时对象赋值给t对象（调用的是=运算符）

	//Test t2;

	Test t(10);//等价于Test t(10);这里的=号，不是运算符，表示初始化。

	//t=20;//赋值操作
	//Test t2;
	//t=t2;//赋值操作t.operator=(t2);

	//Test t;
	//t=10;
	return 0;
}