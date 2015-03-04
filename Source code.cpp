#include <iostream>
#include <string>
#include <stack>

using namespace std;


void main()
{
	unsigned int A[5535];       // Array of minterms.
	unsigned int B[5535];      // Array of no of bits.
	string C[5535];
	stack <int> s;
	for (int i = 0; i < 327; i++)
	{
		A[i] = 0;
		B[i] = 0;
		C[i] = "";
	}
	cout << "input the minterm including dont cares and enter -1 to signal the ending of the minterms" << endl;

	int i = 0;
	while (true){
		cout << "input the minterm including dont cares and enter -1 to signal the ending of the minterms" << endl;
		cin >> i;
		if (i == -1){
			break;
		}
		else
			A[i] = 1;
		
	}

	for (int j = 0; j < 327; j++){
		if (A[j] == 1){
			int instWord2 = j;
			int total = 0;
			int count = 0;
			while (instWord2>0)
			{
				total = instWord2 % 2;
				if (total == 1)
					count++;
				instWord2 /= 2;
				s.push(total);
			}
			while (!s.empty())
			{
				int x = s.top();
				C[j] = C[j] + "" + to_string(x);
				s.pop();
			}

			while (C[j].size() <16){
				C[j] = "0" + C[j];
			}
			B[j] = count;

		}
	}

	for (int i = 0; i < 10; i++){
		if (A[i] == 1){
			cout << C[i] << endl;
		}
	}

	system("pause");
}