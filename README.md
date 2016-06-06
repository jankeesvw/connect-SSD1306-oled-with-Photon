# Connect SSD1306 oled display with Photon

In this repository you can find how I hooked up a SSD1306 Adafruit display to a Photon. For my use case I wanted to send text to the display.

## Schematics

I'm using the SPI connection as explained [in the PDF](https://github.com/jankeesvw/SSD1306-Photon/blob/master/docs/monochrome-oled-breakouts.pdf) you can find in the docs folder.

The schematics are included in the [Schematics.fzz](https://github.com/jankeesvw/SSD1306-Photon/blob/master/Schematics.fzz) file:

![Schematics](https://cloud.githubusercontent.com/assets/167882/15805438/acaf0fe8-2b2a-11e6-8284-95ede0fb1f81.png)

## End result

This how it looks when it's connected:

![SSD1306 working with a Photon](https://cloud.githubusercontent.com/assets/167882/15805330/f928621a-2b26-11e6-8eae-8519a5499e7d.jpg)

I'm sending a string with data to the Particle API, that string is split with commas (`,`). For example: `Hello,World.` becomes:

```
Hello
World.
```

To send something to the screen I something like this:

```bash
curl -X POST -F "params=Hello,World." "https://api.particle.io/v1/devices/1234567/lines?access_token=abcdefgh"
```