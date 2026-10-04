/****************************************
* Автор: Сабитов И.И.                   *
* Задание: циклы с пред и постусловием *
* Вариант: 8                            *
*****************************************/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	const double gasConstant = 8.31;

	double temperature;
	double initialVolume;
	double adiabaticIndex;
	double firstStartVolume;
	double firstEndVolume;
	double firstStep;
	double secondEndVolume;
	double secondStep;
	double finalVolume;
	double isothermalWork;
	double adiabaticWork;

	int stepIndex;

	cout << "Enter temperature T (K): ";
	cin >> temperature;
	cout << "Enter initial volume V1 (m^3): ";
	cin >> initialVolume;
	cout << "Enter adiabatic index n: ";
	cin >> adiabaticIndex;
	cout << "Enter first section start V2 (m^3): ";
	cin >> firstStartVolume;
	cout << "Enter first section end V2 (m^3): ";
	cin >> firstEndVolume;
	cout << "Enter first section step (m^3): ";
	cin >> firstStep;
	cout << "Enter second section end V2 (m^3): ";
	cin >> secondEndVolume;
	cout << "Enter second section step (m^3): ";
	cin >> secondStep;

	cout << "V2 (m^3)\tA1 (kJ)\tA2 (kJ)";

	//First section: while
	stepIndex = 0;
	finalVolume = firstStartVolume;
	while (finalVolume <= firstEndVolume) {
		isothermalWork = gasConstant * temperature * log(finalVolume / initialVolume);
		adiabaticWork = gasConstant * temperature / (adiabaticIndex - 1.0) *
			(1.0 - pow(initialVolume / finalVolume, adiabaticIndex - 1.0));
		cout << "\n" << finalVolume << "\t\t" << isothermalWork << "\t" << adiabaticWork; 
		++stepIndex;
		finalVolume = firstStartVolume + stepIndex * firstStep;
	}

	//Second section: do-while
	stepIndex = 1;
	finalVolume = firstEndVolume + stepIndex * secondStep;
	do {
		isothermalWork = gasConstant * temperature * log(finalVolume / initialVolume);
		adiabaticWork = gasConstant * temperature / (adiabaticIndex - 1.0) *
			(1.0 - pow(initialVolume / finalVolume, adiabaticIndex - 1.0));
		cout << "\n" << finalVolume << "\t\t" << isothermalWork << "\t" << adiabaticWork;
		++stepIndex;
		finalVolume = firstEndVolume + stepIndex * secondStep;
	} while (finalVolume <= secondEndVolume);

	return 0;
}