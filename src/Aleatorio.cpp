#include "..\include\Aleatorio.hpp"
#include <cstdlib>

float obtenetFlotanteAleatorio(float minimo, float maximo) {
    return minimo + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maximo - minimo)));
}

sf::Vector2f obtenerPosicionAleatoria(const sf::RenderWindow& ventana) {
    float x = obtenetFlotanteAleatorio(0.f, static_cast<float>(ventana.getSize().x));
    float y = obtenetFlotanteAleatorio(0.f, static_cast<float>(ventana.getSize().y));
    return sf::Vector2f(x, y);
}
