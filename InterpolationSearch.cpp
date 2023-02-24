//Interpolation search

#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int interpolation(float* a, int l, int r, float k) {
	if ((l > r) || (k > a[r]) || (k < a[l])) return -1;
	int x = (k - a[l]) * (r - l);
	x = int(x / (a[r] - a[l]));
	x += l;

	if (a[x] == k) return x;
	else if (a[x] > k) return interpolation(a, l, x - 1, k);
	else if (a[x] < k) return interpolation(a, x + 1, r, k);
}
int main() {
	string filename = "input_4.txt";
	ifstream ifs(filename);
	if (ifs) {
		int n;
		ifs >> n;

		float* a = new float[n];

		for (int i = 0; i < n; i++) {
			if (ifs) {
				ifs >> a[i];
			}
			else {
				cout << "Error input file" << endl;
				return 0;
			}
		}

		float k=0.0;
		if (ifs) ifs >> k;

		int indx = interpolation(a, 0, n - 1, k);
		//cout << k << "  " << n << "  " << a[2] << endl;
		cout << indx << endl;
	}
	else cout << "Error read input file" << endl;

	return 0;
}