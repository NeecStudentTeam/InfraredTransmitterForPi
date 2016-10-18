InfraredTransmitterForPi
====

Overview

## Description
Simple to use infrared transmitter for pi

## Usage

arg1 : IRDATA  
arg2 : Test Mode Flg (not use gpio)

`sudo ./sendir 55324 0`

## Build

for raspberry pi

`sudo gcc sendir.cpp -osendir -lwiringPi`

for windows stub

`sudo gcc sendir_windows_stub.cpp -osendir_windows_stub`

## Installation

`PATH`

```
sudo ln -s ~/InfraredTransmitterForPi/sendir /usr/bin/sendir
sudo chmod ugo+x /usr/bin/sendir
```
