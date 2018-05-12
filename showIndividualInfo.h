
void showIndividualInfo(int energy, int evpoints, int pop)
{
    textStringStream << "This Individual's Energy: " << energy;
    textString = textStringStream.str();
    text.setString(textString);
    text.setCharacterSize(16);
    text.setPosition(80,656);
    text.setColor(sf::Color::Red);
    text.setFont(gameFont);
    app.draw(text);
    textStringStream.str("");

    textStringStream << "Evolution Points for this Species: " << evpoints;
    textString = textStringStream.str();
    text.setString(textString);
    text.setCharacterSize(16);
    text.setPosition(80,672);
    text.setColor(sf::Color::Red);
    text.setFont(gameFont);
    app.draw(text);
    textStringStream.str("");

    textStringStream << "Population for this Species: " << pop;
    textString = textStringStream.str();
    text.setString(textString);
    text.setCharacterSize(16);
    text.setPosition(80,688);
    text.setColor(sf::Color::Red);
    text.setFont(gameFont);
    app.draw(text);
    textStringStream.str("");
}
