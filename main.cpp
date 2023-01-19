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
/// 階乗
/// </summary>
/// <param name="n">整数</param>
/// <returns></returns>
int factorial(int n) {
	int num = 1;
	for (int i = 2; i <= n; i++) {
		num *= i;
	}
	return num;
}
/// <summary>
/// 順列
/// </summary>
/// <param name="n">元の数</param>
/// <param name="r">選ぶ数</param>
/// <returns>総数</returns>
int permutation(int n, int r) {
	int num = 1;
	for (int i = 1; i <= r; i++) {
		num = num * (n - i + 1);
	}
	return num;
}
/// <summary>
/// 組み合わせ
/// </summary>
/// <param name="n">元の数</param>
/// <param name="r">選ぶ数</param>
/// <returns>総数</returns>
constexpr int combination(int n, int r) {
	int num = 1;
	for (int i = 1; i <= r; i++) {
		num = num * (n - i + 1) / i;
	}
	return num;
}

using namespace std;

struct Combi {
	int indexX; // 組み合わせの右側
	int indexY; // 組み合わせの左側
	int x; // 左辺
	int y; // 右辺
	int z; // 結果
};

std::ostream& operator<<(std::ostream& o, const Combi& c) {
	return o << Format("[%2d:%2d] %d * %d = %2d", c.indexX,c.indexY,c.x,c.y,c.z) <<  std::endl;
}

int main() {

	srand((unsigned int)time(nullptr));
	
	const int kArrayConst = 10;
	const int kPair = 2;
	int array[kArrayConst] = {};
	
	{
		int i = 0;
		for (auto& it : array) {
			it = rand() % 10;			
		}
	}
	
	for (int i = 0; i < kArrayConst; i++) {
		std::cout << array[i];

		if (i != kArrayConst - 1) {
			std::cout << ", ";
		}
		else {
			std::cout << std::endl << std::endl;
		}
	}
	
	// arrayの組み合わせをリストアップ
	// 組み合わせが入るリスト
	std::vector<Combi> combiList;
	// 左側ループ 0 ~ i ~ n - 1
	for (int i = 0; i < kArrayConst - 1; i++) {
		// 右側ループ i ~ j ~ n
		for (int j = i + 1; j < kArrayConst; j++) {
			Combi tmp = {};
			tmp.indexX = i;
			tmp.indexY = j;
			tmp.x = array[i];
			tmp.y = array[j];
			tmp.z = tmp.x * tmp.y;
			// リストの最後尾に追加
			combiList.emplace_back(tmp);
		}
	}
	// リストを出力
	for (const auto& it : combiList) {
		std::cout << it;
	}
	
	std::cout << std::endl << Format("%d C %d = %d", kArrayConst, kPair, combiList.size());

	End();
	return 0;
}