#!/bin/sh
set -eu

keymap -c keymap-drawer/config.yaml draw \
    -j keyboards/lp36/keyboard.json \
    -l LAYOUT \
    -o keymap-drawer/lp36.svg \
    keymap-drawer/lp36.yaml

keymap -c keymap-drawer/config.yaml draw \
    -j keyboards/lp36/keyboard.json \
    -l LAYOUT \
    -o keymap-drawer/lp36-combos.svg \
    keymap-drawer/lp36-combos.yaml

