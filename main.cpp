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
/// �K��
/// </summary>
/// <param name="n">����</param>
/// <returns></returns>
int factorial(int n) {
	int num = 1;
	for (int i = 2; i <= n; i++) {
		num *= i;
	}
	return num;
}
/// <summary>
/// ����
/// </summary>
/// <param name="n">���̐�</param>
/// <param name="r">�I�Ԑ�</param>
/// <returns>����</returns>
int permutation(int n, int r) {
	int num = 1;
	for (int i = 1; i <= r; i++) {
		num = num * (n - i + 1);
	}
	return num;
}
/// <summary>
/// �g�ݍ��킹
/// </summary>
/// <param name="n">���̐�</param>
/// <param name="r">�I�Ԑ�</param>
/// <returns>����</returns>
constexpr int combination(int n, int r) {
	int num = 1;
	for (int i = 1; i <= r; i++) {
		num = num * (n - i + 1) / i;
	}
	return num;
}

using namespace std;

struct Combi {
	int indexX; // �g�ݍ��킹�̉E��
	int indexY; // �g�ݍ��킹�̍���
	int x; // ����
	int y; // �E��
	int z; // ����
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
	
	// array�̑g�ݍ��킹�����X�g�A�b�v
	// �g�ݍ��킹�����郊�X�g
	std::vector<Combi> combiList;
	// �������[�v 0 ~ i ~ n - 1
	for (int i = 0; i < kArrayConst - 1; i++) {
		// �E�����[�v i ~ j ~ n
		for (int j = i + 1; j < kArrayConst; j++) {
			Combi tmp = {};
			tmp.indexX = i;
			tmp.indexY = j;
			tmp.x = array[i];
			tmp.y = array[j];
			tmp.z = tmp.x * tmp.y;
			// ���X�g�̍Ō���ɒǉ�
			combiList.emplace_back(tmp);
		}
	}
	// ���X�g���o��
	for (const auto& it : combiList) {
		std::cout << it;
	}
	
	std::cout << std::endl << Format("%d C %d = %d", kArrayConst, kPair, combiList.size());

	End();
	return 0;
}