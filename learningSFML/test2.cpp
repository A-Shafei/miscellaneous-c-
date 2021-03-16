#include <SFML/Graphics.hpp>
#include <iostream>

int xOffset;
int yOffset;
sf::Vector2f shapeAtClick;

bool isOver(sf::CircleShape & target, sf::RenderWindow & relative)
{
    sf::FloatRect rect = target.getLocalBounds();
    sf::Vector2f topleft = target.getPosition();
    if (sf::Mouse::getPosition(relative).x < topleft.x || sf::Mouse::getPosition(relative).x > topleft.x + rect.width)
    {
        return false;
    }
    else if (sf::Mouse::getPosition(relative).y < topleft.y || sf::Mouse::getPosition(relative).y > topleft.y + rect.height)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{

    // anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);

    sf::CircleShape shape1(50.f);
    //  node.setOrigin(node.getLocalBounds().width/2, node.getLocalBounds().height/2);
    shape1.setFillColor(sf::Color(100, 250, 50));

    sf::CircleShape shape2(50.f);
    //  node.setOrigin(node.getLocalBounds().width/2, node.getLocalBounds().height/2);
    shape2.setFillColor(sf::Color(250, 100, 50));
    shape2.setPosition(200, 200);

    sf::VertexArray line(sf::LineStrip, 4);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && isOver(shape1, window))
                {
                    std::cout << "wat?" << std::endl;
                    shapeAtClick = shape1.getPosition();
                    xOffset = event.mouseButton.x - shapeAtClick.x;
                    yOffset = event.mouseButton.y - shapeAtClick.y;
                }
                if (event.mouseButton.button == sf::Mouse::Left && isOver(shape2, window))
                {
                    shapeAtClick = shape2.getPosition();
                    xOffset = event.mouseButton.x - shapeAtClick.x;
                    yOffset = event.mouseButton.y - shapeAtClick.y;
                }
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isOver(shape1, window) )
        {
            shape1.setPosition(sf::Mouse::getPosition(window).x - xOffset, sf::Mouse::getPosition(window).y - yOffset);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isOver(shape2, window) )
        {
            shape2.setPosition(sf::Mouse::getPosition(window).x - xOffset, sf::Mouse::getPosition(window).y - yOffset);
        }

        line[0].position = sf::Vector2f(shape1.getPosition().x+100, shape1.getPosition().y+100);
        line[1].position = sf::Vector2f(shape1.getPosition().x+150, shape1.getPosition().y+100);
        line[2].position = sf::Vector2f(shape2.getPosition().x, shape2.getPosition().y-50);
        line[3].position = shape2.getPosition();


        // clear the window with black color
        window.clear(sf::Color(245,245,245));

        // draw everything here...
        // window.draw(...);
        window.draw(shape1);
        window.draw(shape2);
        window.draw(line);

        // end the current frame
        window.display();
    }

    return 0;
}
