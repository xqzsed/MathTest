#pragma once
#include "lib.h"
#include <ctime>
#include <cstdlib>
#include <clocale>
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

MathTest::MathTest(int count)
	: MathTest(count, -100, 100, '\0') {
}

MathTest::MathTest(int count, int minValue, int maxValue)
	: MathTest(count, minValue, maxValue, '\0') {
}

MathTest::MathTest(int count, int minValue, int maxValue, char operation)
	: count(count), correctCount(0) {
	tasks = new Task[count];
	userAnswers = new int[count];

	for (int i = 0; i < count; ++i) {
		tasks[i] = Task(minValue, maxValue);
		userAnswers[i] = 0;
	}
}

MathTest::~MathTest() {
	delete[] tasks;
	delete[] userAnswers;
}
void MathTest::run() {
	correctCount = 0;
	for (int i = 0; i < count; ++i) {
		cout << "Вопрос " << (i + 1) << count << ": ";
		cout << tasks[i].num_1 << " " << tasks[i].operation << " " << tasks[i].num_2 << " = ";
		cin >> userAnswers[i];

		if (userAnswers[i] == tasks[i].answer) {
			++correctCount;
		}
	}
}
void MathTest::showStatistics() const {
	cout << "Правильных ответов: " << correctCount << " из " << count << endl;
	double percent = (count > 0) ? (100.0 * correctCount / count) : 0.0;
	cout << "Процент: " << percent << "%" << endl;
}