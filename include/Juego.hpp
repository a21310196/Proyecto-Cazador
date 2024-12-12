
#ifndef JUEGO_HPP
#define JUEGO_HPP
#include <SFML/Graphics.hpp>
#include "Jugador.hpp"
#include "Cazador.hpp"
#include <vector>
#include <Sonido.hpp>
class Juego
{

private:
    Sonido sonido;

    sf::Sprite sprite;
    sf::RenderWindow ventana;
    Jugador jugador;
    std::vector<Cazador> cazador;
    sf::Clock reloj;
    sf::Font fuente;
    sf::Text textoTiempo;
    sf::Text textoPuntos;
    sf::Text textoReiniciar;
    sf::Text textotexturas;
    sf::Text textoUltimaPuntuacion;
    sf::Text textoPapeada;
    sf::Text textovictoria;
    sf::Text textovictoria2;

    int puntacion;
    int ultimaPuntuacion;

    sf::Time tiempoAparicionUltimoCazador;
    sf::Texture texturaCazador;
    sf::Texture texturaJugador;
    sf::Texture texturagameover;
    sf::Texture backT;
    sf::Texture texturaMamalon;

    sf::Sprite back;
    sf::Sprite texturaGAMEOVER;
    sf::Sprite spriteMamalon;

public:
    bool musicaFondoReproducida; // Bandera para controlar si la música de fondo se está reproduciendo
    bool musicaGameOverReproducida;
    bool musicaVictoriaReproducida;
    bool gameOver;
    bool victoria;
    Juego();

    void Iniciar();
    void ProcesarEventos();
    void Actualizar(sf::Time deltaTiempo);
    void Dibujar();
    void ReiniciarJuego();
    void AparecerCazador();
    void ChecarVictoria();
    void GestionarMusica();
};

#endif // JUEGO_HPP
       // Video de la pantalla, README.dm