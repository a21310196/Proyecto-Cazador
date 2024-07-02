
#include <SFML/Graphics.hpp>

class Jugador
{

private:
    sf::Sprite sprite;

public:
    Jugador(const sf::Texture& textura);
    void Entrada(const sf::RenderWindow &ventana);
    void Dibujar(sf::RenderWindow &ventana) const;
    sf::Vector2f ObtenerPosicion() const;
    sf::FloatRect ObtenerBordes() const;
    };