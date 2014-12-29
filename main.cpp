
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    // Create the main window
    RenderWindow window(sf::VideoMode(800, 600), "hahahahah");
    Font font;
    font.loadFromFile("/System/Library/Fonts/Menlo.ttc");

    Text text("Hello SFML", font, 50);
    text.setColor(Color::White);
    // Clear screen
    window.clear();
    

    window.draw(text);
    
    CircleShape circ(60);
    circ.setPosition(59, 350);
    Color circle;
    circle=Color::Cyan;
    circ.setFillColor(Color::Blue);
    
    
    // Draw the sprite
    window.draw(circ);
    
    // Update the window
    window.display();
    

    // Start the game loop
    while (window.isOpen())
    {

        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed) {
                window.close();
            }
            
            // Escape pressed : exit
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
        }




    }

    return EXIT_SUCCESS;
}
