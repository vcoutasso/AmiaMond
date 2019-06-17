#include "menu.hpp"

Jogo::~Jogo() {
	sound.stop();
	buffer.~SoundBuffer();
	sound.~Sound();

	//music.stop();
	//music.~Music();

	window.~RenderWindow();
}

Jogo::Jogo() {
}

int Jogo::openInstructions() {
	int width = window.getSize().x;
	int height = window.getSize().y;

	int quit = 0;
	float deltaTime = 0;
	bool atualizaTela = true;

	sf::RectangleShape background(sf::Vector2f(1920.0f, 1080.0f));
	sf::Texture space;
	
	space.loadFromFile("bin/bg_inst.png");
	background.setTexture(&space);

	Animation animation(&space, sf::Vector2u(1, 15), 0.3f);


	Option exit(0, 0, 40, "VOLTAR PARA O MENU", "bin/Pixelada.ttf");
	exit.text.setPosition(width - (exit.text.getGlobalBounds().width) - 14, height - 65);
	Option title(160, 30, 40, "COMO JOGAR:", "bin/Pixelada.ttf");

	title.text.setStyle(sf::Text::Bold | sf::Text::Italic);

	sf::Clock clock;

	while (!quit) {

		sf::Event event;

		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:
				quit = -1;
				break;

			case sf::Event::MouseMoved:		//Caso aperte no Botão Sair
				if (exit.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					exit.setHovering(true);
					exit.text.setFillColor(HOVER_COLOR);
				}
				else {
					exit.setHovering(false); //Para quando estiver fora voltar
					exit.text.setFillColor(BUTTON_COLOR);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (exit.getHovering()) {
					quit = 1;
				}
				break;

			default:
				break;
			}
		}

			if (clock.getElapsedTime().asSeconds() <= 1 / FPS) {
				animation.updateY(0, deltaTime);
				background.setTextureRect(animation.uvRect);
				window.draw(background);
				window.draw(exit.text);
				window.draw(title.text);
				sf::sleep(sf::seconds((1 / FPS) - clock.getElapsedTime().asSeconds()));

				atualizaTela = true;
			}
			
			if (atualizaTela) {
				window.display();

				deltaTime = clock.restart().asSeconds();
				atualizaTela = false;
			}
			
		}

	// Libera recursos e retorna
	//exit.~Option();
	//title.~Option();

	space.~Texture();

	return quit;
}



