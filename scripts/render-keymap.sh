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

npx --yes sharp-cli@6.1.0 \
    -i keymap-drawer/lp36-combos.svg \
    -o keymap-drawer/lp36-combos.png \
    --format png \
    --density 144 \
    flatten '#ffffff'
