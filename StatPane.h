//c++ BattleShip 프로젝트
//작성 일자 : 2018-06-02
//학번 : 20171636 이름 : 손현기

#pragma once
#include <stdio.h>
#include "Pane.h"

class StatPane : public Pane {
public:
   friend class CBattleShipApp; 
   StatPane(int x, int y, int width, int height);

    virtual void Draw(int number = 0);
};
