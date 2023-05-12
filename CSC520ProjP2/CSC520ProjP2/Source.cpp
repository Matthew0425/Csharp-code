#include <iostream>
#include <vector>
#include <set>

void outputCombos(int, int, int, int, int, int, int, std::set<std::vector<int>>&);

int main() {
	std::set<std::vector<int>> combos;
	std::cout << "Max area: 2000" << std::endl;
	outputCombos(2000, 1, 1, 1, 1, 0, 0, combos);
	std::cout << "done" << std::endl;
	//combos.clear();
	std::cout << "Max area: 3000" << std::endl;
	outputCombos(3000, 1, 1, 1, 1, 0, 0, combos);
	std::cout << "done" << std::endl;
	//combos.clear();
	std::cout << "Max area: 4000" << std::endl;
	outputCombos(4000, 1, 1, 1, 1, 0, 0, combos);
	std::cout << "done" << std::endl;
}

void outputCombos(int limit, int i, int j, int k, int q, int x, int factor, std::set<std::vector<int>> &c) {
	int w = 250;
	int ia = 100;
	int im = 200;
	int m = 300;
	int lp = 500;


	if (limit - (((w * i) + (ia * j) + (im * k) + (m * q) + (lp * x))*(1.7 - .7*(factor))) > 0) {
		std::vector<int> dummy;
		dummy.push_back(i);
		dummy.push_back(j);
		dummy.push_back(k);
		dummy.push_back(q);
		dummy.push_back(x);
		int otherDummy = c.size();
		c.insert(dummy);
		if (c.size() > otherDummy && x == 1 &&  i == 4 && (((w * i) + (ia * j) + (im * k) + (m * q) + (lp * x)) * (1.7 - .7 * (factor))) > 3000) {
			std::cout << i << "w " << j << "ia " << k << "im " << q << "m " << x << "lp " << factor << "factor   " << (((w * i) + (ia * j) + (im * k) + (m * q) + (lp * x)) * (1.7 - .7 * (factor))) << std::endl;
		}
		else if (c.size() > otherDummy && x == 1 && (((w * i) + (ia * j) + (im * k) + (m * q) + (lp * x)) * (1.7 - .7 * (factor))) > 2000) {
			std::cout << i << "w " << j << "ia " << k << "im " << q << "m " << x << "lp " << factor << "factor   " << (((w * i) + (ia * j) + (im * k) + (m * q) + (lp * x)) * (1.7 - .7 * (factor))) << std::endl;
		}
		else if (c.size() > otherDummy && factor == 0) {
			std::cout << i << "w " << j << "ia " << k << "im " << q << "m " << x << "lp " << factor << "factor   " << (((w * i) + (ia * j) + (im * k) + (m * q) + (lp * x)) * (1.7 - .7 * (factor))) << std::endl;
		}
	}

	if (i < 4) 
	{
		outputCombos(limit, i * 2, j, k, q, x, factor, c);
	}
	if (j < 4) 
	{
		outputCombos(limit, i, j + 1, k, q, x, factor, c);
	}
	if (k < 4) 
	{
		outputCombos(limit, i, j, k + 1, q, x, factor, c);
	}
	if (q < 4) 
	{
		outputCombos(limit, i, j, k, q + 1, x, factor, c);
	}
	if (x < 1) {
		outputCombos(limit, i, j, k, q, x + 1, factor, c);
	}
	if (factor < 1) {
		outputCombos(limit, i, j, k, q, x, factor + 1, c);
	}
	return;
	/*if (i == 4 || j == 4 || k == 4 || q == 4) {
		return;
	}
	else
	{
		outputCombos(limit, i * 2, j, k, q);
		outputCombos(limit, i, j + 1, k, q);
		outputCombos(limit, i, j, k + 1, q);
		outputCombos(limit, i, j, k, q + 1);
	}*/


	/*if (i < 4 && j < 4 && k < 4 && q < 4) {
		outputCombos(limit, i*2, j, k, q);
		outputCombos(limit, i, j + 1, k, q);
		outputCombos(limit, i, j, k + 1, q);
		outputCombos(limit, i, j, k, q + 1);
	}
	else if (i == 4 && j < 4 && k < 4 && q < 4) {
		outputCombos(limit, i, j + 1, k, q);
		outputCombos(limit, i, j, k + 1, q);
		outputCombos(limit, i, j, k, q + 1);
	}
	else if (j == 4 && i < 4 && k < 4 && q < 4) {
		outputCombos(limit, i * 2, j, k, q);
		outputCombos(limit, i, j, k + 1, q);
		outputCombos(limit, i, j, k, q + 1);
	}
	else if (k == 4 && i < 4 && j < 4 && q < 4) {
		outputCombos(limit, i * 2, j, k, q);
		outputCombos(limit, i, j + 1, k, q);
		outputCombos(limit, i, j, k, q + 1);
	}
	else if (q == 4 && i < 4 && j < 4 && k < 4) {
		outputCombos(limit, i * 2, j, k, q);
		outputCombos(limit, i, j + 1, k, q);
		outputCombos(limit, i, j, k + 1, q);
	}
	else if (i == 4 && j == 4 && k < 4 && q < 4) {
		outputCombos(limit, i, j, k + 1, q);
		outputCombos(limit, i, j, k, q + 1);
	}
	else if (i == 4 && j < 4 && k == 4 && q < 4) {
		outputCombos(limit, i, j + 1, k, q);
		outputCombos(limit, i, j, k, q + 1);
	}
	else if (i == 4 && j < 4 && k < 4 && q == 4) {
		outputCombos(limit, i, j + 1, k, q);
		outputCombos(limit, i, j, k + 1, q);
	}
	else if (i < 4 && j == 4 && k < 4 && q == 4) {
		outputCombos(limit, i*2 , j, k, q);
		outputCombos(limit, i, j, k + 1, q);
	}
	else if (i < 4 && j == 4 && k == 4 && q < 4) {
		outputCombos(limit, i*2, j, k, q);
		outputCombos(limit, i, j, k, q + 1);
	}
	else if (i < 4 && j == 4 && k == 4 && q < 4) {
		outputCombos(limit, i*2, j, k, q);
		outputCombos(limit, i, j, k, q + 1);
	}
	else if (i < 4 && j < 4 && k == 4 && q == 4) {
		outputCombos(limit, i*2, j, k, q);
		outputCombos(limit, i, j + 1, k, q);
	}
	else if (i < 4 && j == 4 && k == 4 && q == 4) {
		outputCombos(limit, i*2, j, k, q);
	}
	else if (i == 4 && j < 4 && k == 4 && q == 4) {
		outputCombos(limit, i, j + 1, k, q);
	}
	else if (i == 4 && j == 4 && k < 4 && q == 4) {
		outputCombos(limit, i, j, k + 1, q);
	}
	else if (i == 4 && j == 4 && k == 4 && q < 4) {
		outputCombos(limit, i, j, k, q + 1);
	}
	else {
		return;
	}*/

}