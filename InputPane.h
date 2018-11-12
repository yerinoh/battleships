//c++ BattleShip 프로젝트
//작성 일자 : 2018-06-02
//학번 : 20171636 이름 : 손현기

#pragma once

#include "Pane.h"

class InputPane : public Pane {
public:
    friend class CBattleShipApp;
    InputPane(int x, int y, int width, int height);

    virtual void Draw();
};
