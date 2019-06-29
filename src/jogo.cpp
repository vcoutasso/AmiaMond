#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <cmath>

#include "option.hpp"
#include "jogo.hpp"
#include "corrida.hpp"
#include "player.hpp"

#include "collision.hpp"

Jogo::Jogo() {
	font.loadFromFile("bin/Pixelada.ttf");
	fps.setFont(font);
	fps.setCharacterSize(24);
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
	exit.text.setPosition(static_cast<float>(width) - (exit.text.getGlobalBounds().width) - 14, static_cast<float>(height) - 65);
	Option title(160, 30, 40, "COMO JOGAR:", "bin/Pixelada.ttf");

	title.text.setStyle(sf::Text::Bold | sf::Text::Italic);

	sf::Clock clock;

	while (!quit) {

		sf::Event event{};

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
				sf::sleep(sf::seconds(static_cast<float>(1.f / FPS - clock.getElapsedTime().asSeconds())));

			}

			atualizaTela = true;

			if (atualizaTela) {
				window.display();

				deltaTime = clock.restart().asSeconds();
				atualizaTela = false;
			}

		}


	return quit;
}


// Implemetando a Função Jogar contendo todas as opções de modo de jogo e quantidade de jogadores
int Jogo::openJogar(Animation& animation, sf::RectangleShape& background) {
	float height = window.getSize().y;

	int quit = 0;
	bool atualizaTela = true;

	Option modoJogo(0, 0, 40, "MODO DE JOGO:", "bin/Pixelada.ttf");
	modoJogo.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 4 * height / 15.f + 30);
	modoJogo.text.setFillColor(sf::Color::Yellow);

	Option novoJogo(0, 0, 40, "* SELECIONE O ESTILO DE JOGO:", "bin/Pixelada.ttf");
	novoJogo.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 10);
	novoJogo.text.setStyle(sf::Text::Bold | sf::Text::Italic);

	Option modoJogoCorrida(0, 0, 40, "CORRIDA", "bin/Pixelada.ttf");
	modoJogoCorrida.text.setPosition(100, 400);

	Option exit(0, 0, 40, "VOLTAR PARA O MENU", "bin/Pixelada.ttf");
	exit.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, height - 65);

	Option numJogadores(0, 0, 40, "NM. DE JOGADORES:", "bin/Pixelada.ttf");
	numJogadores.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 8 *height / 15 + 30);
	numJogadores.text.setFillColor(sf::Color::Yellow);

	Option doisJogadores(100 , 8 * height / 15 + 150, 40, "2", "bin/Pixelada.ttf");
	Option tresJogadores(100 + 100, 8 * height / 15 + 150, 40, "3", "bin/Pixelada.ttf");
	Option quatroJogadores(100 + 200, 8 * height / 15 + 150, 40, "4", "bin/Pixelada.ttf");

	Option iniciar(1800, height - 65, 40, "INICIAR!", "bin/Pixelada.ttf");

	sf::Clock clock;
	float deltaTime = 0;

	while (!quit) {

		sf::Event event{};

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
					modoJogoCorrida.text.setFillColor(SELECTED_COLOR);
				}

				if (doisJogadores.getHovering()) {
					doisJogadores.setSelected(true);
					doisJogadores.text.setFillColor(SELECTED_COLOR);
				}
				else if (tresJogadores.getHovering()) {
					tresJogadores.setSelected(true);
					tresJogadores.text.setFillColor(SELECTED_COLOR);
				}
				else if (quatroJogadores.getHovering()) {
					quatroJogadores.setSelected(true);
					quatroJogadores.text.setFillColor(SELECTED_COLOR);
				}

				if (iniciar.getHovering()) {
					// So inicia o jogo se estiver com todas as opções pertinentes selecionadas
					if ((doisJogadores.getSelected() || tresJogadores.getSelected() || quatroJogadores.getSelected()) && (modoJogoCorrida.getSelected())) {
						int n = 2;

						if (tresJogadores.getSelected())
							n = 3;
						else if (quatroJogadores.getSelected())
							n = 4;

						if (playCorrida(n) == -1)
							quit = -1;

						iniciar.text.setFillColor(sf::Color::White);
						window.draw(iniciar.text);
						clock.restart();
					}
				}
				break;

			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					// So inicia o jogo se estiver com todas as opções pertinentes selecionadas
					if ((doisJogadores.getSelected() || tresJogadores.getSelected() || quatroJogadores.getSelected()) && (modoJogoCorrida.getSelected())) {
						int n = 2;

						if (tresJogadores.getHovering())
							n = 3;
						else if (quatroJogadores.getHovering())
							n = 4;

						if (playCorrida(n) == -1)
							quit = -1;

						iniciar.text.setFillColor(sf::Color::White);
						window.draw(iniciar.text);
						clock.restart();
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

			sf::sleep(sf::seconds(1 / FPS - clock.getElapsedTime().asSeconds()));
		}

		atualizaTela = true;

		if (atualizaTela) {

			window.display();

			deltaTime = clock.restart().asSeconds();
			atualizaTela = false;
		}


	}


	return quit;
}

