#include "menu.hpp"

namespace Chess {
	void startMenu(Window & window, Flags& flags) {


	    Chess::Button playBut("images/play.png");
	    playBut.setSize(250, 53);
	    playBut.setPosButton(X_WINDOW/2 - playBut.getSize().x/2, 200);


		Chess::Button optionBut("images/option.png");
		optionBut.setSize(231, 53);
		optionBut.setPosButton(X_WINDOW/2 - optionBut.getSize().x/2, 290);


		Chess::Button exitBut("images/exit.png");
		exitBut.setSize(149, 53);
		exitBut.setPosButton(X_WINDOW/2 - exitBut.getSize().x/2, 380);




		sf::Texture menuBackground;
		menuBackground.loadFromFile("images/menu.png");
		sf::Sprite menuBg(menuBackground);
		menuBg.setScale(X_WINDOW / 1333, Y_WINDOW / 751);

		bool isMenu = 1;
		int menuNum = 0;

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

			if (sf::IntRect(playBut.getPosButton().x * window.getRatio().x, playBut.getPosButton().y * window.getRatio().y, playBut.getSize().x * window.getRatio().x, playBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { playBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
			if (sf::IntRect(optionBut.getPosButton().x * window.getRatio().x, optionBut.getPosButton().y * window.getRatio().y, optionBut.getSize().x * window.getRatio().x, optionBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { optionBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
			if (sf::IntRect(exitBut.getPosButton().x * window.getRatio().x, exitBut.getPosButton().y * window.getRatio().y, exitBut.getSize().x * window.getRatio().x, exitBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}


				if (event.type == sf::Event::MouseButtonReleased) {
                	if (menuNum == 1) {
						isMenu = false;
						Chess::selectMode(window, flags);
					}
					if (menuNum == 2) {
					}
					if (menuNum == 3) { window.close(); isMenu = false;
					}  //
            	}




			if (flags.isClient || flags.isHost || flags.isOnePlayerMode) { isMenu = false; }

			window.draw(menuBg);
			window.draw(playBut.getSprite());
			window.draw(optionBut.getSprite());
			window.draw(exitBut.getSprite());
			window.display();
		}
	}
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
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

    void Button::setSize(float x, float y) {
        size.x = x;
        size.y = y;
    }

 	void Button::setPosButton(float x, float y) {
		sprite.setPosition(x, y);
		pos.x = x;
    	pos.y = y;
    }

    sf::Sprite& Button::getSprite() { return sprite; }
    sf::Vector2f Button::getSize() { return size; }
    sf::Vector2f Button::getPosButton() { return pos; }

	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////


	void selectMode(Window& window, Flags& flags) {

		//  Загружаем фон
		sf::Texture menuBackground;
		menuBackground.loadFromFile("images/menu.png");
		sf::Sprite menuBg(menuBackground);
		menuBg.setPosition(0, 0);

		//
		bool isMenu = 1;  // пока меню открыто
		int menuNum = 0;  // для номеров кнопок

		//  кнопки

		Chess::Button singlePlayBut("images/singlePlay.png");
	    singlePlayBut.setSize(561, 53);
	    singlePlayBut.setPosButton(X_WINDOW/2 - singlePlayBut.getSize().x/2, 200);


		Chess::Button onlineGameBut("images/online_game.png");
	    onlineGameBut.setSize(270, 53);
	    onlineGameBut.setPosButton(X_WINDOW/2 - onlineGameBut.getSize().x/2, 286);

		Chess::Button backBut("images/backk.png");
	    backBut.setSize(141, 53);
	    backBut.setPosButton(X_WINDOW/2 - backBut.getSize().x/2, 372);

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
					window.getSizeNew();
			 	}
			}

			float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
			clock.restart(); //перезагружает время
			time = time / 120; //скорость игры
			singlePlayBut.getSprite().setColor(sf::Color::White);
			onlineGameBut.getSprite().setColor(sf::Color::White);
			backBut.getSprite().setColor(sf::Color::White);
			menuNum = 0;

			if (sf::IntRect(singlePlayBut.getPosButton().x * window.getRatio().x, singlePlayBut.getPosButton().y * window.getRatio().y, singlePlayBut.getSize().x * window.getRatio().x, singlePlayBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { singlePlayBut.getSprite().setColor(sf::Color::Blue); menuNum = 1; }
			if (sf::IntRect(onlineGameBut.getPosButton().x * window.getRatio().x, onlineGameBut.getPosButton().y * window.getRatio().y, onlineGameBut.getSize().x * window.getRatio().x, onlineGameBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { onlineGameBut.getSprite().setColor(sf::Color::Blue); menuNum = 2; }
			if (sf::IntRect(backBut.getPosButton().x * window.getRatio().x, backBut.getPosButton().y * window.getRatio().y, backBut.getSize().x * window.getRatio().x, backBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { backBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }

			//if (flags.isHost || flags.isClient) { isMenu = false; }

			if (event.type == sf::Event::MouseButtonReleased) {
				if (menuNum == 1) {
					isMenu = false;
					flags.isOnePlayerMode = true;
				}  // если нажали первую кнопку, то выходим из меню
				if (menuNum == 2) {
					isMenu = false;
					flags.isOnlineGame = true;
					Chess::selectH(window, flags);
				}
				if (menuNum == 3) {
					isMenu = false;
					Chess::startMenu(window, flags);
					// Chess::startMenu(window);
				}  // add implementation of option

			}

			window.draw(menuBg);
			window.draw(singlePlayBut.getSprite());
			window.draw(onlineGameBut.getSprite());
			window.draw(backBut.getSprite());
			window.display();

		}


	}


	void selectH(Window& window, Flags& flags) {

			//  Загружаем фон
			sf::Texture menuBackground;
			menuBackground.loadFromFile("images/menu.png");
			sf::Sprite menuBg(menuBackground);
			menuBg.setPosition(0, 0);

			//
			bool isMenu = 1;  // пока меню открыто
			int menuNum = 0;  // для номеров кнопок

			//  кнопки

			Chess::Button createBut("images/createGame.png");
			createBut.setSize(268, 53);
			createBut.setPosButton(X_WINDOW/2 - createBut.getSize().x / 2, 200);


			Chess::Button joinBut("images/joinGame.png");
			joinBut.setSize(467, 53);
			joinBut.setPosButton(X_WINDOW/2 - joinBut.getSize().x / 2, 286);

			Chess::Button backBut("images/backk.png");
			backBut.setSize(141, 53);
			backBut.setPosButton(X_WINDOW/2 - backBut.getSize().x / 2, 372);

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
						window.getSizeNew();
					}
				}

				float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
				clock.restart(); //перезагружает время
				time = time / 120; //скорость игры
				createBut.getSprite().setColor(sf::Color::White);
				joinBut.getSprite().setColor(sf::Color::White);
				backBut.getSprite().setColor(sf::Color::White);
				menuNum = 0;

				if (sf::IntRect(createBut.getPosButton().x * window.getRatio().x, createBut.getPosButton().y * window.getRatio().y, createBut.getSize().x * window.getRatio().x, createBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { createBut.getSprite().setColor(sf::Color::Blue); menuNum = 1; }
				if (sf::IntRect(joinBut.getPosButton().x * window.getRatio().x, joinBut.getPosButton().y * window.getRatio().y, joinBut.getSize().x * window.getRatio().x, joinBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { joinBut.getSprite().setColor(sf::Color::Blue); menuNum = 2; }
				if (sf::IntRect(backBut.getPosButton().x * window.getRatio().x, backBut.getPosButton().y * window.getRatio().y, backBut.getSize().x * window.getRatio().x, backBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { backBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }

				if (event.type == sf::Event::MouseButtonReleased) {
					if (menuNum == 1) {
						isMenu = false;
						flags.isHost = true;
					}  // если нажали первую кнопку, то выходим из меню
					if (menuNum == 2) {
						isMenu = false;
						flags.isClient = true;
					}
					if (menuNum == 3) {
						isMenu = false;
						Chess::selectMode(window, flags);
					}  // add implementation of option

				}

				window.draw(menuBg);
				window.draw(createBut.getSprite());
				window.draw(joinBut.getSprite());
				window.draw(backBut.getSprite());
				window.display();

			}
		}
}


