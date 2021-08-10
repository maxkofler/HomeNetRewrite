# HomeNet

Direct links:
* [Installation](#installation)

## What is HomeNet?
HomeNet is one part of a system to monitor and record data to visualize it. \
This part of the system is designed to run on a Server and collect all the data from drivers. \
The server is specially developed towards usage on a single board computer that have really small power consumptions and have some GPIOs to attach
sensors and modules directly to them. \
An other Part (HomeNet-GUI) is the visualization of this data and communicates to this server.

## How does it work?

HomeNet uses drivers written in Python to call in all data. For this the core C++ application calls some functions relevant for the Python modules and stores 
the data the drivers return to HomeNet. All of this gets stored in files somewhere on you "server" and can be accessed through HomeNet-GUI with trends and useful information. \
A feature called Triggers is planned that lets the user control devices attached to the server (motors, leds, relais...) through drivers.

# Installation
```
git clone https://github.com/maxkofler/homenet
cd homenet
git submodules update --init --recursive
mkdir build && cd build
cmake ..
make -j <amount of cores>
```
* After these steps you should create the following folder for HomeNet to work with: ```/etc/homenet/```
* Once you have created this folder you can move ```build/HomeNet``` to ```/usr/bin/HomeNet```
* If you use systemd you can use a script like this to start HomeNet on startup:\
```/etc/systemd/system/HomeNet.service```
```
[Unit]
Description=HomeNet daemon

[Service]
User=homenet
WorkingDirectory=/etc/homenet
ExecStart=/usr/bin/HomeNet

[Install]
WantedBy=multi-user.target
```
And enable it by typing (with sudo) ```systemctl enable HomeNet```
### How to continue from now?
Read the documentation contained in the doc/ folder to configure HomeNet and create drivers
