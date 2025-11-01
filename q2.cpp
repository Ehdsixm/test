#include <iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;

bool distinct(const string& enter) {
	int i = 0;
	if (enter[0] == 'R') {
		for (char c : enter) {
			if (isdigit(c)) {
				for (int a = i + 1; a < enter.length(); a += 1) {
					if (isdigit(enter[a])) {
						continue;
					}
					else {
						return true;
					}
				}
				return false;
			}
			else {
				i += 1;
			}
		}
	}
	else {
		return false;
	}

	return false;
}

int lton(char letter) {
	switch (letter) {
	    case 'A' :
		    return 1;
		case 'B':
			return 2;
		case 'C':
			return 3;
		case 'D':
			return 4;
		case 'E':
			return 5;
		case 'F':
			return 6;
		case 'G':
			return 7;
		case 'H':
			return 8;
		case 'I':
			return 9;
		case 'J':
			return 10;
		case 'K':
			return 11;
		case 'L':
			return 12;
		case 'M':
			return 13;
		case 'N':
			return 14;
		case 'O':
			return 15;
		case 'P':
			return 16;
		case 'Q':
			return 17;
		case 'R':
			return 18;
		case 'S':
			return 19;
		case 'T':
			return 20;
		case 'U':
			return 21;
		case 'V':
			return 22;
		case 'W':
			return 23;
		case 'X':
			return 24;
		case 'Y':
			return 25;
		case 'Z':
			return 26;


	}


}

char ntol(int num) {
	switch (num) {
	case 1:
		return 'A';
	case 2:
		return 'B';
	case 3:
		return 'C';
	case 4:
		return 'D';
	case 5:
		return 'E';
	case 6:
		return 'F';
	case 7:
		return 'G';
	case 8:
		return 'H';
	case 9:
		return 'I';
	case 10:
		return 'J';
	case 11:
		return 'K';
	case 12:
		return 'L';
	case 13:
		return 'M';
	case 14:
		return 'N';
	case 15:
		return 'O';
	case 16:
		return 'P';
	case 17:
		return 'Q';
	case 18:
		return 'R';
	case 19:
		return 'S';
	case 20:
		return 'T';
	case 21:
		return 'U';
	case 22:
		return 'V';
	case 23:
		return 'W';
	case 24:
		return 'X';
	case 25:
		return 'Y';
	case 26:
		return 'Z';
	}
}







int main() {
	int cishu = 0;
	cout << "请输入次数：";
	cin >> cishu;
	cout << endl;
	for (int shu = 0; shu < cishu; shu += 1) {
		string code = "";
		cout << "请输入编码：";
		cin >> code;
		cout << endl;

		if (distinct(code) == true) {
			int j = 0;
			int num1 = 0;
			int h1 = 0;
			int h2 = 0;
			string result = "";
			for (char c1 : code) {
				if (c1 == 'C') {
					break;

				}
				else {
					j += 1;
				}
			}
			for (int k = 1; k < j; k += 1) {
				h1 = code[k];
				num1 += pow(10, j - k) * h1;
			}
			while (num1 > 26) {
				h2 = num1 % 26;
				char cr = ntol(h2);
				result = result + cr;

			}
			reverse(result.begin(), result.end());
			cout << result;
			for (int l = j + 1; l < code.length() + 1; l += 1) {
				cout << code[l];
			}
			cout << endl;


		}
		else {
			int n3 = 0;
			int lin = 0;
			for (char c2 : code) {
				if (isdigit(c2)) {
					break;

				}
				else {
					n3 += 1;

				}

			}
			for (int b1 = 1; b1 < n3 + 1; b1 += 1) {
				int f1 = lton(code[b1]);
				lin += pow(26, n3 - b1) * f1;
			}
			cout << 'R' << lin << 'C';
			for (int b1 = n3 + 2; b1 < code.length() + 1; b1 += 1) {
				cout << code[b1];
			}
		}

	}



	
	
	





	return 0;
}
