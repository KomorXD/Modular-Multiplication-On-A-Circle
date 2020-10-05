#include <iostream>

#include "App.hpp"

App::App(unsigned uWindowWidth, unsigned uWindowHeight, unsigned uPointsNum, unsigned uMult)
	: m_Window({ uWindowWidth, uWindowHeight }, "Circle", sf::Style::Close | sf::Style::Titlebar)
	, m_Circle(380.0f, { uWindowWidth / 2.0f, uWindowHeight / 2.0f }) {

	m_Circle.Update(uPointsNum, uMult);
}

App::~App() {
	m_Window.close();
}

void App::Run() {
	sf::Event ev;

	while (m_Window.isOpen()) {
		while (m_Window.pollEvent(ev)) {
			switch (ev.type) {
				case sf::Event::Closed:
					m_Window.close();

					return;
					break;

				case sf::Event::KeyPressed:
					if (ev.key.code == sf::Keyboard::Space) {
						unsigned uPointsNum, uMult;

						std::cout << "\n(If you wish to change later, press Space)" << std::endl;
						std::cout << "Enter desired number of points: ";
						std::cin >> uPointsNum;

						std::cout << "Enter desired multiplier: ";
						std::cin >> uMult;

						m_Circle.Update(uPointsNum, uMult);
					}
					else if (ev.key.code == sf::Keyboard::Escape) {
						m_Window.close();

						return;
						break;
					}

					break;
				}
		}

		m_Window.clear(sf::Color(100, 100, 100));

		m_Circle.Render(m_Window);

		m_Window.display();
	}
}
