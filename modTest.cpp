#include <iostream>

int main()
{
	int result = 0;
	int a = -163;
	int b = 5;
	int a1 = 0;
	
	if(a < 0){
		int division = -(a / b);
		a1 = a + (division+1) * b;
	}
	else a1 = a;
	
	result = a1 % b;
	std::cout << result << std::endl;
}
