# LP36 QMK firmware

QMK firmware for the 36-key RP2040 LoremIpsum36/LP36, ported from the
Windows-work configuration of my Temper ZMK keyboard.

![LP36 keymap](keymap-drawer/lp36.svg)

[Combo reference](keymap-drawer/lp36-combos.svg)

## Features

- Seven layers: Base, Navigation, Mouse, Media, Number, Symbol, and Function
- Bilateral Windows home-row mods with typing-flow suppression
- Six thumb layer-taps
- 31 layer-aware, prior-idle-gated combos
- Positional combo hold-taps for Tab and paired punctuation
- Nested comma/dot and question/exclamation modifier morphs
- Tap-preferred navigation hold-taps
- Mouse keys, media controls, RGB underglow, and NKRO
- RP2040 BOOTSEL entry: hold the leftmost Esc/Media thumb and press `Q`

The source behavior is the Temper `win_work` branch at commit
`c3cf23cc021a495e623f2e8051ff4dc6be7bf565`. CI is pinned to Vial-QMK commit
`dd43959ae5c08d8a28d38a1acf7b04e86b14a344`, the revision used for the first
verified LP36 build.

Vial is deliberately disabled in this firmware. The advanced behavior relies
on a static physical combo table and custom state machines that cannot safely
follow arbitrary runtime remapping.

## Build

The GitHub Actions **Build firmware** workflow lints and compiles the UF2 on
every push and pull request. Download `lp36_temper_win_work.uf2` from the run's
artifact.

For a local Vial-QMK checkout, copy `keyboards/lp36` into its `keyboards`
directory and run:

```sh
qmk lint -kb lp36
qmk compile -kb lp36 -km temper_win_work
```

## Flash

Enter BOOTSEL with Media+Q. Then either copy the UF2 to the `RPI-RP2` volume or
write and verify it with:

```sh
picotool load -v -x lp36_temper_win_work.uf2
```

## Keymap diagrams

The diagrams use [keymap-drawer](https://github.com/caksoylar/keymap-drawer).
Install `keymap-drawer==0.22.0`, then regenerate both checked-in SVGs with:

```sh
./scripts/render-keymap.sh
```

The **Render keymap** workflow rejects stale generated SVGs and uploads them as
an artifact. `keymap-drawer/lp36.yaml` is the human-readable diagram source;
the QMK keymap remains authoritative.

## Hardware

- RP2040-Zero, 2 MiB flash
- 4 × 10 matrix, `COL2ROW`
- columns GP2–GP11; rows GP12–GP15
- thumb switches at row 3, columns 2–7
- WS2812 data on GP0, 36 LEDs
- USB VID:PID `5254:0008`

The private full-flash factory backup is intentionally not included in this
public repository.
