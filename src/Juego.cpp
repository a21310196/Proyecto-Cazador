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
      victoria(false),
      musicaFondoReproducida(false),    // Inicializa la bandera de musica de fondo
      musicaGameOverReproducida(false), // Inicializar la variable
      musicaVictoriaReproducida(false),
      tiempoAparicionUltimoCazador(sf::Time::Zero)
{
    ventana.setFramerateLimit(60);
    fuente.loadFromFile("assets/fonts/minecraft.ttf"); // Carga la fuente del texto

    sonido.CargarMusicaFondo();
    sonido.CargarMusicaGameOver();
    sonido.CargarMusicaVictoria();

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
    textoReiniciar.setPosition(200.f, 350.f);

    textoUltimaPuntuacion.setFont(fuente);
    textoUltimaPuntuacion.setCharacterSize(24);
    textoUltimaPuntuacion.setFillColor(sf::Color::White);
    textoUltimaPuntuacion.setPosition(10.f, 70.f);
    textoUltimaPuntuacion.setString("Ultima puntuacion: 0");

    textoPapeada.setFont(fuente);
    textoPapeada.setCharacterSize(40);
    textoPapeada.setFillColor(sf::Color::Black);
    textoPapeada.setPosition(175.f, 200.f);
    textoPapeada.setString("Tableado por pemdejom");

    textovictoria.setFont(fuente);
    textovictoria.setCharacterSize(23);
    textovictoria.setFillColor(sf::Color::Blue);
    textovictoria.setPosition(100.f, 300.f);
    textovictoria.setString("Te pudiste pelar de tu chinga por cicatron, Ahuevo perrillo!");

    textovictoria2.setFont(fuente);
    textovictoria2.setCharacterSize(30);
    textovictoria2.setFillColor(sf::Color::Blue);
    textovictoria2.setPosition(125.f, 200.f);
    textovictoria2.setString("Felicidades, lograste juntar todas las michas!");

    texturaJugador.loadFromFile("assets/images/Pemdejom.png");
    texturaCazador.loadFromFile("assets/images/Cartel.png");
    texturagameover.loadFromFile("assets/images/pipipi.png");
    texturaMamalon.loadFromFile("assets/images/mamalon.png");
    backT.loadFromFile("assets/images/back.png");

    back.setTexture(backT);
    back.setPosition(0, -15);
    back.setScale(4.5f, 3.05f);

    spriteMamalon.setTexture(texturaMamalon);
    spriteMamalon.setPosition(0, -15);
    spriteMamalon.setScale(4.1f, 3.00f);

    std::cout << "Estajalando" << std::endl;

    if (!backT.loadFromFile("resources/sprites/background.png"))
        if (!texturaJugador.loadFromFile("assets/images/Pemdejom.png"))
        {
            std::cout << "Error al cargar la textura del jugador." << std::endl;
        }

    if (!texturagameover.loadFromFile("assets/images/pipipi.png"))
    {
        std::cout << "Error al cargar la textura de Game Over." << std::endl;
    }
    {
        std::cout << "Error al cargar la textura resources/sprites/background.png" << '\n';
    }
    jugador = Jugador(texturaJugador);

    std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializar el generador de números aleatorios
}
void Juego::GestionarMusica()
{
    if (gameOver && !victoria)
    {
        if (!musicaGameOverReproducida)
        {
            sonido.DetenerMusica();            // Detener la música de fondo
            sonido.ReproducirMusicaGameOver(); // Reproducir música de Game Over

            musicaFondoReproducida = false;
            musicaGameOverReproducida = true;
            musicaVictoriaReproducida = false;
        }
    }
    else if (victoria && gameOver)
    {
        if (!musicaVictoriaReproducida)
        {
            sonido.ReproducirMusicaVictoria(); // Reproducir música de Victoria

            sonido.DetenerMusica(); // Detener la música de fondo
            sonido.DetenerMusicaGameOver();

            musicaFondoReproducida = false;
            musicaGameOverReproducida = false;
            musicaVictoriaReproducida = true;
        }
    }
    else
    {
        if (!musicaFondoReproducida)
        {
            sonido.ReproducirMusica(); // Reproducir la música de fondo
            sonido.DetenerMusicaGameOver();
            sonido.DetenerMusicaVictoria();
            musicaFondoReproducida = true;
            musicaGameOverReproducida = false;
            musicaVictoriaReproducida = false;
        }
    }
}

