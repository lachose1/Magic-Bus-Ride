#include <cstdlib>
#include <SFML/Graphics.hpp> 

using namespace sf;

int main()
{
    RenderWindow app(VideoMode(800, 600, 32), "Ma premiere fenetre SFML ! ");

    // Boucle principale
    while (app.IsOpened())
    {
        Event event;

        while (app.GetEvent(event))
        {
            if (event.Type == Event::Closed)
                app.Close();
        }

        // Remplissage de l'écran (couleur noire par défaut)
        app.Clear();

        // Affichage de la fenêtre à l'écran
        app.Display();
    }
    return EXIT_SUCCESS;
}