int Jogo::mainMenu() {
	float height = window.getSize().y;

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

	 if (!music.openFromFile("bin/menu_theme.wav")) {
			std::cout << "Error! Could not load menu_theme.wav!" << std::endl;
			quit = -1;
	}

	music.setVolume(30.f);
	music.setLoop(true);
	music.play();

	bool atualizaTela = true;

	while(!quit) {

		sf::Event event{};

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

				// Monitora os movimentos do mouse para verificar se está sobre alguma opção
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
			if (clock.getElapsedTime().asSeconds() <= 1 / FPS) {
				animation.updateY(0, deltaTime);
				background.setTextureRect(animation.uvRect);
				window.draw(background);
				window.draw(instrucoes.text);
				window.draw(sair.text);
				window.draw(jogar.text);

				sf::sleep(sf::seconds((1 / FPS) - clock.getElapsedTime().asSeconds()));
			}

			atualizaTela = true;

			if (atualizaTela) {
				atualizaTela = false;

				window.display();

				deltaTime = clock.restart().asSeconds();

				if (resetaDeltaTime) {
					deltaTime = 0;
					resetaDeltaTime = false;
				}
			}

		}



	return quit;
}

// Método principal do jogo no modo Corrida
int Jogo::playCorrida(int nplayers) {

	sf::Clock clock;
	sf::Clock clockObstaculos;

	// Define o intervalo entre a criação de diferentes obstaculos
	sf::Time intervaloObstaculos = sf::seconds(1.5);

	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture space;

	Corrida corrida (nplayers);

	const int xInicial = 860;
	int yInicial = 170;
	const int velInicial = 9;


	// Inicializa os bonecos
	for (int n = 0; n < corrida.getNumPlayers(); ++n) {
		corrida.initPlayer(sf::Vector2f(xInicial, yInicial), sf::Vector2f(0.1, 0.1), "bin/surfnauta_cinza.png", velInicial);
		yInicial += yInicial;
	}

	space.loadFromFile("bin/bg_game.png");
	background.setTexture(&space);

	Animation animation(&space, sf::Vector2u(3, 15), 0.025f);

	int quit = 0;
	float deltaTime = 0;

	bool atualizaTela = true;
	bool mostraFPS = false;

	background.setTexture(&space);

	clock.restart();

	window.setMouseCursorVisible(false);

	// Clock que nunca é resetado para saber quanto tempo passou desde o inicio do jogo
	// Usado para aumentar a dificuldade do jogo com o tempo
	sf::Clock gameTimer;

	while (!quit) {

		sf::Event event{};

		// Permanece no loop até tratar todos os eventos. Tratamento é feito através de um switch case no método handleEvents()
		while (window.pollEvent(event))
			corrida.handleEvents(event, quit, mostraFPS);
			
		// Muda o background para fazer a animação e desenha na tela.
		animation.updateXY(deltaTime);			
		background.setTextureRect(animation.uvRect);
	
		window.draw(background);

		// Se passou o tempo definido em intervaloObstaculos, cria um novo obstaculo e reseta o clock.
		if (clockObstaculos.getElapsedTime().asSeconds() >= intervaloObstaculos.asSeconds()) {
			corrida.criaObstaculo();
			clockObstaculos.restart();
		}

		// Desenha elementos na tela
		if (clock.getElapsedTime().asSeconds() <= 1 / FPS) {


			corrida.removeObstaculos(); // Remove todos os obstaculos que não estão mais visiveis na tela
			corrida.desenhaObstaculos(window); // Desenha obstaculos restantes na tela

			// Checa colisão com todos os tipos de obstáculos
			corrida.colisaoEstatico();
			corrida.colisaoGiratorio();
			corrida.colisaoVazado();

			// Remove os jogadores que morreram.
			//corrida.mataMatado();

			// Faz os joagdores se deslocarem para a posição inicial em x (860) se for necessário.
			corrida.retornaPlayers();

			// Desenha jogadores
			corrida.desenhaPlayers(window);

			// Aguarda para manter um fps proximo de 60
			sf::sleep(sf::seconds(1 / FPS - clock.getElapsedTime().asSeconds()));
		}

		atualizaTela = true;


		if (atualizaTela) {

			deltaTime = clock.restart().asSeconds();

			if (mostraFPS)
				showFPS(deltaTime);

			window.display();

			atualizaTela = false;
		}

	}

	window.setMouseCursorVisible(true);

	return quit;
}

// Mostra a quantidade de frames por segundo no canto superior direito da tela.
void Jogo::showFPS(float deltaTime) {
	fps.setString(std::to_string((int)round(1 / deltaTime)));
	fps.setFillColor(sf::Color::White);
	fps.setPosition(window.getSize().x - fps.getLocalBounds().width, 0);

	window.draw(fps);
}
