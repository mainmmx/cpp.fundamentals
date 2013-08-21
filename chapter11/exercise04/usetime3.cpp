#include <iostream>
#include "mytime3.h"

int main()
{
	using std::cout;
	using std::endl;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida<<"; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida* 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
/**/
	cout << "60(min) + Aida: " << 60 + aida << endl;
	cout << "60(min) - Aida: " << 60 - aida << endl;
	cout << "12(min) + Tosca: " << 12 + tosca << endl;
	cout << "48(min) - Tosca: " << 48 - tosca << endl;
/**/
	return 0;
}
