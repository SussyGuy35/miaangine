# MIAANGINE
A simple 2D AABB based GameEngine using SDL C++ run in WIndows.

------------



## Disclaimer
The engine still not yet finished, it lack a lot of feature </br>
I will definitely re-do a new one </br>
*but like for real, i'm really suprised if you can use this abomination*

## Getting Started
```#include "miaangine.hpp"``` to use all the features or import specify any file depending on your needs. </br>
All engine components are in the ```mia``` namespace.

## Features
- Custom SDL window.
- Object-based engine.
- Camera system - World position.
- Input system.
- Events system.
- AABB-based physics.
- Audio support.

## Basics
### Tools
The engine mostly use function to access object. </br>
The engine contains some basic tools:
- Game: Handle some basic SDL stuff and contain some generic function for the engine.
- Input: Handle the inputs.
- Time: Handle time of the engine.
- Events: Handle events callback system.
- Camera: World Camera.
- Renderer: Manage the engine's rendering.
- Physics: Manage the engine's physics.
- SpriteHandler: Help make *Sprite. 

</br>You can use all the tools by ```mia::_<name-of-tool>()```.
### Concept
- Screen: is the plane of the program screen, the real plane where things are rendered out.
- World: a plane/layout which is separated from Screen, related with Screen through Camera

## Entry point 
*Make sure to import the necessary header*

### Init
Go to the ```common.hpp``` file and change the const variables for your usage. </br>
*this is so bad but I don't want to redo it anymore*

### Windows
```mia::_Game().InitWindow()``` to make the SDL program. </br>
```mia::_Game().ClearWindow()``` to clear the SDL program.

### Game loop
Make a simple ```while(true)``` loop and use ```mia::_Game().Update()``` to tell the engine update. </br>
Use ```mia::_Game().Render()"``` to render. </br>
Use ```if (mia::_Input().isQuit()) break;``` break out of the loop if user quit the window.

### Summary
Together, you might have something like this as a entry point:
```
mia::_Game().InitWindow();
while (true)
{
	mia::_Game().Update();
	
	// Game logic here
	
	 if (mia::_Input().isQuit()) break;
	mia::_Game().Render();
}
mia::_Game().ClearWindow();
```

## API
The engine mostly use function to access object attributes.

### Utilities
The engine contain some utilities.

#### Vector (2D)
Vector have 3 variant are ```v2f```; ```v2i```; ```v2d``` which contain difference type of "x, y". ```v2f``` for "float"; ```v2i``` for "int"; ```v2d``` for "double". </br>
Besides basic operator, it also have ```magnitude()```, ```normalize()```.

#### String
Just a lighter, simpler version of ```std::string```.

#### Mask
A 32-bit bitmask 
- ```insert(int pos)```: Insert bit to "pos".
- ```remove(int pos)```: Remove bit in "pos".
- ```query(int pos)```: Check if a bit in "pos".
- ```count()```: Return number of bit in mask.
- ```get()```: Return the mask as int.

#### Rect
A rectangle data. 
- ```v2f pos```: position
- ```v2f siz```: size
- ```rect(v2f pos, v2f siz)```: Init a rect with pos and siz.
- ```bool contain(v2f point)```: Check if contain a point.
- ```bool contain(rect other)```: Check if contain a rect.
- ```bool overlap(rect other)```: Check if overlap other rect.

#### Singleton
Inheritance this class to make the class become singleton
```
class <target-class> : public Singleton<<target-class>>
```
Remember to private the constructor and add friend class to Singleton.
```
private:
friend class Singleton<<target-class>>
```

### Object*

#### Object
The main working ...object existing on World.
- string name.
- v2f position.
- Portrait *portrait: Portrait component.
- Body *body: Body component

#### UI
The main object existing on Screen.
- string name.
- v2f position.
- Image *image: Image component

### Component

#### Portrait
An Object's component, is the way to render object.
- Sprite *sprite.
- v2f pivot.
- v2f offset.
- SDL_Color color.
- ```Portrait(Object *master, ...)```: Constructor a Portait attach to "master".
- ```Object ChangeMaster(Object *other)```: Set new master.
- ```rect GetRect()```: Get the rect of Portrait.

#### Body
An Object's component, is the way to render object.
- BodyType type: have 2 type _BODY_STATIC and _BODY_DYNAMIC.
- v2f size.
- v2f pivot.
- v2f offset.
- v2f velocity.
- ```Body(Object *master, ...)```: Constructor a Portait attach to "master".
- ```Object ChangeMaster(Object *other)```: Set new master.
- ```rect GetRect()```: Get the rect of Body.
- ```AddForce(v2f value)```: Add force.
- ```AddAcceleration(v2f value)```: Add acceleration.

#### Image
An UI's component, is the way to render UI.
- Sprite *sprite.
- v2f pivot.
- v2f offset.
- SDL_Color color.
- ```Image(UI *master, ...)```: Constructor a Image attach to "master".
- ```Object ChangeMaster(Object *other)```: Set new master.
- ```rect GetRect()```: Get the rect of Image.

### Game
One of basic tools, access by ```mia::_Game()```. </br>
- ```int InitWindow()```: Init SDL program according to ```common.hpp```.
- ```int ClearWindow()```: Clear SDL program.
- ```int Update()```: Update game.
- ```int Render()```: Render game.

### Input
One of basic tools, access by ```mia::_Input()```. </br>
- ```void Update()```: Update/Register input.
- ```bool getKey(int key)```: Check if "key" is holding.
- ```bool getKeyDown(int key)```: Check if "key" is pressed in the last update.
- ```bool getKeyUp(int key)```: Check if "key" is released in the last update.
- ```v2f getMousePosition()```: Get the mouse position in the last update.
- ```bool isQuit()```: Check if user quit the program.

### Time
One of basic tools, access by ```mia::_Time()```. </br>
- ```void Step()```: Update time clock.
- ```double deltaTime()```: Get the delta time between 2 update.
- ```float fps()```: Get the current FPS.
- ```double time()```: Get the current time (in seconds).
- ```uint64_t stepCount()```: Get the ammount of update.

### Camera
*Like above, Camera is the one define how thing on World should be considered in Screen.* </br>
One of basic tools, access by ```mia::_Camera()```. </br>