# MIAANGINE

## Overview
Miaangine is a simple, lightweight 2D game engine using C++ SDL2 by Miaan. <br>
The engine can work on Windows and Linux

## Demo
Use CMake to build the CMakeLists.txt:
```bash
mkdir build
cd build
cmake ..
```
Then you can compile and run game.exe to run the demo

## Getting Started
Copy "src/miaangine/" folder from the source code and paste it wherever in your project <br> 
Then you can import "miaangine.hpp" to use all the features or import specify any file depending on your needs

## Features
- Custom SDL window
- Render 2D rectangle
- Input system
- Game loop events
- AABB-based physic engine

## Tutorial
*Make sure to import the necessary header* <br>
**This toturial litterally outdated after a day :P** 

### Init/End program
Use ```mia::Init()``` to make the SDL window
```c
mia::Init(uint32_t width, uint32_t height, bool fullscreen)
```
Use ```mia::End()``` to exit program

### Game loop
Make a simple ```while(true)``` loop and use ```mia::NewFrame()``` to tell the engine run a new frame
```c
while (true)
{
    mia::NewFrame();

    // Game logic here
}
```
After this, every game object will have its game loop (more detail below)

### Game object
Create your class then inherit ```WorldObject```, then implant the method ```void Update(uint8_t message)```
```c
#include "miaangine.hpp"

class MyObject : public mia::WorldObject
{
public:
    MyObject():
        WorldObject("Name of my object")
    {}

    void Update(uint8_t message) override;

};
```

### Event system
*Miaangine uses event publisher system to notify each game object and you can freely custom it* <br>
Use ```mia::events->[event publisher]->RegisterListener([object])``` to register object to a event publisher <br>
Then the method ```Update(uint8_t message)``` in every game object is registered will be automatically called with a different ```uint8_t message``` based on the event 
```c
MyObject():
    WorldObject("Name of my object")
{
    mia::events->primaryUpdate->RegisterListener(this);
}
```
```c
void MyObject::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        // Game logic here

        break;
    
    default:
        break;
    }
}
```
There are built-in events: (format of this part: - [event publisher name] <[the event message]> : [the event description]) <br>
- onEnterNewFrame <_EVENT_ON_ENTER_FRAME> : notify whenever a new frame runs, this event will notify before any calculation in that frame
- primaryUpdate <_EVENT_PRIMARY_UPDATE> : notify every frame, after calculating the timer and receiving input but before calculating the physic

*you can see the usage of the event system by looking at the demo*

### Rendering
*Miaangine currently just support rendering 2D rectangle* <br> 
Make a portrait (render image) inside a ```WorldObject``` by method ```MakePortrait()```
```c
MyObject():
    WorldObject("Name of my object")
{
    MakePortrait(size, offset)
}

```
Then you can use ```portrait()``` to access the portrait of an object <br>
*You can add multiple portraits to one object and use ```portrait(int index)``` to access to them* <br>
Use ```RegisterPortrait()``` to register the portrait to the renderer
```c
MyObject():
    WorldObject("Name of my object")
{
    MakePortrait(size, offset)
    mia::portraitRenderer->RegisterPortrait(portrait());
}
```
*You can also make a stand-alone Portrait by ```new Portrait()``` but I recomment using GameObject::MakePortrait()*

### Physics
**Miaangine physics only supports AABB** <br>
Similar to the portrait, make a body by ```MakeBody()```, access it by ```body()```, then use ```RegisterBody()``` to register the body to the physics world (also support multiple body in one object)
```c
MyObject():
    WorldObject("Name of my object")
{
    MakeBody(size, offset)
    mia::physicWorld->RegisterBody(body());
}
```
