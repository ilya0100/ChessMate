#include "utils.hpp"

void menu(sf::RenderWindow & window) {
	sf::Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/play.png");
	menuTexture3.loadFromFile("images/exit.png");
	menuBackground.loadFromFile("images/menu.jpeg");
	sf::Sprite menu1(menuTexture1), menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(120, 200);
	menu3.setPosition(120, 290);
	menuBg.setPosition(0, 0);
	
	sf::Clock clock;
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{	
		sf::Event event;
 		while (window.pollEvent(event)) {
 			if (event.type == sf::Event::Closed) {
 				window.close();
				isMenu = false;
		 		}
 		}
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time/120; //скорость игры
		menu1.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menuNum = 0;
		//window.clear(sf::Color(129, 181, 221));
 
		if (sf::IntRect(120, 200, 117, 23).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect(120, 290, 61, 23).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }
 
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3)  { window.close(); isMenu = false; }
 
		}
 
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu3);
		
		window.display();
	}
	////////////////////////////////////////////////////
}

