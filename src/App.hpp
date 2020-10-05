#pragma once

#include <SFML/Graphics.hpp>

#include "Circle.hpp"

class App {
	private:
		sf::RenderWindow m_Window;
		Circle			 m_Circle;

	public:
		App(unsigned uWindowWidth, unsigned uWindowHeight, unsigned uPointsNum, unsigned uMult);
		~App();

		void Run();
};