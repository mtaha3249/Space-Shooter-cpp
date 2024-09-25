# Space Shooter cpp
 

<table><tr><th><b><i>Class Name</i></b></th><th valign="top"><b><i>Function Name</i></b></th><th valign="top"><b><i>Class/Function Description</i></b></th></tr>
<tr><td colspan="3"><b><i>LAYER 1</i></b></td></tr>
<tr><td><b><i>Game.cpp</i></b></td><td colspan="2" valign="top">Main class, entry point of the engine. Initialize and update engine class</td></tr>
<tr><td colspan="3"><b><i>LAYER 2</i></b></td></tr>
<tr><td rowspan="6"><b><i>Engine.cpp</i></b></td><td colspan="2" valign="top">A wrapper for the whole game engine combine multiple classes like Input, GameManager and SDL</td></tr>
<tr><td valign="top"><i>Init()</i></td><td valign="top">Start the rendering of the SDL and initialize the gameobjects from GameManager</td></tr>
<tr><td valign="top"><i>Update()</i></td><td valign="top">Update all gameobjects assigned in the GameManager</td></tr>
<tr><td valign="top"><i>Sdlevent()</i></td><td valign="top">Detect Input and raise event for the Input</td></tr>
<tr><td valign="top"><i>Render()</i></td><td valign="top">Clear the old render and draw a fresh instance of the gameobjects</td></tr>
<tr><td valign="top"><i>Clean()</i></td><td valign="top">Clear the SDL data</td></tr>
<tr><td rowspan="2"><p><b><i>GameManager.cpp</i></b></p><p><b><i>(Singleton)</i></b></p></td><td colspan="2" valign="top">have all the world gameobjects</td></tr>
<tr><td valign="top"><i>Init()</i></td><td valign="top">Initialize the gameobjects and cache in the world object vector</td></tr>
<tr><td rowspan="3"><b><i>InputListener.h</i></b></td><td colspan="2" valign="top">have virtual function of keydown and keyup</td></tr>
<tr><td valign="top"><i>KeyDown()</i></td><td valign="top">calls when key is down</td></tr>
<tr><td valign="top"><i>KeyUp()</i></td><td valign="top">calls when key is up</td></tr>
<tr><td rowspan="4"><p><b><i>InputSystem.cpp</i></b></p><p><b><i>(Singleton)</i></b></p></td><td colspan="2" valign="top">Raise, bind and remove listeners</td></tr>
<tr><td valign="top"><i>RaiseEvent()</i></td><td valign="top">raise event and call the listener bind</td></tr>
<tr><td valign="top"><i>addListener()</i></td><td valign="top">Registering listener</td></tr>
<tr><td valign="top"><i>removeListener()</i></td><td valign="top">Unregister listener</td></tr>
<tr><td rowspan="4"><b><i>TextureManager.cpp</i></b></td><td colspan="2" valign="top">This class is basically a separate module, whose responsibility is to render the texture</td></tr>
<tr><td valign="top"><i>LoadTexture()</i></td><td valign="top">Load texture with the file path</td></tr>
<tr><td valign="top"><i>LoadTexture()</i></td><td valign="top">Load the given texture, loading should be done manually from the file</td></tr>
<tr><td valign="top"><i>LoadFile()</i></td><td valign="top">Load file</td></tr>
<tr><td><b><i>Physics.cpp (Singleton)</i></b></td><td colspan="2" valign="top">Contains information of physics, like gravity, optimized value for velocity iteration and position iteration</td></tr>
<tr><td><b><i>EngineTime.cpp</i></b></td><td colspan="2" valign="top">Contains the time information like delta time, FPS, frame time etc</td></tr>
<tr><td colspan="3"><b><i>LAYER 3</i></b></td></tr>
<tr><td><b><i>Vector2.cpp</i></b></td><td colspan="2" valign="top">A vector2 struct with the overload operators</td></tr>
<tr><td><b><i>Transform.cpp</i></b></td><td colspan="2" valign="top">A class consists of position, rotation and scale as a vector2</td></tr>
<tr><td><b><i>Rigidbody.cpp</i></b></td><td colspan="2" valign="top">Create rigidbody for the multiple overload constructor and register it to the box2d via physics class having the information of physics world</td></tr>
<tr><td rowspan="3"><b><i>GameObject.cpp</i></b></td><td colspan="2" valign="top">A class with the virtual function of Draw and Update</td></tr>
<tr><td valign="top"><i>Draw()</i></td><td valign="top">Implemented to the gameobject implementer for the draw</td></tr>
<tr><td valign="top"><i>Update()</i></td><td valign="top">Implemented to the gameobject implementer for the update of the gameobject</td></tr>
<tr><td rowspan="3"><b><i>Collider.cpp</i></b></td><td colspan="2" valign="top">A class having 2 virtual functions for the Init and CheckCollision</td></tr>
<tr><td valign="top"><i>Init()</i></td><td valign="top">Initialize the collider for the object</td></tr>
<tr><td valign="top"><i>CheckCollision()</i></td><td valign="top">TODO</td></tr>
<tr><td colspan="3"><b><i>LAYER 4</i></b></td></tr>
<tr><td rowspan="4"><b><i>CircleCollider.cpp</i></b></td><td colspan="2" valign="top">Inherits from the Collider class and create a circle collider to given object</td></tr>
<tr><td valign="top"><i>Init() override</i></td><td valign="top">Setup collider</td></tr>
<tr><td valign="top"><i>CheckCollison() override</i></td><td valign="top">TODO</td></tr>
<tr><td valign="top"><i>SetCircleCollider()</i></td><td valign="top">Setup collider size</td></tr>
<tr><td rowspan="4"><b><i>BoxCollider.cpp</i></b></td><td colspan="2" valign="top">Inherits from the Collider class and create a Box collider to given object</td></tr>
<tr><td valign="top"><i>Init() override</i></td><td valign="top">Setup collider</td></tr>
<tr><td valign="top"><i>CheckCollison() override</i></td><td valign="top">TODO</td></tr>
<tr><td valign="top"><i>SetBoxCollider()</i></td><td valign="top">Setup collider size</td></tr>
<tr><td rowspan="5"><b><i>Helper.cpp</i></b></td><td colspan="2" valign="top">A class with some utility functions</td></tr>
<tr><td valign="top"><i>Print()</i></td><td valign="top">Various overload for the print log</td></tr>
<tr><td valign="top"><i>Random()</i></td><td valign="top">Various overload to find the random in the given range</td></tr>
<tr><td valign="top"><i>DrawCricle()</i></td><td valign="top">Draw a circle, a gizmo circle</td></tr>
<tr><td valign="top"><i>DrawRectangle()</i></td><td valign="top">Draw a rectangle, a gizmo rectangle</td></tr>
<tr><td rowspan="8"><b><i>Ship.cpp</i></b></td><td colspan="2" valign="top">A player class inherit from the gameobject and input listener. It draws ship and initialize the whole system for the player. Used Constructor to draw texture using texture manager</td></tr>
<tr><td valign="top"><i>Update() override</i></td><td valign="top">Update movement</td></tr>
<tr><td valign="top"><i>Draw() override</i></td><td valign="top">Draw ship for the texture </td></tr>
<tr><td valign="top"><i>OnKeyDown() override</i></td><td valign="top">Move direction for the keys</td></tr>
<tr><td valign="top"><i>OnKeyUp() override</i></td><td valign="top">Move direction for the keys</td></tr>
<tr><td valign="top"><i>InitRigidBody()</i></td><td valign="top">Initialize the rigidbody</td></tr>
<tr><td valign="top"><i>Move()</i></td><td valign="top">Update position to the transform</td></tr>
<tr><td valign="top"><i>boundToScreen()</i></td><td valign="top">Check the player stays in the screen</td></tr>
<tr><td rowspan="6"><b><i>Asteroids.cpp</i></b></td><td colspan="2" valign="top">A simple asteroid is spawn and move to the direction, inherited from the gameobject class</td></tr>
<tr><td valign="top"><i>Update() override</i></td><td valign="top">Update the position of the asteroid</td></tr>
<tr><td valign="top"><i>Draw() override</i></td><td valign="top">Update the rendering</td></tr>
<tr><td valign="top"><i>InitRigidBody()</i></td><td valign="top">Initialize the rigidbody</td></tr>
<tr><td valign="top"><i>InitSpeeds()</i></td><td valign="top">Get random speed value using helper class</td></tr>
<tr><td valign="top"><i>InitDirection()</i></td><td valign="top">Get random direction value using helper class</td></tr>
<tr><td rowspan="3"><b><i>Background.cpp</i></b></td><td colspan="2" valign="top">A simple class inherited from the gameobject class and draw the background space</td></tr>
<tr><td valign="top"><i>Update() override</i></td><td valign="top">Update the position of the background</td></tr>
<tr><td valign="top"><i>Draw() override</i></td><td valign="top">Update the render of the background</td></tr>
<tr><td colspan="3"><b><i>This project is on the way, physics base movement is happening but the collision isn’t detecting.</i></b></td></tr>
</table>
