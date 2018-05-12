sf::Text displayTextOnScreen(int x, int y, std::string input)
{
    sf::Text text;
    std::stringstream textStringStream;
    std::string textString;
 	textStringStream << input;
    textString = textStringStream.str();
    text.setString(textString);
    text.setCharacterSize(16);
    text.setPosition(x,y);
    text.setColor(sf::Color::Red);
    text.setFont(gameFont);
    textStringStream.str("");
    return text;
}
