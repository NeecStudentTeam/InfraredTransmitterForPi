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

`sudo gcc sendir.cpp -osendir -lwiringPi`

## Installation

`PATH`

```
sudo ln -s ~InfraredTransmitterForPi/sendir /usr/bin/sendir
sudo chmod ugo+x /usr/bin/sendir
```