//TODO: Abrir funções a partir das opções do usuário
//Implemetando a Função Jogar contendo todas as opções de modo de jogo e quantidade de jogadores
int Jogo::openJogar(Animation& animation, sf::RectangleShape& background) {
	int height = window.getSize().y;

	int quit = 0;
	bool atualizaTela = true;

	Option modoJogo(0, 0, 40, "MODO DE JOGO", "bin/Pixelada.ttf");
	modoJogo.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 4 * height / 15 + 30);
	modoJogo.text.setFillColor(sf::Color::Yellow);

	Option novoJogo(0, 0, 40, "* SELECIONE O ESTILO DE JOGO:", "bin/Pixelada.ttf");
	novoJogo.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 10);
	novoJogo.text.setStyle(sf::Text::Bold | sf::Text::Italic); 

	Option modoJogoCorrida(0, 0, 40, "CORRIDA", "bin/Pixelada.ttf");
	modoJogoCorrida.text.setPosition(450, 4 * height / 15 + 30);

	Option exit(0, 0, 40, "VOLTAR PARA O MENU", "bin/Pixelada.ttf");
	exit.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, height - 65);

	Option numJogadores(0, 0, 40, "NM. DE JOGADORES", "bin/Pixelada.ttf");
	numJogadores.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 8 * height / 15 + 30);
	numJogadores.text.setFillColor(sf::Color::Yellow);

	Option doisJogadores(460 , 8 * height / 15 + 30, 40, "2", "bin/Pixelada.ttf");
	Option tresJogadores(450 + 310, 8 * height / 15 + 30, 40, "3", "bin/Pixelada.ttf");
	Option quatroJogadores(450 + 620, 8 * height / 15 + 30, 40, "4", "bin/Pixelada.ttf");

	Option iniciar(1100, height - 65, 40, "INICIAR!", "bin/Pixelada.ttf");

	sf::Clock clock;
	float deltaTime = 0;

	while (!quit) {

		sf::Event event;

		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:
				quit = -1;
				break;

			case sf::Event::MouseMoved:

				if (exit.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					exit.setHovering(true);
					exit.text.setFillColor(HOVER_COLOR);
				}
				else if (iniciar.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					iniciar.setHovering(true);
					iniciar.text.setFillColor(HOVER_COLOR);
				}
				else if (modoJogoCorrida.isHovering(event.mouseMove.x, event.mouseMove.y) && !modoJogoCorrida.getSelected()) {
					modoJogoCorrida.setHovering(true);
					if (!modoJogoCorrida.getSelected()) modoJogoCorrida.text.setFillColor(HOVER_COLOR);
				}
				else if (doisJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					doisJogadores.setHovering(true);
					if (!doisJogadores.getSelected()) doisJogadores.text.setFillColor(HOVER_COLOR);
				}
				else if (tresJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					tresJogadores.setHovering(true);
					if (!tresJogadores.getSelected()) tresJogadores.text.setFillColor(HOVER_COLOR);
				}
				else if (quatroJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					quatroJogadores.setHovering(true);
					if (!quatroJogadores.getSelected()) quatroJogadores.text.setFillColor(HOVER_COLOR);
				}
				else { // Se o mouse não estiver sobre nenhuma opção, desmarca todas
					exit.setHovering(false);
					iniciar.setHovering(false);
					modoJogoCorrida.setHovering(false);
					doisJogadores.setHovering(false);
					tresJogadores.setHovering(false);
					quatroJogadores.setHovering(false);

					exit.text.setFillColor(BUTTON_COLOR); 
					iniciar.text.setFillColor(BUTTON_COLOR); 

					if (!modoJogoCorrida.getSelected()) modoJogoCorrida.text.setFillColor(BUTTON_COLOR); 
					if (!doisJogadores.getSelected()) doisJogadores.text.setFillColor(BUTTON_COLOR);
					if (!tresJogadores.getSelected()) tresJogadores.text.setFillColor(BUTTON_COLOR);
					if (!quatroJogadores.getSelected()) quatroJogadores.text.setFillColor(BUTTON_COLOR);
				}
				
				break;

			case sf::Event::MouseButtonPressed:
				if (exit.getHovering()) {
					quit = 1;
				}


				if ((doisJogadores.getHovering() || tresJogadores.getHovering() || quatroJogadores.getHovering())) {
					doisJogadores.text.setFillColor(BUTTON_COLOR);
					tresJogadores.text.setFillColor(BUTTON_COLOR);
					quatroJogadores.text.setFillColor(BUTTON_COLOR);

					doisJogadores.setSelected(false);
					tresJogadores.setSelected(false);
					quatroJogadores.setSelected(false);
				}

				if (modoJogoCorrida.getHovering()) {
					modoJogoCorrida.setSelected(true);
					modoJogoCorrida.text.setFillColor(sf::Color::Black);
				}

				if (doisJogadores.getHovering()) {
					doisJogadores.setSelected(true);
					doisJogadores.text.setFillColor(sf::Color::Black);
				}
				else if (tresJogadores.getHovering()) {
					tresJogadores.setSelected(true);
					tresJogadores.text.setFillColor(sf::Color::Black);
				}
				else if (quatroJogadores.getHovering()) {
					quatroJogadores.setSelected(true);
					quatroJogadores.text.setFillColor(sf::Color::Black);
				}

				if (iniciar.getHovering()) {
					// So inicia o jogo se estiver com todas as opções pertinentes selecionadas
					if ((doisJogadores.getSelected() || tresJogadores.getSelected() || quatroJogadores.getSelected()) && (modoJogoCorrida.getSelected())) {
						int n = 2;

						if (tresJogadores.getHovering())
							n = 3;
						else if (quatroJogadores.getHovering())
							n = 4;

						if (playCorrida(n) == -1)
							quit = -1;
					}
				}
				break;

			default:
				break;
			}
		}

		if (clock.getElapsedTime().asSeconds() <= 1 / FPS) {
			animation.updateY(0, deltaTime);
			background.setTextureRect(animation.uvRect);

			window.draw(background);
			window.draw(novoJogo.text);
			window.draw(modoJogo.text);
			window.draw(modoJogoCorrida.text);
			window.draw(exit.text);
			window.draw(iniciar.text);

			window.draw(numJogadores.text);
			window.draw(doisJogadores.text);
			window.draw(tresJogadores.text);
			window.draw(quatroJogadores.text);

			sf::sleep(sf::seconds((1 / FPS) - clock.getElapsedTime().asSeconds()));
			atualizaTela = true;
		}

		if (atualizaTela) {

			window.display();

			deltaTime = clock.restart().asSeconds();
			atualizaTela = false;
		}


	}

	// Libera recursos e retorna
	/*novoJogo.~Option();
	modoJogo.~Option();
	modoJogoCorrida.~Option();
	exit.~Option();
	iniciar.~Option();
	numJogadores.~Option();
	doisJogadores.~Option();
	tresJogadores.~Option();
	quatroJogadores.~Option();*/

	return quit;
}

