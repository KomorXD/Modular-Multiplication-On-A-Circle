#include <cmath>

#include "Circle.hpp"

static const float PI = 3.14159265358979f;

sf::Vector2f Circle::PositionAtValue(int iValue) {
	for (Point& point : m_Points) {
		if (point.uOrder == iValue)
			return point.shape.getPosition();
	}

	return { -1.0f, -1.0f };
}

Circle::Circle(float fRadius, const sf::Vector2f& centerPos)
	: m_CircleCircumstance(fRadius, 100U), m_uNumberOfPoints(10U), m_uMultiplier(2U) {

	m_CircleCircumstance.setFillColor(sf::Color(100, 100, 100));
	m_CircleCircumstance.setOutlineColor(sf::Color::Red);
	m_CircleCircumstance.setOutlineThickness(2.0f);
	m_CircleCircumstance.setOrigin(fRadius, fRadius);
	m_CircleCircumstance.setPosition(centerPos);
}

void Circle::Update(unsigned uNewPoints, unsigned uNewMult) {
	m_uNumberOfPoints = uNewPoints;
	m_uMultiplier	  = uNewMult;

	m_Points.clear();
	m_VertexArrays.clear();

	for (size_t i = 0; i < m_uNumberOfPoints; i++) {
		sf::CircleShape prototype(3.0f);
		
		prototype.setOrigin({ 3.0f, 3.0f });
		prototype.setFillColor(sf::Color::Blue);
		prototype.setPosition({ std::cos(i * (2 * PI / m_uNumberOfPoints) - PI / 2.0f) * m_CircleCircumstance.getRadius() + m_CircleCircumstance.getPosition().x,
								std::sin(i * (2 * PI / m_uNumberOfPoints) - PI / 2.0f) * m_CircleCircumstance.getRadius() + m_CircleCircumstance.getPosition().y });

		m_Points.push_back({ prototype, i });
	}

	m_VertexArrays.reserve(m_uNumberOfPoints);

	for (size_t i = 0; i < m_uNumberOfPoints; i++) {
		m_VertexArrays.push_back(sf::VertexArray(sf::LinesStrip, 2));
		m_VertexArrays[i][0] = sf::Vertex(PositionAtValue(i));

		int iNextVal = i * m_uMultiplier;

		m_VertexArrays[i][1] = sf::Vertex(PositionAtValue(iNextVal % m_uNumberOfPoints));
		m_VertexArrays[i][0].color = m_VertexArrays[i][1].color = sf::Color::Green;
	}
}

void Circle::Render(sf::RenderTarget& renderer) {
	renderer.draw(m_CircleCircumstance);

	for (Point& point : m_Points)
		renderer.draw(point.shape);

	for (sf::VertexArray& vArr : m_VertexArrays)
		renderer.draw(vArr);
}
