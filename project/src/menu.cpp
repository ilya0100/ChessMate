#include "menu.hpp"
#include <iostream>

namespace Chess {
	void startMenu(sf::RenderWindow & window) {
		// sf::Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
		sf::Vector2u windowSize = window.getSize();
		sf::Vector2u windowSizeNew = window.getSize();
		// menuTexture1.loadFromFile("images/play.png");
		// menuTexture3.loadFromFile("images/exit.png");
		// menuBackground.loadFromFile("images/menu.png");
		// sf::Sprite menu1(menuTexture1), menu3(menuTexture3), menuBg(menuBackground);

	    Chess::Button playBut("images/play.png");
	    playBut.setSize(X_PLAY, Y_PLAY);
	    // playBut.getSprite().setPosition(200, 200);
		playBut.getSprite().setPosition(X_WINDOW / 2 - X_PLAY / 2, Y_WINDOW / 5);
	    sf::Vector2f playButPos = playBut.getSprite().getPosition();

		Chess::Button optionBut("images/option.png");
		optionBut.setSize(231, 53);
		optionBut.getSprite().setPosition(200, 290);
		sf::Vector2f OptionButPos = optionBut.getSprite().getPosition();

		Chess::Button exitBut("images/exit.png");
		exitBut.setSize(149, 53);
		exitBut.getSprite().setPosition(200, 380);
		sf::Vector2f exitButPos = exitBut.getSprite().getPosition();

		// Chess::Button BgBut("images/exit.png");
		// BgBut.getSprite().setPosition(200, 290);
		// sf::Vector2f BgButPos = BgBut.getSprite().getPosition();

		sf::Texture menuBackground;
		menuBackground.loadFromFile("images/menu.png");
		sf::Sprite menuBg(menuBackground);
		menuBg.setScale(X_WINDOW / X_MENU, Y_WINDOW / Y_MENU);

		bool isMenu = 1;
		int menuNum = 0;

		// sf::Vector2u menu1Size;
		// menu1Size.x = 250;
		// menu1Size.y = 53;
		// menu1.setPosition(200, 200);
		// sf::Vector2f menu1Pos = menu1.getPosition();

		// sf::Vector2u menu3Size;
		// menu3Size.x = 149;
		// menu3Size.y = 53;
		// menu3.setPosition(200, 290);
		// sf::Vector2f menu3Pos = menu3.getPosition();

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
			playBut.getSprite().setColor(sf::Color::White);
			optionBut.getSprite().setColor(sf::Color::White);
			exitBut.getSprite().setColor(sf::Color::White);
			menuNum = 0;
	
			if (sf::IntRect((float)playBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)playBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)playBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)playBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { playBut.getSprite().setColor(sf::Color::Blue); menuNum = 1; }
			if (sf::IntRect((float)exitBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)exitBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)exitBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)exitBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { exitBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }
			if (sf::IntRect((float)optionBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)optionBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)optionBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)optionBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { optionBut.getSprite().setColor(sf::Color::Blue); menuNum = 4; }

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (menuNum == 1) isMenu = false;  // если нажали первую кнопку, то выходим из меню 
				if (menuNum == 3) { window.close(); isMenu = false; }
				if (menuNum == 4) {}  // add implementation of option
	
			}

			window.draw(menuBg);
			window.draw(playBut.getSprite());
			window.draw(optionBut.getSprite());
			window.draw(exitBut.getSprite());
			window.display();
		}
	}
	////////////////////////////////////////////////////

	// Buttons from menu
    Button::Button(const std::string filename) {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
    }

    void Button::setButton(const std::string filename) {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
    }

    void Button::setSize(size_t x, size_t y) {
        size.x = x;
        size.y = y;
    }

 	void Button::setPosButton(float x, float y) {
		sprite.setPosition(x, y);
		pos.x = x;
    	pos.y = y;
    }

    sf::Sprite& Button::getSprite() { return sprite; }
    sf::Vector2u Button::getSize() { return size; }
    sf::Vector2f Button::getPosButton() { return pos; }

	void selectMode(Window& window) {

		sf::Texture menuBackground;
		menuBackground.loadFromFile("images/menu.png");
		sf::Sprite menuBg(menuBackground);


		Chess::Button singlePlayBut("images/singlePlay.png");
	    singlePlayBut.setSize(561, 53);
	    singlePlayBut.setPosButton(169.5, 200);

		/*
		Chess::Button online_game("images/.png");
	    playBut.setSize(250, 53);
	    playBut.getSprite().setPosition(200, 200);
	    sf::Vector2f playButPos = playBut.getSprite().getPosition();

		Chess::Button optionBut("images/option.png");
		optionBut.setSize(231, 53);
		optionBut.getSprite().setPosition(200, 290);
		sf::Vector2f OptionButPos = optionBut.getSprite().getPosition();
		*/


	}
}




	void startMenuN(Window & window) {

		//  Загружаем фон
		sf::Texture menuBackground;
		menuBackground.loadFromFile("images/menu.png");
		sf::Sprite menuBg(menuBackground);
		menuBg.setPosition(0,0);

		//
		bool isMenu = 1;  // пока меню открыто
		int menuNum = 0;  // для номеров кнопок

		//  кнопки

		Chess::Button playBut("images/play.png");
	    playBut.setSize(250, 53);
	    playBut.setPosButton(200, 200);

		Chess::Button optionBut("images/option.png");
	    playBut.setSize(231, 53);
	    playBut.setPosButton(200, 290);

		Chess::Button exitBut("images/exit.png");
	    playBut.setSize(149, 53);
	    playBut.setPosButton(200, 380);

		sf::Clock clock;  // время

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
				if (event.type == sf::Event::Resized) {
					window.getSizeNew();
			 	}
			}

			float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
			clock.restart(); //перезагружает время
			time = time / 120; //скорость игры
			playBut.getSprite().setColor(sf::Color::White);
			optionBut.getSprite().setColor(sf::Color::White);
			exitBut.getSprite().setColor(sf::Color::White);
			menuNum = 0;

			//if (sf::IntRect((float)playBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)playBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)playBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)playBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { playBut.getSprite().setColor(sf::Color::Blue); menuNum = 1; }
			//if (sf::IntRect((float)exitBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)exitBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)exitBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)exitBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { exitBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }
			//if (sf::IntRect((float)optionBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)optionBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)optionBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)optionBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { optionBut.getSprite().setColor(sf::Color::Blue); menuNum = 4; }


		}



