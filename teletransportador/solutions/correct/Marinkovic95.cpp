#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	ll A[N], C[N];
	for(int i = 0; i < N; ++i)
		cin >> A[i];
	for(int i = 0; i < N; ++i)
		cin >> C[i];

	ll l = *min_element(A,A+N), r = *max_element(A,A+N);
	auto eval = [&](ll x)
	{
		ll ans = 0;
		for(int i = 0; i < N; ++i)
			ans += C[i]*abs(A[i]-x);
		return ans;
	};
	while(l != r)
	{
		ll m = (l+r)/2;
		if(eval(m) <= eval(m+1))
			r = m;
		else
			l = m+1;
	}

	cout << l << '\n';
	return 0;
}