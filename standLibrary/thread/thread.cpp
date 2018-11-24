// thread.cpp : Defines the entry point for the console application.
//

#include <thread>
#include <iostream>

void sum(int* input, int size, int* output) {
	*output = 0;
	for (int i =0 ; i < size; ++i) {
		(*output) = (*output) + input[i];
	}
}

int main()
{
	int input = 0;
	std::cin >> input;
	if (input <= 0) {
		std::cout << "Unavaliable data size" << std::endl;
	}
	int *num = new int[input];
	for (int i = 0; i < input; ++i) {
		num[i] = i;
	}
	int output = 0;
	std::thread t(sum, num, input, &output);
	if (t.joinable()) {
		t.join();
	}
	std::cout << "sum: " << output << std::endl;
    return 0;
}

