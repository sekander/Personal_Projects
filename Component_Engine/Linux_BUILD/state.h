#pragma once

//Abstract class

class State{
public:
    virtual void Init() = 0;

    virtual void Input(float delta) = 0;
    virtual void Update(float delta) = 0;

    virtual void Render(float delta) = 0;

    virtual void DeleteData() = 0;

};
