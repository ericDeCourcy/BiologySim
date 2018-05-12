//This file loads all of the textures needed for the program

#include <SFML/Graphics.hpp>

sf::Sprite redCell;
sf::Sprite greenCell;
sf::Sprite menuBlock;
sf::Sprite pause;
sf::Sprite options;
sf::Sprite pauseScreen;
sf::Sprite pauseChartObj;
sf::Sprite play;
sf::Sprite cellHolder;

int loadTextures()
{
    sf::Texture redCellTexture;
    if (!redCellTexture.loadFromFile("redCell.gif"))
    {   return EXIT_FAILURE;    }                //exits game if file cannot be found
    sf::Sprite redCell(redCellTexture);

    //loads the geeencell sprite
    sf::Texture greenCellTexture;
    if (!greenCellTexture.loadFromFile("greenCell.gif"))
    {   return EXIT_FAILURE;    }                //exits game if file cannot be found
    sf::Sprite greenCell(greenCellTexture);

    sf::Texture menuBlockTexture;
    if (!menuBlockTexture.loadFromFile("menuBlock.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite menuBlock(menuBlockTexture);

    sf::Texture pauseTexture;
    if (!pauseTexture.loadFromFile("pause.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite pause(pauseTexture);

    sf::Texture optionsTexture;
    if (!optionsTexture.loadFromFile("options.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite options(optionsTexture);

    sf::Texture pauseScreenTexture;
    if (!pauseScreenTexture.loadFromFile("pauseScreen.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite pauseScreen(pauseScreenTexture);

    sf::Texture pauseChartObjTexture;
    if (!pauseChartObjTexture.loadFromFile("pauseChartObj.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite pauseChartObj(pauseChartObjTexture);

    sf::Texture playTexture;
    if (!playTexture.loadFromFile("play.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite play(playTexture);

    sf::Texture cellHolderTexture;
    if (!cellHolderTexture.loadFromFile("cellHolder.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite cellHolder(cellHolderTexture);

    sf::Texture destinationBlockTexture;
    if (!destinationBlockTexture.loadFromFile("destinations.gif"))
    {   return EXIT_FAILURE;    }


}
