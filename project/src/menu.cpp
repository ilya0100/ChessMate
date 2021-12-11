#include "menu.hpp"
#include <iostream>

void Chess::menu(sf::RenderWindow & window) {
	sf::Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	sf::Vector2u windowSize = window.getSize();
	sf::Vector2u windowSizeNew = window.getSize();
	menuTexture1.loadFromFile("images/play.png");
	menuTexture3.loadFromFile("images/exit.png");
	menuBackground.loadFromFile("images/menu.jpeg");
	sf::Sprite menu1(menuTexture1), menu3(menuTexture3), menuBg(menuBackground);

    // Chess:Button playBut("images/play.png");
    // playBut.setSize(250, 53);
    // playBut.getSprite().setPosition(200, 200);
    // sf::Vector2f playButPos = playBut.getSprite().getPosition();

	bool isMenu = 1;
	int menuNum = 0;

	sf::Vector2u menu1Size;
	menu1Size.x = 250;
	menu1Size.y = 53;
	menu1.setPosition(200, 200);
	sf::Vector2f menu1Pos = menu1.getPosition();

	sf::Vector2u menu3Size;
	menu3Size.x = 149;
	menu3Size.y = 53;
	menu3.setPosition(200, 290);
	sf::Vector2f menu3Pos = menu3.getPosition();


	menuBg.setPosition(0, 0);
	
	sf::Clock clock;
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu) {
		sf::Event event;
 		while (window.pollEvent(event)) {
 			if (event.type == sf::Event::Closed) {
 				window.close();
				isMenu = false;
		 		}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window.close();
					isMenu = false;
			}
			//на будущее
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				rectS.move(0, -1);
				rectPos = rectS.getPosition();
				*/
			if (event.type == sf::Event::Resized) {
				windowSizeNew = window.getSize();
		 	}
 		}

		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 120; //скорость игры
		menu1.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menuNum = 0;
 
		if (sf::IntRect((float)menu1Pos.x * ((float)windowSizeNew.x / (float)windowSize.x), (float)menu1Pos.y * ((float)windowSizeNew.y / (float)windowSize.y), (float)menu1Size.x * ((float)windowSizeNew.x / (float)windowSize.x), (float)menu1Size.y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect((float)menu3Pos.x * ((float)windowSizeNew.x / (float)windowSize.x), (float)menu3Pos.y * ((float)windowSizeNew.y / (float)windowSize.y), (float)menu3Size.x * ((float)windowSizeNew.x / (float)windowSize.x), (float)menu3Size.y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;  // если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3)  { window.close(); isMenu = false; }
 
		}



		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu3);
		window.display();
	}
	////////////////////////////////////////////////////
}
