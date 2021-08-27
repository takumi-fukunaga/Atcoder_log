//二項係数
typedef long long ll
ll kaijo[1000010];
void init() {
	kaijo[0] = 1;
	for (ll i = 1;i <= 1000000;i++)kaijo[i] = (kaijo[i - 1] * i) % N;
}
 
ll inv(ll x,ll power) {
	ll res = 1;
	ll k = power;
	ll y = x%N;
	while (k) {
		if (k & 1)res = (res*y) % N;
		y = (y%N*y%N) % N;
		k /= 2;
	}
	return res;
}

ll Pow(ll x,ll power,ll r){
	ll res = 1;
	ll k = power;
	ll y = x%r;
	while (k) {
		if (k & 1)res = (res*y) % r;
		y = (y%r*y%r) % r;
		k /= 2;
	}
	return res;
}

ll Comb(ll n, ll k) {
	if (n < 0 || k < 0 || (n - k) < 0)return 0;
	ll b = kaijo[n];
	ll c = kaijo[n - k];
	ll d = kaijo[k];
	ll cd = (c*d) % N;
	return ((b%N)*(inv(cd,N-2)) % N) % N;
}