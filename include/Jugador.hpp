
#include <SFML/Graphics.hpp>

class Jugador
{

private:
    sf::Sprite sprite;

public:
    bool gameOverMusicaReproducida;
    Jugador(const sf::Texture &textura);
    void Entrada(const sf::RenderWindow &ventana);
    void Dibujar(sf::RenderWindow &ventana) const;
    void Escogertextura(sf::RenderWindow &ventana);
    void setTextura(const sf::Texture &nuevaTextura);

    sf::Vector2f ObtenerPosicion() const;
    sf::FloatRect ObtenerBordes() const;
};