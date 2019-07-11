#include<ctime>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<iostream>
#include<windows.h>

using namespace std;

int x = 8, y = 8;
int key, dir = 2, gamestate = 1, score, t;

string name;
string map[110] = {
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  ",
    "                                                  "
};

void output(void) {
    string out;
    system("cls");
    for(int j = 0; j < 50; ++j) {
    	out += 'W';
	}
    out += '\n';
    for(int i = 1; i <= 19; ++i) {
        for(int j = 0; j < map[i].length(); ++j){
            if(i != x + 2 || j != y) {
            	out += map[i][j];
			}
            else {
            	out+='O';
			}
        }
        out += '\n';  
    }
    for(int j = 0; j < 50; j++) {
    	out+='M';
	}
    out += '\n';
    cout << out;
    cout << "Score:" << score << endl;
}

int main(void) {
    srand(time(NULL));
    system("cls");
    cout << "Enter your name:";
    cin >> name;
    cout << "Welcome," << name << "!" << endl;
    Sleep(1000);
    for(int i = 0; i < 100; ++i) {
        system("cls");
        cout << "loading..." << endl;
        for(int j = i; j > 0; j -= 5){
            cout << "-";
        }
        cout << endl << i << "%" << endl;
        Sleep(25);
    }
    system("cls");
    while(gamestate) {
        dir = 2;
        for(int times = 0; times < 20; times++){
            Sleep(5);
            if(_kbhit()) {
                key = _getch();
                if(key == 'w') {
                	dir = 1;
				}
            }
        }
        if(dir == 2) {
        	++x;
		}
        else {
        	--x;
		}
        for(int i = 1; i <= 19; ++i) {
            for(int j = 0; j < map[i].length() - 1; ++j) {
                if(map[i][j + 1] == '|') {
                    map[i][j]     = '|';
                    map[i][j + 1] = ' ';
                }
            }
        }
        for(int i = 1; i <= 19; ++i) {
            map[i][0] = ' ';
        }
        if(t % 20 == 0) {
            int event = rand() % 17 + 1;
            for(int i = 1; i < event; i++) {
            	map[i][49] = '|';
			}
            for(int j = event + 3; j <= 19; j++) {
            	map[j][49] = '|';
			}
        }
        if(x > 17 || x < -1 || map[x + 2][y] == '|') {
        	gamestate=0;
		}
        output();
        if(gamestate == 1 && t % 20 == 1 && t > 30) {
        	++score;
		}
        ++t;
    }
    system("cls");
    cout << "Game over!" << endl;
    cout << "Score:" << score << endl;
    cout << "Press space to exit" << endl;
    while(1) {
        while(!_kbhit()) {
            Sleep(10);
        }
        int overkey = _getch();
        if(overkey == 32) {
        	break;
		}
    }
    return 0;
}
