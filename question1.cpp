#include<iostream>
using namespace std;

int main()
{
	
	int m;
	cout <<"输入m:";
	cin >> m;
	cout << endl;
	int n;
	cout << "输入n:";
	cin >> n;
	cout << endl;
	int a;
	cout << "输入a:";
	cin >> a;
	cout << endl;
	if (a > m||a > n) {
		cout << "砖不能这么大"<<endl;

	}
	else {
		int l, h;
		if (m % a == 0) {
			l = m / a;
		}
		else {
			l = m / a;
			l += 1;
		}
		if (n % a == 0) {
			h = n / a;
		}
		else {
			h = n / a;
			h += 1;
		}
		int num = h * l;
		cout << "一共需要" << num << "块砖" << endl;


	}

	return 0;
}