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
- ```int getScreenWidth()```: Get screen width.
- ```int getScreenHeight()```: Get screen height.
- ```float getCameraWidth()```: Get camera width in World.
- ```float getCameraHeight()```: Get camera height in World.
- ```v2f SetCenter(v2f position)```: Set camera center position.
- ```float Resize(float newSize, v2f pivot)```: Resize camera to "newSize" in pivot "pivot"
- ```v2f WorldToScreenPoint(v2f point)```: Get Screen point from a World point.
- ```v2f ScreenToWorldPoint(v2f point)```: Get World point from a Screen point.

### Renderer
One of basic tools, access by ```mia::_Renderer()```. </br>
- ```void RegisterPortrait(Portrait *portrait)```: Register Portrait to render.
- ```void UnregisterPortrait(Portrait *portrait)```: UnRegister Portrait from render.
- ```void RegisterImage(Image *image)```: Register Image to render.
- ```void UnregisterImage(Image *image)```: UnRegister Image from render.
- ```void RegisterTilemap(Tilemap *tilemap)```: Register Tilemap to render.
- ```void UnregisterTilemap(Tilemap *tilemap)```: UnRegister Tilemap from render.
- ```void RenderBodiesCollision(bool state)```: Enable Render Bodies collision (or not).

## Things I could do better
*this is like a place where I confess my sins when I was working on the project* </br>
- Error handling and debugging system. *(this engine has done so poorly on debug and error handling so I think this is literally unusable by anyone else except me)*
- Use less pointer and heap allocation to store things. *(heap allocation allow many powerful thing but also the pain in the ass when come down to error handling)*
- Use less OOP approach while I can use something simpler.
- Use fewer get/set functions and some weird way to access an object's attributes. *(this is like the result of 2 thing above, I tried to use pointer stuff but also want to prevent error so I came up with the weirdest thing humanity can possibly came up with)*
- More clear on ownership *(this engine has no clear on ownerships, this might also the result of overuse heap allocation and transfer parameters as pointer)*

*time to do another one*