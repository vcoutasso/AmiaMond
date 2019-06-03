#include "jogo.hpp"
#include "menu.hpp"

using namespace sf;

Jogo::~Jogo() {
	window.~RenderWindow();
}

Jogo::Jogo() {
}

void Jogo::openInstructions()
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
				window.close();
				break;

			case sf::Event::MouseMoved:		//Caso aperte no Botão Sair
				if (exit.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					exit.setHovering(true);
				}
				else
					exit.setHovering(false); //Para quando estiver fora voltar
				break;

			case sf::Event::MouseButtonPressed:
				if (exit.getHovering()) {
					return;
				}
				break;

			default:
				break;
			}

			if (clock.getElapsedTime().asSeconds() >= 1 / 60.f) {

				if (exit.getHovering())
					exit.text.setFillColor(sf::Color::Blue);
				else
					exit.text.setFillColor(sf::Color::Red);

				window.clear(sf::Color(123, 231, 111));
				window.draw(exit.text);
				window.draw(title.text);
				window.display();

				clock.restart();
			}
		}
	}
}

//TODO: Abrir funções a partir das opções do usuário
//Implemetando a Função Jogar contendo todas as opções de modo de jogo e quantidade de jogadores
void Jogo::openJogar()
{
	int width = window.getSize().x;
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

	Clock clock;

	while (window.isOpen()) {

		Event event;

		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseMoved:
				if (exit.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					exit.setHovering(true);
				}
				else
					exit.setHovering(false);

				if (iniciar.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					iniciar.setHovering(true);
				}
				else
					iniciar.setHovering(false);

				if (modoJogoCorrida.isHovering(event.mouseMove.x, event.mouseMove.y) && !modoJogoCorrida.getSelected()) {

					modoJogoCorrida.setHovering(true);
				}
				else
					modoJogoCorrida.setHovering(false);

				if (doisJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {

					doisJogadores.setHovering(true);
				}
				else
					doisJogadores.setHovering(false);

				if (tresJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					tresJogadores.setHovering(true);
				}
				else
					tresJogadores.setHovering(false);

				if (quatroJogadores.isHovering(event.mouseMove.x, event.mouseMove.y)) {
					quatroJogadores.setHovering(true);
				}
				else
					quatroJogadores.setHovering(false);
				break;

			case sf::Event::MouseButtonPressed:
				if (exit.getHovering()) {
					return;
				}

				if (modoJogoCorrida.getHovering()) {
					modoJogoCorrida.setSelected(true);
				}

				if (doisJogadores.getHovering()) {
					doisJogadores.setSelected(true);
					
					tresJogadores.setSelected(false);
					quatroJogadores.setSelected(false);
				}

				if (tresJogadores.getHovering()) {
					tresJogadores.setSelected(true);

					doisJogadores.setSelected(false);
					quatroJogadores.setSelected(false);
				}

				if (quatroJogadores.getHovering()) {
					quatroJogadores.setSelected(true);

					doisJogadores.setSelected(false);
					tresJogadores.setSelected(false);
				}
				break;

			default:
				break;
			}
		}

		if (clock.getElapsedTime().asSeconds() >= 1 / 60.f) {

			if (exit.getHovering()) {
				exit.text.setFillColor(sf::Color::Blue);
			}
			else
				exit.text.setFillColor(sf::Color::Red);

			if (iniciar.getHovering()) {
				iniciar.text.setFillColor(sf::Color::Blue);
			}
			else
				iniciar.text.setFillColor(sf::Color::Red);

			if (exit.getHovering()) {
				exit.text.setFillColor(sf::Color::Blue);
			}
			else
				exit.text.setFillColor(sf::Color::Red);

			if (modoJogoCorrida.getHovering()) {
				modoJogoCorrida.text.setFillColor(sf::Color::Blue);
			}
			else
				modoJogoCorrida.text.setFillColor(sf::Color::Red);

			if (doisJogadores.getHovering()) {
				doisJogadores.text.setFillColor(sf::Color::Blue);
			}
			else
				doisJogadores.text.setFillColor(sf::Color::Red);

			if (tresJogadores.getHovering()) {
				tresJogadores.text.setFillColor(sf::Color::Blue);
			}
			else
				tresJogadores.text.setFillColor(sf::Color::Red);

			if (quatroJogadores.getHovering()) {
				quatroJogadores.text.setFillColor(sf::Color::Blue);
			}
			else
				quatroJogadores.text.setFillColor(sf::Color::Red);

			if (modoJogoCorrida.getSelected()) {
				modoJogoCorrida.text.setFillColor(sf::Color::Black);
			}

			if (doisJogadores.getSelected()) {
				doisJogadores.text.setFillColor(sf::Color::Black);
			}

			if (tresJogadores.getSelected()) {
				tresJogadores.text.setFillColor(sf::Color::Black);
			}

			if (quatroJogadores.getSelected()) {
				quatroJogadores.text.setFillColor(sf::Color::Black);
			}

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
}

void Jogo::mainMenu() {
	int width = window.getSize().x;
	int height = window.getSize().y;

	Option jogar(width / 2,  height / 4, 40, "Novo Jogo", "bin/Roboto-Bold.ttf");
	Option sair(width / 2, 3 * height / 4, 40, "Sair", "bin/Roboto-Bold.ttf");
	Option instrucoes(width / 2, 2 * height / 4, 40, "Tutorial", "bin/Roboto-Bold.ttf"); //Adicionando as Instruções

	Clock clock;

	bool atualizaTela = true;

	while(window.isOpen()) {
		
		Event event;
		
		/* Tratamento de eventos */ 
		while (window.pollEvent(event)) {

			switch (event.type) {
				case Event::Closed:
					window.close();
					break;

				case Event::MouseButtonPressed:
					if (sair.getHovering())
						window.close();
					
					if (instrucoes.getHovering()) {
						openInstructions(); //Entrando nas Instruções

						instrucoes.setHovering(false);
					}

					if (jogar.getHovering()) {
						openJogar();

						jogar.setHovering(false);
					}

					break;

				case Event::KeyReleased:
					if (event.key.code == Keyboard::Escape)
						window.close();
					break;
				
				case Event::MouseMoved:
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
			if (clock.getElapsedTime().asSeconds() >= 1 / 60.f) {
				atualizaTela = true;
			}

			if (atualizaTela) {
				atualizaTela = false;

				if (sair.getHovering()) 
					sair.text.setFillColor(Color::Blue);
				else
					sair.text.setFillColor(Color::Red);
				

				if (jogar.getHovering())
					jogar.text.setFillColor(Color::Blue);
				else
					jogar.text.setFillColor(Color::Red);

				if (instrucoes.getHovering())
					instrucoes.text.setFillColor(Color::Blue);
				else
					instrucoes.text.setFillColor(Color::Red);
				

				window.clear(Color(123, 231, 111));
				window.draw(instrucoes.text);
				window.draw(sair.text);
				window.draw(jogar.text);
				window.display();

				clock.restart();
			}
		}


	}
}
