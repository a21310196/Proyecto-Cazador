#include "Sonido.hpp"
#include <iostream> // Para imprimir errores

// Definición del constructor Sonido::Sonido()
Sonido::Sonido()
{
    // Si no necesitas hacer nada específico en el constructor, lo puedes dejar vacío
    // El constructor implícito se crea automáticamente si no se declara uno explícitamente,
    // pero si lo defines explícitamente, no hay que olvidarse de poner 'Sonido::' delante.
}

// Definición del destructor
Sonido::~Sonido()
{
    // Si necesitas hacer algo cuando la clase sea destruida, lo puedes agregar aquí.
    // Si no, lo puedes dejar vacío. SFML maneja la liberación de los recursos automáticamente.
}

// Funciones miembro
void Sonido::CargarMusicaVictoria()
{
    if (!_musicavictoria.loadFromFile("assets/music/victoria.ogg"))
    {
        std::cerr << "Error al cargar la música de fondo." << std::endl;
    }
}
void Sonido::CargarMusicaFondo()
{
    if (!_musicaFondo.loadFromFile("assets/music/troquero locochon.ogg"))
    {
        std::cerr << "Error al cargar la música de fondo." << std::endl;
    }
}
void Sonido::CargarMusicaGameOver()
{
    if (!_musicaGameOver.loadFromFile("assets/music/pipipi.ogg"))
    {
        std::cerr << "Error al cargar la música de Game Over." << std::endl;
    }
}

void Sonido::ReproducirMusicaVictoria()
{
    _sonidovictoria.setBuffer(_musicavictoria);
    _sonidovictoria.play();
}
void Sonido::ReproducirMusica()
{
    _sonidoFondo.setBuffer(_musicaFondo);
    _sonidoFondo.play();
}
void Sonido::ReproducirMusicaGameOver()
{
    _sonidoGameOver.setBuffer(_musicaGameOver);
    _sonidoGameOver.play();
}

void Sonido::DetenerMusica()
{
    _sonidoFondo.stop();
}
void Sonido::DetenerMusicaGameOver()
{
    _sonidoGameOver.stop();
}
void Sonido::DetenerMusicaVictoria()
{
    _sonidovictoria.stop();
}