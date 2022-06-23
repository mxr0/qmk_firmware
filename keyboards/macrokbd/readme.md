# Macro Keyboard v1.0

![macroKBD](http://www.retrobuiltgames.com/s/cc_images/teaserbox_4109097335.JPG?t=1609166249)

Macro Keyboard v1.0i, with dual encoder support. designed by [@RyanBates](http://www.retrobuiltgames.com/).

## Keyboard Info

* Keyboard Maintainer: [mxr0](https://github.com/mxr0)
* Hardware Supported: [Macro_keyboard_v1](http://www.retrobuiltgames.com/the-build-page/macro-keyboard-v2-0/macro-keyboard-mini-v1-0/)
* Hardware Availability: order PCBs with gerber file from the repository or order from [tindie](https://www.tindie.com/products/ryanbatesrbg/pcb-mini-programmable-macro-keyboard-encoders/)

Make example for this keyboard (after setting up your build environment):

    make etrobuiltgames/mini/rev1:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top right key and plug in the controller.
* **Keycode in layout**: Press the key mapped to `RESET` if it is configured.
* **Physical reset pins**: Briefly short the RST and GND pins on the microcontroller using tweezers, a paperclip, or any other conductive material.

