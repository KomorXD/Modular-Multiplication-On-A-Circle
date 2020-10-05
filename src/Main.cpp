#include <iostream>

#include "App.hpp"

int main() {
	unsigned uPointsNum, uMult;

	std::cout << "(If you wish to change later, press Space)" << std::endl;
	std::cout << "Enter desired number of points: ";
	std::cin >> uPointsNum;

	std::cout << "Enter desired multiplier: ";
	std::cin >> uMult;

	App app(1200U, 800U, uPointsNum, uMult);

	app.Run();

	return 0;
}