int Jogo::mainMenu() {
	int height = window.getSize().y;

	int quit = 0;

	/* Flag pra identificar se o jogo está no menu por ter voltado de uma tela
	 * Se for o caso, deltaTime receberá um valor muito grande e irá imprimir todos os frames "atrasados" em um curto espaço de tempo
	 * Essa flag permite atribuir um valor baixo para deltaTime e impedir que isso aconteça.
	 */
	bool resetaDeltaTime = false;

	sf::RectangleShape background(sf::Vector2f(1920.0f, 1080.0f));
	sf::Texture space;
	
	space.loadFromFile("bin/bg_menu.png");

	background.setTexture(&space);

	Animation animation(&space, sf::Vector2u(1, 15), 0.3f);

	Option jogar(190,  height / 4, 40, "NOVO JOGO", "bin/Pixelada.ttf");
	Option sair(190, 3 * height / 4, 40, "SAIR", "bin/Pixelada.ttf");
	Option instrucoes(190, 2 * height / 4, 40, "TUTORIAL", "bin/Pixelada.ttf"); //Adicionando as Instruções

	sf::Clock clock;
	float deltaTime = 0;
 
	/* if (!music.openFromFile("bin/menu_theme.wav")) {
			std::cout << "Error! Could not load menu_theme.wav!" << endl;
			quit = -1;
	}

	music.setVolume(30.f);
	music.setLoop(true);
	music.play();*/

	bool atualizaTela = true;

	while(!quit) {
		
		sf::Event event;

		/* Tratamento de eventos */ 
		while (window.pollEvent(event)) {


			switch (event.type) {
				case sf::Event::Closed:
					quit = -1;
					break;

				case sf::Event::MouseButtonPressed:
					if (sair.getHovering())
						quit = 1;
					
					if (instrucoes.getHovering()) {
						if (openInstructions() == -1) //Entrando nas Instruções
							quit = -1;
						resetaDeltaTime = true;

						instrucoes.setHovering(false);
					}

					if (jogar.getHovering()) {
						if (openJogar(animation, background) == -1)
							quit = -1;
						resetaDeltaTime = true;

						jogar.setHovering(false);
					}

					break;

				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Escape)
						quit = 1;
					break;
				
				case sf::Event::MouseMoved:
					if (sair.isHovering(event.mouseMove.x, event.mouseMove.y)) {
						sair.setHovering(true);
						sair.text.setFillColor(HOVER_COLOR);
					}
					else if (jogar.isHovering(event.mouseMove.x, event.mouseMove.y)) {
						jogar.setHovering(true);
						jogar.text.setFillColor(HOVER_COLOR);
					}
					else if (instrucoes.isHovering(event.mouseMove.x, event.mouseMove.y)) {
						instrucoes.setHovering(true);
						instrucoes.text.setFillColor(HOVER_COLOR);
					}
					else {
						instrucoes.setHovering(false);
						sair.setHovering(false);
						jogar.setHovering(false);

						sair.text.setFillColor(BUTTON_COLOR);
						jogar.text.setFillColor(BUTTON_COLOR);
						instrucoes.text.setFillColor(BUTTON_COLOR);
					}

					break;

				default:
					break;
			}
		}
			

			// Atualiza a tela apenas depois de processar os eventos e se tiver passado o tempo minimo necessario.
			// Caso contrário, torna a processar os eventos.
			if (clock.getElapsedTime().asSeconds() >= 1 / FPS) {
				atualizaTela = true;
			}

			if (atualizaTela) {
				atualizaTela = false;

				animation.updateY(0, deltaTime);
				background.setTextureRect(animation.uvRect);
				window.draw(background);
				window.draw(instrucoes.text);
				window.draw(sair.text);
				window.draw(jogar.text);
				window.display();

				deltaTime = clock.restart().asSeconds();

				if (resetaDeltaTime) {
					deltaTime = 0;
					resetaDeltaTime = false;
				}
			}

		}


	// Libera recursos e retorna
	//instrucoes.~Option();
	//sair.~Option();
	//jogar.~Option();

	space.~Texture();

	return quit;
}


