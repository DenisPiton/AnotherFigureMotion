﻿#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
void circle(Shape& shape) {
	shape.setPosition(shape.getPosition().x + 4, shape.getPosition().y + 4);
}
void circleMgnum(CircleShape& shape, CircleShape& shape2, RenderWindow& window) {
	if (shape.getPosition().x <= 0) {
		shape2.setPosition((float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x < (1 - (float)window.getSize().x)) {
			shape.setPosition(0, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y <= 0) {
		shape2.setPosition(shape2.getPosition().x, (float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y < (1 - (float)window.getSize().y)) {
			shape.setPosition(shape.getPosition().x, 0);
		}
	}
	if (shape.getPosition().x + shape.getRadius() * 2 >= window.getSize().x) {
		shape2.setPosition(-(float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x + shape.getRadius() * 2 - (float)window.getSize().x > window.getSize().x) {
			shape.setPosition(-shape.getRadius() * 2, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y + shape.getRadius() * 2 >= window.getSize().y) {
		shape2.setPosition(shape2.getPosition().x, -(float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y + shape.getRadius() * 2 - (float)window.getSize().x > window.getSize().y) {
			shape.setPosition(shape.getPosition().x, -shape.getRadius() * 2);
		}
	}
}

void AnotherShapeMgnum(RectangleShape& shape, RectangleShape& shape2, RenderWindow& window) {
	if (shape.getPosition().x <= 0) {
		shape2.setPosition((float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x < (1 - (float)window.getSize().x)) {
			shape.setPosition(0, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y <= 0) {
		shape2.setPosition(shape2.getPosition().x, (float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y < (1 - (float)window.getSize().y)) {
			shape.setPosition(shape.getPosition().x, 0);
		}
	}
	if (shape.getPosition().x + shape.getSize().x >= window.getSize().x) {
		shape2.setPosition(-(float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x + shape.getSize().x - (float)window.getSize().x > window.getSize().x) {
			shape.setPosition(-shape.getSize().x, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y + shape.getSize().y >= window.getSize().y) {
		shape2.setPosition(shape2.getPosition().x, -(float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y + shape.getSize().y - (float)window.getSize().x > window.getSize().y) {
			shape.setPosition(shape.getPosition().x, -shape.getSize().y);
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Lesson 2. kychka-pc.ru");
	window.setFramerateLimit(30);
	sf::CircleShape shape(100.f);

	//shape.setFillColor(sf::Color::Red);
	 
	Texture textureFont;
	textureFont.loadFromFile("res/font.jpg");
	RectangleShape recShape(Vector2f(window.getSize()));
	recShape.setTexture(&textureFont);
	cout << recShape.getSize().x << " " << recShape.getSize().y;

	Texture textureCircle;
	textureCircle.loadFromFile("res/circle.jpg");
	shape.setTexture(&textureCircle);
	CircleShape shape2;
	RectangleShape box1(sf::Vector2f(100, 100));
	RectangleShape box2;


	box1.setFillColor(sf::Color(100, 100, 0));
	box2 = box1;
	box2.setPosition((Vector2f)window.getSize());
	shape2 = shape;
	shape2.setPosition((Vector2f)window.getSize());
	int x = 0, y = 0;
	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		circleMgnum(shape, shape2, window);
		AnotherShapeMgnum(box1, box2, window);
		circle(box1);
		circle(shape);
		window.clear();
		//window.draw(recShape);
		//window.draw(shape);
		/*window.draw(shape2);*/
		window.draw(box1);
		window.draw(box2);
		window.display();
	}

	return 0;
}