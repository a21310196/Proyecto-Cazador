#include "../include/Jugador.hpp"

Jugador::Jugador(const sf::Texture& textura) {
    sprite.setTexture(textura);
    sprite.setScale(0.3f, 0.3f); // Escalar la textura si es necesario
    sprite.setPosition(400.f, 300.f); // Posición inicial en el centro de la ventana
}

void Jugador::Entrada(const sf::RenderWindow& ventana) {
    sf::Vector2i posicionMouse = sf::Mouse::getPosition(ventana);
    sprite.setPosition(static_cast<float>(posicionMouse.x), static_cast<float>(posicionMouse.y));
}

void Jugador::Dibujar(sf::RenderWindow& ventana) const {
    ventana.draw(sprite);
}

sf::Vector2f Jugador::ObtenerPosicion() const {
    return sprite.getPosition();
}

sf::FloatRect Jugador::ObtenerBordes() const {
    return sprite.getGlobalBounds();
}
