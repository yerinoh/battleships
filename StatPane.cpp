//
//  StatPane.cpp
//  BattleShip_v1
//
//  Created by 손현기 on 2018. 5. 24..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include "StatPane.h"
#include <vector>
#include <string>

StatPane::StatPane(int x, int y, int width, int height)
        : Pane(x, y, width, height) {
    mvwprintw(m_pWindow, 0, 3, "< STATUS >");
    mvwprintw(m_pWindow, 5, 2, "Turn : ");
}

void StatPane::Draw(int number) {

    wattron(m_pWindow, COLOR_PAIR(2));
    const char* v[] = {"AIRCRAFT : AAAAA", "BATTLESHIP : BBBB", "CRUISER : CCC", "DESTROYER : DD DD"};
    int i = 1;
    for (int j = 0; j < 4; ++j) {
        if (i & number) {
            wattron(m_pWindow, COLOR_PAIR(4));
        }

        mvwprintw(m_pWindow, j + 1, 2, v[j]);
        if (i & number) {
            wattron(m_pWindow, COLOR_PAIR(2));
        }
        i *= 2;
    }
//
//    mvwprintw(m_pWindow, 2, 2, "BATTLESHIP : BBBB");
//    mvwprintw(m_pWindow, 3, 2, "CRUISER : CCC");
//    mvwprintw(m_pWindow, 4, 2, "DESTROYER : DD DD");

    wrefresh(m_pWindow);

}

