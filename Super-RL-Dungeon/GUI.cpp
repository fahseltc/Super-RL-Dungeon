#include "GUI.h"
#include "engine.h"


static const int PANEL_HEIGHT = 3;
static const int BAR_WIDTH = 20;

GUI::GUI()
{
    con = new TCODConsole(Engine::kGlobalWidth, PANEL_HEIGHT);
}

GUI::~GUI()
{
    delete con;
}

void GUI::render()
{
    // clear the GUI console
    con->setDefaultBackground(TCODColor::black);
    con->clear();

    // draw the health bar
    renderBar(1, 1, BAR_WIDTH, "HP", 3,
        10,
        TCODColor::lightRed, TCODColor::darkerRed);


    // blit the GUI console on the root console
    TCODConsole::blit(con, 0, 0, Engine::kGlobalWidth, PANEL_HEIGHT,
        TCODConsole::root, 0, 0);

}


void GUI::renderBar(int x, int y, int width, const char *name,
    float value, float maxValue, const TCODColor &barColor,
    const TCODColor &backColor) {

    // fill the background
    con->setDefaultBackground(backColor);
    con->rect(x, y, width, 1, false, TCOD_BKGND_SET);

    int barWidth = (int)(value / maxValue * width);
    if (barWidth > 0) {
        // draw the bar
        con->setDefaultBackground(barColor);
        con->rect(x, y, barWidth, 1, false, TCOD_BKGND_SET);
    }

    // print text on top of the bar
    con->setDefaultForeground(TCODColor::white);
    con->printEx(x + width / 2, y, TCOD_BKGND_NONE, TCOD_CENTER,
        "%s : %g/%g", name, value, maxValue);
}