/*
		sf::Vector2u windowSize = window.getSize();
		sf::Vector2u windowSizeNew = window.getSize();


	    Chess::Button playBut("images/play.png");
	    playBut.setSize(250, 53);
	    playBut.getSprite().setPosition(200, 200);
	    sf::Vector2f playButPos = playBut.getSprite().getPosition();

		Chess::Button optionBut("images/option.png");
		optionBut.setSize(231, 53);
		optionBut.getSprite().setPosition(200, 290);
		sf::Vector2f OptionButPos = optionBut.getSprite().getPosition();

		Chess::Button exitBut("images/exit.png");
		exitBut.setSize(149, 53);
		exitBut.getSprite().setPosition(200, 380);
		sf::Vector2f exitButPos = exitBut.getSprite().getPosition();



		sf::Texture menuBackground;
		menuBackground.loadFromFile("images/menu.png");
		sf::Sprite menuBg(menuBackground);

		bool isMenu = 1;
		int menuNum = 0;



		menuBg.setPosition(0, 0);

		sf::Clock clock;

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

				if (event.type == sf::Event::Resized) {
					windowSizeNew = window.getSize();
			 	}
	 		}

			float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
			clock.restart(); //перезагружает время
			time = time / 120; //скорость игры
			playBut.getSprite().setColor(sf::Color::White);
			optionBut.getSprite().setColor(sf::Color::White);
			exitBut.getSprite().setColor(sf::Color::White);
			menuNum = 0;

			if (sf::IntRect((float)playBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)playBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)playBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)playBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { playBut.getSprite().setColor(sf::Color::Blue); menuNum = 1; }
			if (sf::IntRect((float)exitBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)exitBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)exitBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)exitBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { exitBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }
			if (sf::IntRect((float)optionBut.getSprite().getPosition().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)optionBut.getSprite().getPosition().y * ((float)windowSizeNew.y / (float)windowSize.y), (float)optionBut.getSize().x * ((float)windowSizeNew.x / (float)windowSize.x), (float)optionBut.getSize().y * ((float)windowSizeNew.y / (float)windowSize.y)).contains(sf::Mouse::getPosition(window))) { optionBut.getSprite().setColor(sf::Color::Blue); menuNum = 4; }

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (menuNum == 1) isMenu = false;  // если нажали первую кнопку, то выходим из меню
				if (menuNum == 3) { window.close(); isMenu = false; }
				if (menuNum == 4) {}  // add implementation of option

			}

			window.draw(menuBg);
			window.draw(playBut.getSprite());
			window.draw(optionBut.getSprite());
			window.draw(exitBut.getSprite());
			window.display();
		}
		*/
	}
