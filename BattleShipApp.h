//c++ BattleShip 프로젝트
//작성 일자 : 2018-06-02
//학번 : 20171636 이름 : 손현기


#pragma once

#include "StatPane.h"
#include "InputPane.h"
#include "BattleShipMap.h"

class CBattleShipApp {
public:

    void play();

protected:
    void Init();

    void Render();

    void Destroy();

protected:
    CBattleShipMap *m_pMap;
    CBattleShipMap *m_pMap2;
    StatPane *m_pStatPane;
    InputPane *m_pInputPane;
};
