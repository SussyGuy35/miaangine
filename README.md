# MIAANGINE - PROJECT
- [GAME - BunTheBunny](#game---bunthebunny)
- [Miaangine](#miaangine)

------------
------------

# GAME - BunTheBunny

## Table of Contents
- [Demo](#demo)
- [Disclaimer](#disclaimer)
- [General](#general)
- [Mechanic](#mechanic)
  - [Player](#player)
    - [Movement system](#movement-system)
    - [Store velocity system](#store-velocity-system)
    - [Dash system](#dash-system)
    - [Wall jump system](#wall-jump-system)
  - [Special](#special)
- [Obstacles/Buff](#obstaclesbuff)
  - [Spike](#spike)
  - [Spring](#spring)
  - [Surfboard](#surfboard)
  - [Speedbuff](#speedbuff)
  - [Score](#score)
- [Source](#source)

## Demo
- Download Demo: [https://drive.google.com/file/d/1uVFAW6RbYmwjxG1NOEa0GxsbpG5UAtMT/view?usp=sharing](https://drive.google.com/file/d/1uVFAW6RbYmwjxG1NOEa0GxsbpG5UAtMT/view?usp=sharing)
- Video Demo: [https://youtu.be/Qe25e_3YVuw](https://youtu.be/Qe25e_3YVuw)

## Disclaimer
I already done this game demo ([here](https://krakra.itch.io/bunthebunny)) using Unity, so this is a port to SDL C++.

## General
BunTheBunny is a platformer 2D game.

## Mechanic

### Player

#### Movement system
*This might tight up with the engine physics system*
- Move around by *arrow keys*.
- Have distinct movement acceleration and decceleration based on current player movement and state.
	+ Acceleration and Decceleration here means how fast the player can reach the desired speed.
	+ Fully customizable.
- Jump using ```C``` button.
- Jumping having quite a bit of helper:
	+ Coyote time: Allow player to jump even after left the ground for a bit of time.
	+ Jump buffer: Allow player to jump when touch the ground even player input the jump a bit sooner than expected.
	+ Purpose: For better controlling player.

#### Store velocity system
- Player can store the velocity.
- **store velocity** might be use in difference way.
	+ Run.
	+ Take the power up.
	+ Use obstacles.

#### Dash system
- Dash by ```X```.
- Player will dash in the direction of *arrow keys*.
- Dash will use **store velocity**, which mean more **store velocity** the faster player dash.

#### Wall jump system
- Wall jump by ```C``` when near the Wall.
- Wall jump also use **store velocity** as additional velocity to the jump.

### Special
- For better feeling on dashing, the first few ticks of the dash, player actually move many times **store velocity** fast.
- Because of the above, player can cancel the dash by jump or wall jump and take advantage of the fast velocity in start of the dash and perform a super far jump, this might call **jump dash cancel**. *(The easiest way to excute this is by move in a flat surface and press ```X``` -> ```C```)*

## Obstacles/Buff

### Spike
- Simply kill (reset level) when player touched.

### Spring
- Transfer all player velocity to upward velocity and a bit more addition.
- Add a bit velocity to player **store velocity**.

### Surfboard
- Transfer all player velocity to horizontal velocity and a bit more addition.
- Add a bit velocity to player **store velocity**.

### Speedbuff
- Temporary increase player movement speed.

### Score
- Final score of a level calculated by:
	+ Time to complete.
	+ Final speed.
	+ Max speed.

## Source
- All code by me.
- Art by [WibuKa](https://github.com/WibuKa)
- All sound, music by me.
</br>
  more clear, WibuKa and I work on the [game]([here](https://krakra.itch.io/bunthebunny)) for a GameJam, the art asset made by WibuKa on that project and in this project, i modified it a bit and the music once was made by other but I made the music for this project*

------------

# MIAANGINE
A simple 2D AABB based GameEngine using SDL C++ run in WIndows.

## Table of Contents
- [Disclaimer](#disclaimer)
- [Getting Started](#getting-started)
- [Features](#features)
- [Basics](#basics)
  - [Tools](#tools)
  - [Concept](#concept)
- [Entry point](#entry-point)
  - [Init](#init)
  - [Windows](#windows)
  - [Game loop](#game-loop)
  - [Summary](#summary)
- [Mechanic](#mechanic)
  - [Event system](#event-system)
  - [Physics](#physics)
  - [API](#api)
- [Utilities](#utilities)
  - [Vector (2D)](#vector-2d)
  - [String](#string)
  - [Mask](#mask)
  - [Rect](#rect)
  - [Singleton](#singleton)
- [Object*](#object)
  - [Object](#object)
  - [UI](#ui)
  - [Observer](#observer)
  - [Tilemap](#tilemap)
- [Component](#component)
  - [Portrait](#portrait)
  - [Body](#body)
  - [Image](#image)
- [Game](#game)
- [Input](#input)
- [Time](#time)
- [Camera](#camera)
- [Event](#event)
- [Renderer](#renderer)
- [Physics](#physics-1)
- [Other](#other)
  - [Clip](#clip)
  - [TilemapPalette](#tilemappalette)
- [Things I could do better](#things-i-could-do-better)

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

## Mechanic

### Event system
Observer design pattern.

### Physics
Arbitrary AABB Collision.

### *and many thing more*

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

#### Observer
The observer of the event system.
- ```void Update(int message)```: This will be called if the event it registered call, "message" corresponding the event.

#### Tilemap
it work

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

### Event
One of basic tools, access by ```mia::_Events()```. </br>
- ```RegisterObserver(Observer *observer)```.
- ```RemoveObserver(Observer *observer)```.
- ```Notify(int message)```: Notify the registered observer with the "message".

### Renderer
One of basic tools, access by ```mia::_Renderer()```. </br>
- ```void RegisterPortrait(Portrait *portrait)```: Register Portrait to render.
- ```void UnregisterPortrait(Portrait *portrait)```: UnRegister Portrait from render.
- ```void RegisterImage(Image *image)```: Register Image to render.
- ```void UnregisterImage(Image *image)```: UnRegister Image from render.
- ```void RegisterTilemap(Tilemap *tilemap)```: Register Tilemap to render.
- ```void UnregisterTilemap(Tilemap *tilemap)```: UnRegister Tilemap from render.
- ```void RenderBodiesCollision(bool state)```: Enable Render Bodies collision (or not).

### Physics
One of basic tools, access by ```mia::_Physics()```.
- ```void RegisterBody(Body *Body)```: Register Body collision, dynamic handle.
- ```void UnregisterBody(Body *Body)```: UnRegister Body collision, dynamic handle.
- ```void RegisterTilemap(Tilemap *tilemap)```: Register Tilemap collision.
- ```void UnregisterTilemap(Tilemap *tilemap)```: UnRegister Tilemap collision.
- ```bool Query(rect rect)```: return if there's STATIC body in area "rect"
- ```bool RaycastRect(v2f origin, v2f velocity, rect target, double &timeHit, v2f &hitPoint, v2f &normal)```: Cast a ray in "origin" to direction "velocity", distance "velocity" magnitude with the target "target", return if the ray hit, and output:
	+ ```timeHit```: return time need to hit the target (scale in "velocity")
	+ ```hitPoint```: return hit point.
	+ ```normal```: return normal vector of the hit.

### Other

#### Clip 
A container manager multiple sprite.

#### TilemapPalette
A container contain sprites to be used as data for Tilemap.

## Things I could do better
*this is like a place where I confess my sins when I was working on the project* </br>
- Error handling and debugging system. *(this engine has done so poorly on debug and error handling so I think this is literally unusable by anyone else except me)*
- Use less pointer and heap allocation to store things. *(heap allocation allow many powerful thing but also the pain in the ass when come down to error handling)*
- Use less OOP approach while I can use something simpler.
- Use fewer get/set functions and some weird way to access an object's attributes. *(this is like the result of 2 thing above, I tried to use pointer stuff but also want to prevent error so I came up with the weirdest thing humanity can possibly came up with)*
- More clear on ownership *(this engine has no clear on ownerships, this might also the result of overuse heap allocation and transfer parameters as pointer)*

*time to do another one*
