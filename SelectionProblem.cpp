//K-th smallest

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void swap(vector<float>&in, int i, int j) {
	float c = in[i];
	in[i] = in[j];
	in[j] = c;
}

int Partition(vector<float>& in, int l, int r, int pos) {
	if (l == r) return l;

	float pivot = in[pos];

	swap(in,pos,l);
	pos = l;

	for (int i = l + 1; i <= r; i++) {
		if (pivot > in[i]) {
			pos++;
			swap(in, i, pos);
		}
	}

	swap(in, l,pos);

	return pos;
}

void kSmallest(vector<float> in,int l, int r, int k) {
	//take a random pos to partition
	int h = (l+r)/2;
	
	//position of value of h after partition
	int pos = Partition(in, l, r, h);
	//cout << pos << endl;
	
	if (pos == k) {
		float val = in[pos];
		cout << "The " << k+1 << "th smallest value: " << val << endl;
		return;
	}

	if (pos < k) kSmallest(in, pos + 1, r, k);
	if (pos > k) kSmallest(in, l, pos - 1, k);

}



int main() { //int argc, char* argv[]
	srand(time(0));

	string filename = "input_3.txt";
	//if (argc == 1) filename = argv[0];

	//global variables
	int n;//input length
	int k;//kth smallest
	vector<float> in;

	//read input from file
	ifstream ifs(filename);

	if (ifs) {
		ifs >> n;
		for (int i = 0; i < n; i++)
		{
			float temp;
			ifs >> temp;
			in.push_back(temp);
		}
		ifs >> k;
		

		//test read float value from input
		//for (int i = 0; i < n; i++)
			//cout << in[i] << " ";
		//cout <<(in[0]+in[1]) << endl;

		kSmallest(in,0,n-1, k-1);
		
		//for (int i = 0; i < n; i++)
			//cout << in[i] << " ";
		//cout << endl;
	}
	else cout << "Error reading input file" << endl;
	ifs.close();
	return 0;
}