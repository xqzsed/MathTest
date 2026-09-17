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

	Task(int minValue = -100, int maxValue = 100, char operation = '\0');
};
class MathTest {
	Task* _tasks;
	int _count;
	int* _userAnswers;
	int _correctCount;
public:
	MathTest(int count);
	MathTest(int count, int minValue, int maxValue);
	MathTest(int count, int minValue, int maxValue, char operation);
	~MathTest();

	void run();

	void showStatistics() const;

	inline int getCount() const noexcept { return _count; }
	inline int getCorrectCount() const noexcept { return _correctCount; }
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
	case '/':
		if (num_2 != 0) {
			ans = num_1 / num_2;
		}
		else throw invalid_argument("division by zero");
	}
	return ans;
}

Task::Task(int minValue, int maxValue, char operation) {
	if (minValue > maxValue) {
		int tmp = minValue;
		minValue = maxValue;
		maxValue = tmp;
	}

	int range = maxValue - minValue + 1;
	num_1 = rand() % range + minValue;
	num_2 = rand() % range + minValue;

	if (operation == '\0') {
		int op = rand() % 4;
		switch (op) {
		case 0: this->operation = '+'; break;
		case 1: this->operation = '-'; break;
		case 2: this->operation = '*'; break;
		case 3: this->operation = '/'; break;
		}
	}
	else {
		this->operation = operation;
	}//через this, из за возможных конфилктов имен, а переименовывать уже сил нет
	answer = calculate();
}

MathTest::MathTest(int count)
	: MathTest(count, -100, 100, '\0') {
}

MathTest::MathTest(int count, int minValue, int maxValue)
	: MathTest(count, minValue, maxValue, '\0') {
}

MathTest::MathTest(int count, int minValue, int maxValue, char operation): _count(count), _correctCount(0) {
	if (count <= 0) {
		throw std::invalid_argument("count must be > 0");
	}
	_tasks = new Task[_count];
	_userAnswers = new int[_count];

	for (int i = 0; i < _count; ++i) {
		_tasks[i] = Task(minValue, maxValue, operation);
		_userAnswers[i] = 0;
	}
}

MathTest::~MathTest() {
	delete[] _tasks;
	delete[] _userAnswers;
}
void MathTest::run() {
	_correctCount = 0;
	for (int i = 0; i < _count; ++i) {
		cout << "Вопрос " << (i + 1) << "/" << _count << ": ";
		cout << _tasks[i].num_1 << " " << _tasks[i].operation << " " << _tasks[i].num_2 << " = ";
		cin >> _userAnswers[i];

		if (_userAnswers[i] == _tasks[i].answer) {
			++_correctCount;
		}
	}
}
void MathTest::showStatistics() const {
	cout << endl;
	cout << "|           No |";
	for (size_t i = 1; i < (_count + 1); i++) {
		cout << "         " << i << " |";
	}
	cout << "\n+" << string((14 + (12 * _count)), '-') << "+";
	cout << "\n|  Question    |";
	for (size_t i = 0; i < _count; i++) {
		cout << _tasks[i].num_1 << " " << _tasks[i].operation << " " << _tasks[i].num_2 << "    |";

	}
	cout << "\n|  True Answer |";
	for (size_t i = 0; i < _count; i++) {
		cout << "       " << _tasks[i].answer << " |";
	}
	cout << "\n|  Your Answer |";
	for (size_t i = 0; i < _count; i++) {
		cout << "       " << _userAnswers[i] << " |";
	}
	cout << "\n|       Result |";
	for (size_t i = 0; i < _count; i++) {
		cout << "       ";
		if (_userAnswers[i] == _tasks[i].answer) {
			cout << "+ ";

		}
		else { std::cout << "-"; }
		cout << " |";
	}
	cout << endl;
	std::cout << "Total Result : " << _correctCount << " / " << _count << "(mark : ";
	float mark = (static_cast<float>(_correctCount) / _count) * 100;
	if (mark > 90) { std::cout << "A"; }
	else if (mark >= 75) { std::cout << "B"; }
	else if (mark > 50) { std::cout << "C"; }
	else if (mark > 35) { std::cout << "D"; }
	else if (mark > 15) { std::cout << "E"; }
	else { std::cout << "F"; }
	std::cout << " )";
}