#include "menu.hpp"

Jogo::~Jogo() {
	buffer.~SoundBuffer();
	sound.~Sound();
	window.~RenderWindow();
}

Jogo::Jogo() {
}

int Jogo::openInstructions()
{
	int width = window.getSize().x;
	int height = window.getSize().y;

	Option exit(0, 0, 40, "Voltar para o Menu", "bin/Roboto-Bold.ttf");
	exit.text.setPosition(width - (exit.text.getGlobalBounds().width) - 14, height - 65);
	Option title(160, 30, 40, "Como jogar:", "bin/Roboto-Bold.ttf");

	title.text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);

	sf::Clock clock;

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:
				return -1;
				break;

			case sf::Event::MouseMoved:		//Caso aperte no Botão Sair
				if (exit.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					exit.setHovering(true);
					exit.text.setFillColor(sf::Color::Blue);
				}
				else {
					exit.setHovering(false); //Para quando estiver fora voltar
					exit.text.setFillColor(sf::Color::Red);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (exit.getHovering()) {
					return 1;
				}
				break;

			default:
				break;
			}

			if (clock.getElapsedTime().asSeconds() >= 1 / FPS) {

				window.clear(sf::Color(123, 231, 111));
				window.draw(exit.text);
				window.draw(title.text);
				window.display();

				clock.restart();
			}
		}
	}

	return 1;
}

//TODO: Abrir funções a partir das opções do usuário
//Implemetando a Função Jogar contendo todas as opções de modo de jogo e quantidade de jogadores
int Jogo::openJogar()
{
	int height = window.getSize().y;

	Option modoJogo(0, 0, 40, "Modo de Jogo", "bin/Roboto-Bold.ttf");
	modoJogo.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 4 * height / 15 + 30);
	modoJogo.text.setFillColor(sf::Color::Yellow);

	Option novoJogo(0, 0, 40, "* Selecione o Estilo de Jogo:", "bin/Roboto-Bold.ttf");
	novoJogo.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 10);
	novoJogo.text.setStyle(sf::Text::Bold | sf::Text::Italic | sf::Text::Underlined);

	Option modoJogoCorrida(0, 0, 40, "Corrida", "bin/Roboto-Bold.ttf");
	modoJogoCorrida.text.setPosition(450, 4 * height / 15 + 30);

	Option exit(0, 0, 40, "Voltar para o Menu", "bin/Roboto-Bold.ttf");
	exit.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, height - 65);

	Option numJogadores(0, 0, 40, "Nm. de Jogadores", "bin/Roboto-Bold.ttf");
	numJogadores.text.setPosition(modoJogo.text.getGlobalBounds().width / 10 - 3, 8 * height / 15 + 30);
	numJogadores.text.setFillColor(sf::Color::Yellow);

	Option doisJogadores(460 , 8 * height / 15 + 30, 40, "2", "bin/Roboto-Bold.ttf");
	Option tresJogadores(450 + 310, 8 * height / 15 + 30, 40, "3", "bin/Roboto-Bold.ttf");
	Option quatroJogadores(450 + 620, 8 * height / 15 + 30, 40, "4", "bin/Roboto-Bold.ttf");

	Option iniciar(1100, height - 65, 40, "Iniciar!", "bin/Roboto-Bold.ttf");

	sf::Clock clock;

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:
				return -1;
				break;

			case sf::Event::MouseMoved:

				if (exit.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					exit.setHovering(true);
					exit.text.setFillColor(sf::Color::Blue);
				}
				else if (iniciar.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					iniciar.setHovering(true);
					iniciar.text.setFillColor(sf::Color::Blue);
				}
				else if (modoJogoCorrida.isHovering(event.mouseMove.x, event.mouseMove.y) && !modoJogoCorrida.getSelected()) {
					modoJogoCorrida.setHovering(true);
					if (!modoJogoCorrida.getSelected()) modoJogoCorrida.text.setFillColor(sf::Color::Blue);
				}
				else if (doisJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					doisJogadores.setHovering(true);
					if (!doisJogadores.getSelected()) doisJogadores.text.setFillColor(sf::Color::Blue);
				}
				else if (tresJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					tresJogadores.setHovering(true);
					if (!tresJogadores.getSelected()) tresJogadores.text.setFillColor(sf::Color::Blue);
				}
				else if (quatroJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					quatroJogadores.setHovering(true);
					if (!quatroJogadores.getSelected()) quatroJogadores.text.setFillColor(sf::Color::Blue);
				}
				else { // Se o mouse não estiver sobre nenhuma opção, desmarca todas
					exit.setHovering(false);
					iniciar.setHovering(false);
					modoJogoCorrida.setHovering(false);
					doisJogadores.setHovering(false);
					tresJogadores.setHovering(false);
					quatroJogadores.setHovering(false);

					exit.text.setFillColor(sf::Color::Red); 
					iniciar.text.setFillColor(sf::Color::Red); 
					if (!modoJogoCorrida.getSelected()) modoJogoCorrida.text.setFillColor(sf::Color::Red); 
					if (!doisJogadores.getSelected()) doisJogadores.text.setFillColor(sf::Color::Red);
					if (!tresJogadores.getSelected()) tresJogadores.text.setFillColor(sf::Color::Red);
					if (!quatroJogadores.getSelected()) quatroJogadores.text.setFillColor(sf::Color::Red);
				}
				
				break;

			case sf::Event::MouseButtonPressed:
				if (exit.getHovering()) {
					return 1;
				}


				if ((doisJogadores.getHovering() || tresJogadores.getHovering() || quatroJogadores.getHovering())) {
					doisJogadores.text.setFillColor(sf::Color::Red);
					tresJogadores.text.setFillColor(sf::Color::Red);
					quatroJogadores.text.setFillColor(sf::Color::Red);

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
							return -1;
					}
				}
				break;

			default:
				break;
			}
		}

		if (clock.getElapsedTime().asSeconds() >= 1 / FPS) {

			window.clear(sf::Color(123, 231, 111));

			window.draw(novoJogo.text);
			window.draw(modoJogo.text);
			window.draw(modoJogoCorrida.text);
			window.draw(exit.text);
			window.draw(iniciar.text);

			window.draw(numJogadores.text);
			window.draw(doisJogadores.text);
			window.draw(tresJogadores.text);
			window.draw(quatroJogadores.text);

			window.display();

			clock.restart();
		}


	}
	return 1;
}

