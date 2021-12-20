#include "menu.hpp"

namespace Chess {
	void startMenu(Window & window) {


	    Chess::Button playBut("images/play.png");
	    playBut.setSize(250, 53);
	    playBut.setPosition(X_WINDOW/2 - playBut.getSize().x/2, 200);


		Chess::Button optionBut("images/option.png");
		optionBut.setSize(231, 53);
		optionBut.setPosition(X_WINDOW/2 - optionBut.getSize().x/2, 290);


		Chess::Button exitBut("images/exit.png");
		exitBut.setSize(149, 53);
		exitBut.setPosition(X_WINDOW/2 - exitBut.getSize().x/2, 380);




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

			//красим кнопка обратно в белый цвет в цикле, если мышь не касается кнопки.
			playBut.getSprite().setColor(sf::Color::White);
			optionBut.getSprite().setColor(sf::Color::White);
			exitBut.getSprite().setColor(sf::Color::White);

			// приравниваем индикатор касания кнопки нулю
			menuNum = 0;

			if (playBut.isTouch(window)) {playBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
			if (optionBut.isTouch(window)) {optionBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
			if (exitBut.isTouch(window)) {exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}

			//if (sf::IntRect(playBut.getPosition().x * window.getRatio().x, playBut.getPosition().y * window.getRatio().y, playBut.getSize().x * window.getRatio().x, playBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { playBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
			//if (sf::IntRect(optionBut.getPosition().x * window.getRatio().x, optionBut.getPosition().y * window.getRatio().y, optionBut.getSize().x * window.getRatio().x, optionBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { optionBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
			//if (sf::IntRect(exitBut.getPosition().x * window.getRatio().x, exitBut.getPosition().y * window.getRatio().y, exitBut.getSize().x * window.getRatio().x, exitBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}


				if (event.type == sf::Event::MouseButtonReleased) {
                	if (menuNum == 1) {
						isMenu = false;
						Chess::selectMode(window);
					}
					if (menuNum == 2) {}
					if (menuNum == 3) {
						window.close(); 
						isMenu = false;
					}  //
            	}

			window.draw(menuBg);
			window.draw(playBut.getSprite());
			window.draw(optionBut.getSprite());
			window.draw(exitBut.getSprite());
			window.display();
		}
	}

	void selectMode(Window& window) {

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
	    singlePlayBut.setPosition(X_WINDOW/2 - singlePlayBut.getSize().x/2, 200);


		Chess::Button onlineGameBut("images/online_game.png");
	    onlineGameBut.setSize(270, 53);
	    onlineGameBut.setPosition(X_WINDOW/2 - onlineGameBut.getSize().x/2, 286);

		Chess::Button backBut("images/backk.png");
	    backBut.setSize(141, 53);
	    backBut.setPosition(X_WINDOW/2 - backBut.getSize().x/2, 372);

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


			if (singlePlayBut.isTouch(window)) {singlePlayBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
			if (onlineGameBut.isTouch(window)) {onlineGameBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
			if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}

			//if (sf::IntRect(singlePlayBut.getPosition().x * window.getRatio().x, singlePlayBut.getPosition().y * window.getRatio().y, singlePlayBut.getSize().x * window.getRatio().x, singlePlayBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { singlePlayBut.getSprite().setColor(sf::Color::Blue); menuNum = 1; }
			//if (sf::IntRect(onlineGameBut.getPosition().x * window.getRatio().x, onlineGameBut.getPosition().y * window.getRatio().y, onlineGameBut.getSize().x * window.getRatio().x, onlineGameBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { onlineGameBut.getSprite().setColor(sf::Color::Blue); menuNum = 2; }
			//if (sf::IntRect(backBut.getPosition().x * window.getRatio().x, backBut.getPosition().y * window.getRatio().y, backBut.getSize().x * window.getRatio().x, backBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { backBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }

			//if (flags.isHost || flags.isClient) { isMenu = false; }

			if (event.type == sf::Event::MouseButtonReleased) {
				if (menuNum == 1) {
					isMenu = false;
					startGame(window, ONE_PLAYER);
				}  // если нажали первую кнопку, то выходим из меню
				if (menuNum == 2) {
					isMenu = false;
					selectH(window);
				}
				if (menuNum == 3) {
					isMenu = false;
					startMenu(window);
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


	void selectH(Window& window) {

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
			createBut.setPosition(X_WINDOW/2 - createBut.getSize().x / 2, 200);

			sf::IpAddress host_ip;
			host_ip.getPublicAddress(sf::seconds(5.3f));
			//host_ip.getLocalAddress();

			// текст для вывода IP
			sf::Font font;//шрифт
			font.loadFromFile("Fonts/font.TTF");
			sf::Text text(" ", font, 25);
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);
			text.setFillColor(sf::Color::White);
			text.setOutlineColor(sf::Color::Black);
			text.setOutlineThickness(3);
			std::string string_host_ip = host_ip.toString();
			text.setString("Your IP address: " + string_host_ip);
			text.setPosition(20, 20);


			Chess::Button joinBut("images/joinGame.png");
			joinBut.setSize(467, 53);
			joinBut.setPosition(X_WINDOW/2 - joinBut.getSize().x / 2, 286);

			Chess::Button backBut("images/backk.png");
			backBut.setSize(141, 53);
			backBut.setPosition(X_WINDOW/2 - backBut.getSize().x / 2, 372);

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


				if (createBut.isTouch(window)) {createBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
				if (joinBut.isTouch(window)) {joinBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
				if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 3;}

				//if (sf::IntRect(createBut.getPosition().x * window.getRatio().x, createBut.getPosition().y * window.getRatio().y, createBut.getSize().x * window.getRatio().x, createBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { createBut.getSprite().setColor(sf::Color::Blue); menuNum = 1; }
				//if (sf::IntRect(joinBut.getPosition().x * window.getRatio().x, joinBut.getPosition().y * window.getRatio().y, joinBut.getSize().x * window.getRatio().x, joinBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { joinBut.getSprite().setColor(sf::Color::Blue); menuNum = 2; }
				//if (sf::IntRect(backBut.getPosition().x * window.getRatio().x, backBut.getPosition().y * window.getRatio().y, backBut.getSize().x * window.getRatio().x, backBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { backBut.getSprite().setColor(sf::Color::Blue); menuNum = 3; }

				if (event.type == sf::Event::MouseButtonReleased) {
					if (menuNum == 1) {
						isMenu = false;
						startGame(window, HOST);
					}  // если нажали первую кнопку, то выходим из меню
					if (menuNum == 2) {
						isMenu = false;
						startGame(window, CLIENT);
					}
					if (menuNum == 3) {
						isMenu = false;
						selectMode(window);
					}  // add implementation of option

				}

				window.draw(menuBg);
				window.draw(createBut.getSprite());
				window.draw(joinBut.getSprite());
				window.draw(backBut.getSprite());
				window.draw(text);
				window.display();

			}
		}

    void startGame(Window& window, GameMode mode) {

		sf::Clock clock;
    	int menuNum = 0;
		bool isGame = true;

		// button exit through class Button
    	Chess::Button exitBut("images/exit.png");
    	exitBut.setSize(X_EXIT, Y_EXIT);
    	exitBut.setPosition(X_WINDOW - 200, Y_WINDOW - 100);
    	// exitBut.getSprite().setPosition(X_WINDOW - 200, Y_WINDOW - 100);

    	// кнопка назад
    	Chess::Button backBut("images/back.png");
    	backBut.setSize(X_BACK, Y_BACK);
    	backBut.setPosition(100, Y_WINDOW - 100);

    	// add board and figure
    	float scale = SCALE_FACTOR;
    	Chess::BoardTexture board_texture("images/boardTru.jpg");
    	Chess::FigureTexture figures_testure;
    	board_texture.setBoardScale(SCALE_FACTOR);

    	sf::Vector2i playSpace;
    	playSpace.x = X_PLAYSPACE;
    	playSpace.y = Y_PLAYSPACE;
    	board_texture.setPlaySpace(playSpace);

    	Chess::Gameplay gameplay;
		gameplay.setSide();
		gameplay.setGameMode(mode);

		gameplay.updateSprites();

		while (isGame) {
        	sf::Vector2i pos = sf::Mouse::getPosition(window);
        	float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
			clock.restart(); //перезагружает время
			time = time/120;


        	sf::Event event;
        	while (window.pollEvent(event)) {
        		if (event.type == sf::Event::Closed) {
        		    isGame = false;
        		}
        		// берем новый размер окна, чтобы можно было задать новую рабочую зону для кнопок
        		if (event.type == sf::Event::Resized) {
					window.getSizeNew();
				}

        		menuNum = 0;
        		exitBut.getSprite().setColor(sf::Color::White);
        		backBut.getSprite().setColor(sf::Color::White);

        		// изначально соотношение размеров окон 1:1, но после ресайза это отношение меняется, и мы по-прежнему можем нажимать на кнопки в зоне их расположения

				if (exitBut.isTouch(window)) {exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
				if (backBut.isTouch(window)) {backBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}

        		//if (sf::IntRect(exitBut.getPosition().x * window.getRatio().x, exitBut.getPosition().y * window.getRatio().y, exitBut.getSize().x * window.getRatio().x, exitBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
        		//if (sf::IntRect(backBut.getPosition().x * window.getRatio().x, backBut.getPosition().y * window.getRatio().y, backBut.getSize().x * window.getRatio().x, backBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { backBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
        		// if (sf::IntRect(pos.x * windowRatio.x, pos.y * windowRatio.y, (float)backSize.x * windowRatio.x, (float)backSize.y * windowRatio.y).contains(sf::Mouse::getPosition(window))) {}

        	    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        	    //     Chess::startMenu(window, flags);
        	    // }
        	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        	        window.close();
        	    }

        		if (event.type == sf::Event::MouseButtonReleased) {
        		    if (menuNum == 1) {
        		        isGame = false;
						window.close();
        		    }
        		    if (menuNum == 2)  {
        		        isGame = false; 
						selectMode(window);
					}
        		}

        		gameplay.play(event, pos); // proveryaet hod
        	}

        	window.clear();
        	window.clear(sf::Color(129, 181, 221));

        	window.draw(board_texture.getSprite());
        	window.draw(exitBut.getSprite());
        	window.draw(backBut.getSprite());

			gameplay.updateSprites();
        	gameplay.drawFigures(window, pos);

        	window.display();

		}  // while(isGame)
    
	}  // strartGame

}  // namespace Chess
