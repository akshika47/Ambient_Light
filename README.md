# Ambient Light Guide
code for creating wifi controlled and battery powered ambient lights from scratch

### Circuit Diagram
With the help of the following diagram, wire up your first light.

<p align="center">
<img src="https://github.com/akshika47/Ambient_Light/blob/master/Assets/circuit.png" width="500" height="500" class="centre">
</p>

* Checking if the neo pixels are working via croc cables

<p align="center">
<img src="https://github.com/akshika47/Ambient_Light/blob/master/Assets/neo_pixel_test.jpg" height="500" class="centre">
</p>


* Find yourself a brother to do the soldering work ;) 

<p align="center">
<img src="https://github.com/akshika47/Ambient_Light/blob/master/Assets/desira.jpg" width="500" class="centre">
</p>

* This is after soldering the wires to the neo pixels

<p align="center">
<img src="https://github.com/akshika47/Ambient_Light/blob/master/Assets/neo_pixel_with_wires.jpg" height="500" class="centre">
</p>


### Code

Upload the code in this [file](https://github.com/akshika47/Ambient_Light/blob/master/Clients/Wemos_ESP8266/Wemos_ESP8266.ino) to the ESP8266 chip.

### 3D Printing the case

Using the cad files in the 3D_printing_designs folder, print the casing. The case I have done is a very basic design. There is plenty of room for improvement. Use the latest STL files(version 3) for printing. There is a lid and a box to be printed.

Note : I have used [AutoDesk Fusion 360](https://www.autodesk.com/products/fusion-360/overview) for creating the casing. You can use any kind of cad software to design the box.

### Packaging

You can place the circuit inside the box as follows.

<p align="center">
<img src="https://github.com/akshika47/Ambient_Light/blob/master/Assets/light_places_in_the_container.jpg" width="300">
</p>

Note : this container is different to the STL files I have provided.

### Calling the lights over the interent

After powering up the lights, it is required to send a request, in order to switch on the lights. I will cover this part in a seperate post. 

### They are ON!

<p align="center">
<img src="https://github.com/akshika47/Ambient_Light/blob/master/Assets/light.jpg" width="500" height="500">
</p>
