
#include <SFML/Graphics.hpp>

class Cazador
{

private:
    sf::Sprite sprite;
    float velocidad;

public:
    Cazador(float velocidad,const sf::Texture& textura);
    void Actualizar(const sf::Vector2f &posicionPresa, sf::Time deltaTiempo);
    void Dibujar(sf::RenderWindow &ventana) const;
    sf::FloatRect ObtenerBordes() const;
};

