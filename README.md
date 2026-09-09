# LP36 QMK firmware

My 36-key LP36 QMK layout for Windows, inspired by
[Miryoku](https://github.com/manna-harbour/miryoku) and
[urob's ZMK config](https://github.com/urob/zmk-config).

![LP36 keymap](keymap-drawer/lp36.svg)

![LP36 combo reference](keymap-drawer/lp36-combos.png)

## Layout

- Seven layers: Base, Navigation, Mouse, Media, Number, Symbol, and Function
- Bilateral "timeless" home-row mods with typing-flow suppression
- Six thumb layer-taps
- 27 layer-aware, prior-idle-gated combos
- Repeatable modifier-sensitive punctuation and dedicated navigation keys
- Mouse keys and media controls
- RP2040 BOOTSEL entry: hold the leftmost Esc/Media thumb and press `Q`

## Build

GitHub Actions builds `lp36_default.uf2` on every push and pull request.

For a local Vial-QMK checkout, copy `keyboards/lp36` into its `keyboards`
directory and run:

```sh
qmk lint -kb lp36
qmk compile -kb lp36 -km default
```

Enter BOOTSEL with Media+Q, then copy the UF2 to `RPI-RP2` or flash it with:

```sh
picotool load -v -x lp36_default.uf2
```

## Keymap diagrams

The diagrams use [keymap-drawer](https://github.com/caksoylar/keymap-drawer).
Install `keymap-drawer==0.22.0`. With the LP36 overlay installed in a QMK
checkout, synchronize the main diagram source from `keymap.c`, then render all
checked-in images:

```sh
./scripts/sync-keymap.sh /path/to/qmk_firmware
./scripts/render-keymap.sh
```

The firmware workflow also runs host-side QMK report tests for held combo keys,
home-row quick-tap repeat, dedicated arrows, modifier morphs, and independent
mouse-direction acceleration before compiling the UF2.

The QMK keymap is authoritative. Combo annotations remain in a small separate
diagram source because QMK's JSON exporter does not include combo metadata.
