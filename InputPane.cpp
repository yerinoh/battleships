//
// Created by user on 18. 5. 28.
//

#include "InputPane.h"

InputPane::InputPane(int x, int y, int width, int height)
        : Pane(x, y, width, height) {
    mvwprintw(m_pWindow, 0, 3, "< INPUT >");
}

void InputPane::Draw() {
    wattron(m_pWindow, COLOR_PAIR(3));
    mvwprintw(m_pWindow, 1, 2, "Input position...(ex A 3)");
    mvwprintw(m_pWindow, 2, 2, "Input : ");
    mvwprintw(m_pWindow, 3, 2, "Result : ");

    wrefresh(m_pWindow);

}