void Juego::Iniciar()
{

    sf::Clock reloj;

    sonido.CargarMusicaFondo();
    sonido.CargarMusicaGameOver();
    sonido.CargarMusicaVictoria();

    while (ventana.isOpen())
    {
        ProcesarEventos();

        sf::Time deltaTiempo = reloj.restart();

        // Realiza las actualizaciones del juego

        Actualizar(deltaTiempo);
        Dibujar();
        // Posicion incial aleatoria
    }
}
void Juego::ChecarVictoria()
{
    if (puntacion >= 500 && !gameOver)
    {
        victoria = true; // El jugador ha ganado
        gameOver = true; // Cambiar el estado del juego a Game Over (aunque sea victoria)
        textoTiempo.setString("¡Felicidades! completaste las" + std::to_string(puntacion) + " michas.");
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
    GestionarMusica();
    ultimaPuntuacion = puntacion;
    textoUltimaPuntuacion.setString("Ultima puntuacion: " + std::to_string(ultimaPuntuacion));
    puntacion = 0;
    gameOver = false;
    victoria = false;
    reloj.restart();
    tiempoAparicionUltimoCazador = sf::Time::Zero;
    cazador.clear();
    jugador.setTextura(texturaJugador);

    // Detener la música de Game Over

    // Detener cualquier música que esté sonando
    sonido.DetenerMusica();
    sonido.DetenerMusicaVictoria();
    sonido.DetenerMusicaGameOver();

    // Reproducir la música de fondo al reiniciar el juego
    sonido.ReproducirMusica();

    // Restablecer las banderas
    musicaGameOverReproducida = false;
    musicaFondoReproducida = true; // Ahora se está reproduciendo la música de fondo
    musicaVictoriaReproducida = false;
}

void Juego::Actualizar(sf::Time deltaTiempo)

{
    ChecarVictoria();
    GestionarMusica();

    if (gameOver && victoria)
    {
        // Si el jugador ha ganado, mostrar la pantalla de victoria

        spriteMamalon.setTexture(texturaMamalon);
        spriteMamalon.setPosition(0, 0);
        spriteMamalon.setScale(4.5f, 3.05f);
        std::cout << "¡Felicidades, ganaste!" << std::endl;
        return; // No actualices más si el juego está en victoria
    }

    if (gameOver && !victoria)
    {
        texturaGAMEOVER.setTexture(texturagameover);
        texturaGAMEOVER.setPosition(0, 0);
        texturaGAMEOVER.setScale(4.5f, 3.05f);
        std::cout << "Estajalando" << std::endl;

        return; // No actualices nada más si el juego ha terminado
    }

    float seconds = reloj.getElapsedTime().asSeconds();
    textoTiempo.setString("Tiempo: " + std::to_string(static_cast<int>(seconds)));

    puntacion += static_cast<int>(deltaTiempo.asSeconds() * 100);
    textoPuntos.setString("Michas juntadas: " + std::to_string(puntacion));

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
    if (victoria && gameOver)
    {
        // Mostrar mensaje de victori
        ventana.draw(spriteMamalon);  // Puedes cambiar esto por una imagen o texto de victoria
        ventana.draw(textovictoria);  // Podrías cambiarlo por un mensaje de victoria
        ventana.draw(textoReiniciar); // Puedes reutilizar el texto de reiniciar para indicar que se puede reiniciar
        ventana.draw(textovictoria2); // tetxo 2 de victoria
    }

    if (gameOver && !victoria)
    {
        ventana.draw(texturaGAMEOVER); // Muestra la pantalla de Game Over
        ventana.draw(textoPapeada);    // Mensaje de reinicio
        ventana.draw(textoReiniciar);  // Botón de reinicio
    }

    ventana.display();
}
void Juego::AparecerCazador()
{
    float velocidadAleatoria = static_cast<float>(50 + std::rand() % 400); // Velocidad aleatoria entre 50 y 200
    cazador.emplace_back(velocidadAleatoria, texturaCazador);
}