int Jogo::mainMenu() {
	int width = window.getSize().x;
	int height = window.getSize().y;

	Option jogar(width / 2,  height / 4, 40, "Novo Jogo", "bin/Roboto-Bold.ttf");
	Option sair(width / 2, 3 * height / 4, 40, "Sair", "bin/Roboto-Bold.ttf");
	Option instrucoes(width / 2, 2 * height / 4, 40, "Tutorial", "bin/Roboto-Bold.ttf"); //Adicionando as Instruções

	sf::Clock clock;

	if (!buffer.loadFromFile("bin/menu_theme.wav")) {
			std::cout << "Error! Could not load menu_theme.wav!" << endl;
			return -1;
	}

	sound.setBuffer(buffer);
	sound.setVolume(50.f);
	sound.play();
	sound.setLoop(true);

	bool atualizaTela = true;

	while(window.isOpen()) {
		
		sf::Event event;
		
		/* Tratamento de eventos */ 
		while (window.pollEvent(event)) {

			switch (event.type) {
				case sf::Event::Closed:
					return -1;
					break;

				case sf::Event::MouseButtonPressed:
					if (sair.getHovering())
						return 1;
					
					if (instrucoes.getHovering()) {
						if (openInstructions() == -1) //Entrando nas Instruções
							return -1;

						instrucoes.setHovering(false);
					}

					if (jogar.getHovering()) {
						if (openJogar() == -1)
							return -1;

						jogar.setHovering(false);
					}

					break;

				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Escape)
						return 1;
					break;
				
				case sf::Event::MouseMoved:
					if (sair.isHovering(event.mouseMove.x, event.mouseMove.y))
						sair.setHovering(true);
					else if (jogar.isHovering(event.mouseMove.x, event.mouseMove.y))
						jogar.setHovering(true);
					else if (instrucoes.isHovering(event.mouseMove.x, event.mouseMove.y)) 
						instrucoes.setHovering(true);
					else {
						instrucoes.setHovering(false);
						sair.setHovering(false);
						jogar.setHovering(false);
					}

					break;

				default:
					break;
			}
			
			// Atualiza a tela apenas depois de processar os eventos e se tiver passado o tempo minimo necessario.
			// Caso contrário, torna a processar os eventos.
			if (clock.getElapsedTime().asSeconds() >= 1 / FPS) {
				atualizaTela = true;
			}

			if (atualizaTela) {
				atualizaTela = false;

				if (sair.getHovering()) 
					sair.text.setFillColor(sf::Color::Blue);
				else
					sair.text.setFillColor(sf::Color::Red);
				

				if (jogar.getHovering())
					jogar.text.setFillColor(sf::Color::Blue);
				else
					jogar.text.setFillColor(sf::Color::Red);

				if (instrucoes.getHovering())
					instrucoes.text.setFillColor(sf::Color::Blue);
				else
					instrucoes.text.setFillColor(sf::Color::Red);
				

				window.clear(sf::Color(123, 231, 111));
				window.draw(instrucoes.text);
				window.draw(sair.text);
				window.draw(jogar.text);
				window.display();

				clock.restart();
			}
		}


	}
	return 1;
}

int Jogo::playCorrida(int nplayers) {
	sf::Clock clock;

	sf::Texture texture;

	if (!texture.loadFromFile("bin/surfnauta_cinza.png")) {
		std::cout << "Error! Could not load textures!" << std::endl;
		return -1;
	}

	sf::Sprite boneco;

	boneco.setTexture(texture);
	boneco.setScale(sf::Vector2f(0.1, 0.1));

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::MouseMoved:
					boneco.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
					break;
				case sf::Event::KeyReleased: // Volta para o menu
					if (event.key.code == sf::Keyboard::Escape)
						return 1;
					break;

				case sf::Event::Closed: // Sai do jogo
					return -1;
					break;

				default:
					break;

			}	
		}

		if (clock.getElapsedTime().asSeconds() >= 1 / FPS) {
			window.clear(sf::Color::Black);
			window.draw(boneco);
			window.display();
		}

	}
	return 1;
}
