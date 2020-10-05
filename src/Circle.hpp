#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Circle {
	private:
		struct Point {
			sf::CircleShape shape;
			unsigned		uOrder;
		};

		std::vector<Point> m_Points;
		sf::CircleShape	   m_CircleCircumstance;
		
		std::vector<sf::VertexArray> m_VertexArrays;
		
		unsigned m_uNumberOfPoints;
		unsigned m_uMultiplier;

	private:
		sf::Vector2f PositionAtValue(int iValue);

	public:
		Circle(float fRadius, const sf::Vector2f& center);

		void Update(unsigned uNewPoints, unsigned uNewMult);

		void Render(sf::RenderTarget& renderer);
};