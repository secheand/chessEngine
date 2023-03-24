
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like cute_image.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//

#include <SFML/Graphics.hpp>

int main(int argc, char const** argv)
{
    // Declarations
    sf::Event event;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Chess");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (window.pollEvent(event))
        {
            // Check if user closed window
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Check if the user pressed scape to close window
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
