#include "time.hpp"

int main()
{
	measure_time();

	cout << "-----------------------------------------------------------" << endl;
	cout << "ELEMENTOS REMOVIDOS DAS ESTRUTURAS: " << endl;
	for (auto i : deleted_elements)
	{
		cout << setprecision(6) << fixed << i << "\t";
	}
	cout << "\n";
	cout << "-----------------------------------------------------------" << endl;
	return 0;
}
