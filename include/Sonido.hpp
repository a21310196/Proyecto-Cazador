#ifndef SONIDO_HPP
#define SONIDO_HPP
#include <SFML/Audio.hpp> // Librería de audio de SFML

class Sonido
{
private:
    sf::SoundBuffer _musicaFondo;    // Música de fondo
    sf::SoundBuffer _musicaGameOver; // Música de Game Over
    sf::SoundBuffer _musicavictoria;
    sf::Sound _sonidoFondo;    // Objeto para reproducir la música de fondo
    sf::Sound _sonidoGameOver; // Objeto para reproducir la música de Game Over
    sf::Sound _sonidovictoria;

public:
    Sonido();  // Solo declaramos el constructor
    ~Sonido(); // Declaramos el destructor

    void CargarMusicaFondo();    // Cargar música de fondo
    void CargarMusicaGameOver(); // Cargar música de Game Over
    void CargarMusicaVictoria();

    void ReproducirMusica();         // Reproducir música de fondo
    void ReproducirMusicaGameOver(); // Reproducir música de Game Over
    void ReproducirMusicaVictoria();

    void DetenerMusicaVictoria();
    void DetenerMusica(); // Detener la música
    void DetenerMusicaGameOver();
};
#endif // SONIDO_HPP