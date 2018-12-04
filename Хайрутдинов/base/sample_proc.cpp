#include <iostream>
#include "proc.h"

using namespace std;

int main()
{
	int rate, cores, intense, progs;
	setlocale(LC_ALL, "Russian");
	cout << "Enter Rate:" << endl;
	cin >> rate;
	cout << "Enter Cores:" << endl;
	cin >> cores;
	cout << "Enter Intense:" << endl;
	cin >> intense;
	cout << "Enter count programs:" << endl;
	cin >> progs;
	TProc q(rate, cores, intense, progs);
	q.RunNewJob(progs);
	cout << "Mission Complete" << endl;
	cout << "Performance: " << q.GetRate() << endl;
	cout << "Number of cores: " << q.GetCores() << endl;
	cout << "Count of tacts: " << q.GetTacts() << endl;
	cout << "In total programs: " << q.GetProgs() << endl;
	cout << "Count passes:" << q.GetPass() << endl;
	system("pause");
}
