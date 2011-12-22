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

        // Remplissage de l'�cran (couleur noire par d�faut)
        app.Clear();

        // Affichage de la fen�tre � l'�cran
        app.Display();
    }
    return EXIT_SUCCESS;
}