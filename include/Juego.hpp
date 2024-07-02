
#include <SFML/Graphics.hpp>
#include "Jugador.hpp"
#include "Cazador.hpp"
#include <vector>

class Juego {

private:
    void ProcesarEventos();
    void Actualizar(sf::Time deltaTiempo);
    void Dibujar();
    void AparecerCazador();


    sf::Sprite sprite;
    sf::RenderWindow ventana;
    Jugador jugador;
    std::vector<Cazador> cazador;
    sf::Clock reloj;
    sf::Font fuente;
    sf::Text textoTiempo;
    sf::Text textoPuntos;
    sf::Text textoReiniciar;
    sf::Text textoUltimaPuntuacion;
    int puntacion;
    int ultimaPuntuacion;
    bool gameOver;
    sf::Time tiempoAparicionUltimoCazador;
    sf::Texture texturaCazador;
    sf::Texture texturaJugador;
    sf::Texture backT;
	sf::Sprite back;

    
    
   
public:


    Juego();
    void Iniciar();
    void ReiniciarJuego();
};


//Video de la pantalla, README.dm