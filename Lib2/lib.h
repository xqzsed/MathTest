#pragma once
#include "lib.h"
#include <ctime>
#include <cstdlib>
using namespace std;
struct Task {
	int num_1;
	int num_2;
	char operation;
	int answer;
	int calculate();
	Task(int minValue = -100, int maxValue = 100);
};
class MathTest {
	Task* tasks;
	int count;
	int* userAnswers;
	int correctCount;
public:
	MathTest(int count);
	MathTest(int count, int minValue, int maxValue);
	MathTest(int count, int minValue, int maxValue, char operation);
	~MathTest();

	void run();

	void showStatistics() const;

	int getCount() const { return count; }
	int getCorrectCount() const { return correctCount; }
};

int Task::calculate() {
	int ans = 0;
	switch (operation) {
	case '+':
		ans = num_1 + num_2;
		break;
	case '-':
		ans = num_1 - num_2;
		break;
	case '*':
		ans = num_1 * num_2;
		break;
	}
	return ans;
}

Task::Task(int minValue, int maxValue) {
	int range = maxValue - minValue + 1;
	num_1 = rand() % range + minValue;
	num_2 = rand() % range + minValue;

	int op = rand() % 3;
	switch (op) {
	case 0:
		operation = '+';
		break;
	case 1:
		operation = '-';
		break;
	case 2:
		operation = '*';
		break;
	}
	answer = calculate();
}
