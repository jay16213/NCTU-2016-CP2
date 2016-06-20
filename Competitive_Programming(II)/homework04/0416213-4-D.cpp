#include <iostream>
using namespace std;

int Greatest_common_divisor(int n, int m)//compute gcd(n,m)
{
	if (m == 0) return n;
	else return Greatest_common_divisor(m, n%m);
}

int Exgcd(int n, int m, int &x, int &y)//compute gcd(n,m), and return x,y such that nx+my = 1
{
	int gcd = n;
	if (m != 0)
	{
		gcd = Exgcd(m, n%m, y, x);
		y -= (n / m)*x;
	}
	else
	{
		x = 1;
		y = 0;
	}
	return gcd;
}

int main()
{
	int n, m, gcd;
	cin >> n >> m;

	gcd = Greatest_common_divisor(n, m);

	if (gcd != 1) cout << (unsigned long long)n*(m / gcd) << endl;//if gcd != 1,then ans is lcm(n,m)
	else
	{
		if (n == 1 && m == 1) cout << 1 << endl;//n == m == 1,then ans is 1 second
		else if (n == 1) cout << 2 << endl;//n == 1 && m != 1,then ans is 2 seconds
		else if (m == 1) cout << 2 << endl;//m == 1 && n != 1,then ans is 2 seconds
		else
		{
			int x,y;
			unsigned long long ans = 0;

			Exgcd(n, m, x, y);

			if (x <= 0) ans = (unsigned long long)m*y;
			else ans = (unsigned long long)n*x;

			cout << ans << endl;
		}
	}
	return 0;
}
