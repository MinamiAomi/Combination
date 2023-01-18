#include "main.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <stdio.h>
#include <time.h>


template <class ...Args>
std::string Format(const std::string& fmt, Args ...args)
{
	std::size_t len = snprintf(nullptr, 0, fmt.c_str(), args ...);
	std::vector<char> buf(len + 1);
	snprintf(buf.data(), len + 1, fmt.c_str(), args ...);
	return std::string(buf.data());
}

/// <summary>
/// ŠKæ
/// </summary>
/// <param name="n">®”</param>
/// <returns></returns>
int factorial(int n) {
	int num = 1;
	for (int i = 2; i <= n; i++) {
		num *= i;
	}
	return num;
}
/// <summary>
/// ‡—ñ
/// </summary>
/// <param name="n">Œ³‚Ì”</param>
/// <param name="r">‘I‚Ô”</param>
/// <returns>‘”</returns>
int permutation(int n, int r) {
	int num = 1;
	for (int i = 1; i <= r; i++) {
		num = num * (n - i + 1);
	}
	return num;
}
/// <summary>
/// ‘g‚İ‡‚í‚¹
/// </summary>
/// <param name="n">Œ³‚Ì”</param>
/// <param name="r">‘I‚Ô”</param>
/// <returns>‘”</returns>
constexpr int combination(int n, int r) {
	int num = 1;
	for (int i = 1; i <= r; i++) {
		num = num * (n - i + 1) / i;
	}
	return num;
}

using namespace std;

int main() {

	srand((unsigned int)time(nullptr));
	
	const int kArrayConst = 10;
	const int kPair = 2;
	const int comb = combination(kArrayConst, kPair);
	int array[kArrayConst] = {};
	
	{
		int i = 0;
		for (auto& it : array) {
			//it = rand() % 10;
			it = i;
			i++;
		}
	}
	
	for (int i = 0; i < kArrayConst; i++) {
		std::cout << array[i];

		if (i != kArrayConst - 1) {
			std::cout << ", ";
		}
		else {
			std::cout << std::endl;
		}
	}

	std::cout << std::endl << Format("%d C %d = %d", kArrayConst, kPair, comb) << std::endl << std::endl;
	
	std::array<std::array<int, kPair>, comb> index;
	{
		int i, j;
		int arrange[2] = {};

		
		for (int k = 0; k < comb; k++) {
			for (i = kPair - 1; 0 <= i; i--) {
				if (arrange[i] < kArrayConst - kPair + i) {
					arrange[i] += 1;
					for (j = i; j < kPair - 1; j++) {
						arrange[j + 1] = arrange[j] + 1;
					};
					break;
				}
			}
			for (i = 0; i < kPair; i++) {
				index.at(k).at(i) = array[arrange[i]];
			}
		}
	}
	

	End();
	return 0;
}