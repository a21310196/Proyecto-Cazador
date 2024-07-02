#include <Juego.hpp>
#include <Sonido.hpp>

#include <iostream>
#include <cstdlib>
#include <ctime>

Juego::Juego()
    : ventana(sf::VideoMode(800, 600), "Presa VS Cazador"),
      jugador(texturaJugador),
      puntacion(0),
      ultimaPuntuacion(0),
      gameOver(false),
      tiempoAparicionUltimoCazador(sf::Time::Zero)
{
    ventana.setFramerateLimit(60);
    fuente.loadFromFile("assets/fonts/minecraft.ttf"); // Carga la fuente del texto

    textoTiempo.setFont(fuente);
    textoTiempo.setCharacterSize(24);
    textoTiempo.setFillColor(sf::Color::Blue);
    textoTiempo.setPosition(10.f, 10.f);

    textoPuntos.setFont(fuente);
    textoPuntos.setCharacterSize(24);
    textoPuntos.setFillColor(sf::Color::Blue);
    textoPuntos.setPosition(10.f, 40.f);

    textoReiniciar.setFont(fuente);
    textoReiniciar.setCharacterSize(30);
    textoReiniciar.setFillColor(sf::Color::Yellow);
    textoReiniciar.setString("Presiona click para reiniciar");
    textoReiniciar.setPosition(200.f, 300.f);

    textoUltimaPuntuacion.setFont(fuente);
    textoUltimaPuntuacion.setCharacterSize(24);
    textoUltimaPuntuacion.setFillColor(sf::Color::White);
    textoUltimaPuntuacion.setPosition(10.f, 70.f);
    textoUltimaPuntuacion.setString("Ultima puntuacion: 0");

    texturaJugador.loadFromFile("assets/images/jugador.png");
    texturaCazador.loadFromFile("assets/images/cazador.png");
    backT.loadFromFile("assets/images/pipipi.png");

    back.setTexture(backT);
    back.setPosition(0, -15);
    back.setScale(4.1f, 3.00f);
    std::cout << "Estajalando" << std::endl;

    if (!backT.loadFromFile("resources/sprites/background.png"))
    {
        std::cout << "Error al cargar la textura resources/sprites/background.png" << '\n';
    }

    jugador = Jugador(texturaJugador);

    std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializar el generador de números aleatorios
}

void Juego::Iniciar()
{
    sf::Clock reloj;
    Sonido sonido;
    sonido.CargarMusicaFondo();
    while (ventana.isOpen())
    {

        ProcesarEventos();

        sf::Time deltaTiempo = reloj.restart();
        if (!gameOver)
        {
            Actualizar(deltaTiempo);
        }
        Dibujar();
        // Posicion incial aleatoria
    }
}

void Juego::ProcesarEventos()
{
    sf::Event evento;
    while (ventana.pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
        {
            ventana.close();
        }
        if (evento.type == sf::Event::MouseButtonPressed && gameOver)
        {
            ReiniciarJuego();
        }
    }
}

void Juego::ReiniciarJuego()
{
    ultimaPuntuacion = puntacion;
    textoUltimaPuntuacion.setString("Ultima puntuacion: " + std::to_string(ultimaPuntuacion));
    gameOver = false;
    puntacion = 0;
    reloj.restart();
    tiempoAparicionUltimoCazador = sf::Time::Zero;
    cazador.clear();
    jugador = Jugador(texturaJugador);
}

void Juego::Actualizar(sf::Time deltaTiempo)
{
    if (gameOver)
    {
        return;
    }

    float seconds = reloj.getElapsedTime().asSeconds();
    textoTiempo.setString("Tiempo: " + std::to_string(static_cast<int>(seconds)));

    puntacion += static_cast<int>(deltaTiempo.asSeconds() * 100);
    textoPuntos.setString("Puntuacion: " + std::to_string(puntacion));

    jugador.Entrada(ventana);

    // Añadir un nuevo cazador cada 2 segundos
    if (reloj.getElapsedTime() - tiempoAparicionUltimoCazador >= sf::seconds(2))
    {
        AparecerCazador();
        tiempoAparicionUltimoCazador = reloj.getElapsedTime();
    }

    for (auto &cazador : cazador)
    {
        cazador.Actualizar(jugador.ObtenerPosicion(), deltaTiempo);
        if (cazador.ObtenerBordes().intersects(jugador.ObtenerBordes()))
        {
            gameOver = true;
            textoTiempo.setString("Game Over! Ultima puntuacion: " + std::to_string(puntacion));
        }
    }
}

void Juego::Dibujar()
{
    ventana.clear();
    ventana.draw(back);

    jugador.Dibujar(ventana);

    for (const auto &cazador : cazador)
    {
        cazador.Dibujar(ventana);
    }

    ventana.draw(textoTiempo);
    ventana.draw(textoPuntos);
    ventana.draw(textoUltimaPuntuacion);
    if (gameOver)
    {
        ventana.draw(textoReiniciar);
    }

    ventana.display();
}
void Juego::AparecerCazador()
{
    float velocidadAleatoria = static_cast<float>(50 + std::rand() % 400); // Velocidad aleatoria entre 50 y 200
    cazador.emplace_back(velocidadAleatoria, texturaCazador);
}
