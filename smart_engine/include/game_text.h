#include <stdio.h>
#include <iostream>

class game_text{

public:
    game_text(std::string text, float pos_x, float pos_y, float scale, 
                               float color_r, float color_g, float color_b){

                                _text = text;
                                _pos_x = pos_x;
                                _pos_y = pos_y;
                                _scale = scale;
                                _color_r = color_r;
                                _color_g = color_g;
                                _color_b = color_b;


                  }
    ~game_text(){}

    //std::vector<game_text*> xml_text_package;

    //const char* _text;
    std::string _text;
    float _pos_x;
    float _pos_y;
    float _scale;
    float _color_r;
    float _color_g;
    float _color_b;
private:
};