int Jogo::playCorrida(int nplayers) {
	sf::Clock clock;

	sf::Text fps;
	sf::Font font;

	fps.setString("60");
	font.loadFromFile("bin/Pixelada.ttf");
	fps.setFont(font);
	fps.setFillColor(sf::Color::White);
	fps.setCharacterSize(24);
	fps.setPosition(window.getSize().x - fps.getLocalBounds().width, 0);

	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture space;
	sf::Texture texture;
	sf::Sprite boneco;

	space.loadFromFile("bin/bg_game.png");
	background.setTexture(&space);

	Animation animation(&space, sf::Vector2u(3, 15), 0.025f);

	int quit = 0;
	float deltaTime = 0;

	bool atualizaTela = true;
	bool mostraFPS = false;

	if (!texture.loadFromFile("bin/surfnauta_cinza.png")) {
		std::cout << "Error! Could not load textures!" << std::endl;
		quit = -1;
	}


	boneco.setTexture(texture);
	boneco.setScale(sf::Vector2f(0.1, 0.1));

	clock.restart();

	while (!quit) {

		sf::Event event;

		while (window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::MouseMoved:
					boneco.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
					break;
				case sf::Event::KeyReleased: // Volta para o menu
					if (event.key.code == sf::Keyboard::Escape)
						quit = 1;
					if (event.key.code == sf::Keyboard::F1)
						mostraFPS = !mostraFPS;
					break;

				case sf::Event::Closed: // Sai do jogo
					quit = -1;
					break;

				default:
					break;

			}	
		}

		if (clock.getElapsedTime().asSeconds() <= 1 / FPS) {
			animation.updateXY(deltaTime);
			background.setTextureRect(animation.uvRect);
			window.draw(background);
			window.draw(boneco);

			if (mostraFPS)
				window.draw(fps);

			atualizaTela = true;

			sf::sleep(sf::seconds((1 / FPS) - clock.getElapsedTime().asSeconds()));
		}
			
		if (atualizaTela) {
			window.display();

			deltaTime = clock.restart().asSeconds();

			fps.setString(std::to_string((int)round(1 / deltaTime)));
			fps.setPosition(window.getSize().x - fps.getLocalBounds().width, 0);

			atualizaTela = false;
		}

	}

	// Libera recursos e retorna
	boneco.~Sprite();
	texture.~Texture();
	space.~Texture();


	return quit;
}
