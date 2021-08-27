/*
    スニペット
    エラトステネスの篩
*/
bool prime[1000010];
void furui() {
	prime[0]=true;
	prime[1]=true;
	int i = 2;
	while (i <= 1000000) {
		int j = 2;
		while (j*j <= i && !prime[i]) {
			if (i%j == 0) {
				prime[i] = true;
				break;
			}
			else j++;
		}
		int z = 2;
		while (!prime[i]) {
			if (i*z <= 1000000) {
				prime[i*z] = true;
				z++;
			}
			else break;
		}
		i++;
	}
}