//
//  main.cpp
//  Random
//
//  Created by 손현기 on 2018. 5. 28..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "BattleShipApp.h"

using namespace std;

class Make {
private:
    int check_arr[8][8]={{0}};
public:
    void Select_position(int arr_size, int left[], int right[], int c_arr[][8]) {

        int left_value;
        int right_value;

        for (int i = 0; i < arr_size; i++) {
            left_value = left[i];
            right_value = right[i];
            c_arr[left_value][right_value] = 1;
        }
    }

    bool Boundary(int x, int y) {
        bool flag = true;
        if (x > 7 || x < 0 || y > 7 || y < 0) {
            flag = false;
        }
        return flag;
    }

    int Random_select_position(int le, int ri, int dir, int size) {
        int result = -1;
        int count = 0;
        int left_data[size];
        int right_data[size];
        int flag = 0;

        if (dir == 0) { // 북
            if (check_arr[le][ri] == 1 || Boundary(le, ri) == false) {
                return result;
            } else {
                left_data[count] = le;
                right_data[count] = ri;
                count++;

                for (int i = 0; i < size; i++) {
                    le = le - 1;
                    if (check_arr[le][ri] != 1 && Boundary(le, ri) == true) {
                        left_data[count] = le;
                        right_data[count] = ri;
                        count++;
                    } else {
                        flag = -1;
                        break;
                    }
                }
                if (flag == 0) {
                    Select_position(size, left_data, right_data, check_arr);
                    result = 0;
                }

            }
        } else if (dir == 1) { // 동

            if (check_arr[le][ri] == 1 || Boundary(le, ri) == false) {
                return result;
            } else {
                left_data[count] = le;
                right_data[count] = ri;
                count++;
                for (int i = 0; i < size; i++) {
                    ri = ri + 1;
                    if (check_arr[le][ri] != 1 && Boundary(le, ri) == true) {
                        left_data[count] = le;
                        right_data[count] = ri;
                        count++;
                    } else {
                        flag = -1;
                        break;
                    }
                }
                if (flag == 0) {
                    Select_position(size, left_data, right_data, check_arr);
                    result = 0;
                }
            }

        } else if (dir == 2) { // 남

            if (check_arr[le][ri] == 1 || Boundary(le, ri) == false) {
                return result;
            } else {
                left_data[count] = le;
                right_data[count] = ri;
                count++;
                for (int i = 0; i < size; i++) {
                    le = le + 1;
                    if (check_arr[le][ri] != 1 && Boundary(le, ri) == true) {
                        left_data[count] = le;
                        right_data[count] = ri;
                        count++;
                    } else {
                        flag = -1;
                        break;
                    }
                }
                if (flag == 0) {
                    Select_position(size, left_data, right_data, check_arr);
                    result = 0;
                }
            }

        } else if (dir == 3) {//서

            if (check_arr[le][ri] == 1 || Boundary(le, ri) == false) {
                return result;
            } else {
                left_data[count] = le;
                right_data[count] = ri;
                count++;
                for (int i = 0; i < size; i++) {
                    ri = ri - 1;
                    if (check_arr[le][ri] != 1 && Boundary(le, ri) == true) {
                        left_data[count] = le;
                        right_data[count] = ri;
                        count++;
                    } else {
                        flag = -1;
                        break;
                    }
                }
                if (flag == 0) {
                    Select_position(size, left_data, right_data, check_arr);
                    result = 0;
                }
            }
        }


        return result;

    }

    void Print_arr() {
        for (int i = 0; i < 8; i++) {
            for (int i2 = 0; i2 < 8; i2++) {
                cout << check_arr[i][i2] << " ";
            }
            cout << "\n";
        }
    }


};


int main(int argc, const char *argv[]) {
    // insert code here...
    srand((unsigned int) time(NULL));
    int direction = -1;
    int left, right;

    Make mg;

    int size1[5] = {5,4,3,2,2};
    int size_count = 0;


    while (1) {
        left = rand() % 8;
        right = rand() % 8;
        direction = rand() % 4;

        if (size_count > 4) {
            break;
        } else {
            if (mg.Random_select_position(left, right, direction, size1[size_count]) == 0) {
                size_count++;
            }
        }
    }

    mg.Print_arr();

    CBattleShipApp battleShipApp;
    battleShipApp.play();

    std::cout << "Hello, World!\n";
    return 0;
}
