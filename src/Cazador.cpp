#include "..\include\Cazador.hpp"
#include <cmath>

Cazador::Cazador(float velocidad,const sf::Texture& textura) : velocidad(velocidad) {
    sprite.setTexture(textura);
    sprite.setScale(0.3f, 0.3f); // Escala de 0.3
    // Posicion incial aleatoria
    sprite.setPosition(static_cast<float>(std::rand() % 800), static_cast<float>(std::rand() % 600));
}

void Cazador::Actualizar(const sf::Vector2f& posicionPresa, sf::Time deltaTiempo) {
    sf::Vector2f posicionCazador = sprite.getPosition();
    sf::Vector2f direccion = posicionPresa - posicionCazador;
    float longitud = std::sqrt(direccion.x * direccion.x + direccion.y * direccion.y);

    if (longitud != 0) {
        direccion /= longitud; // Normaliza la dirección
    }

    sprite.move(direccion * velocidad * deltaTiempo.asSeconds());
}

void Cazador::Dibujar(sf::RenderWindow& ventana) const {
    ventana.draw(sprite);
}

sf::FloatRect Cazador::ObtenerBordes() const {
    return sprite.getGlobalBounds();
}

