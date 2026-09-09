#!/bin/sh
set -eu

qmk_root=${1:-}
if [ -z "$qmk_root" ] || [ ! -d "$qmk_root/keyboards/lp36" ]; then
    echo "usage: $0 /path/to/qmk_firmware-with-lp36-overlay" >&2
    exit 2
fi

repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
work_dir=$(mktemp -d)
trap 'rm -rf "$work_dir"' EXIT HUP INT TERM

run_keymap() {
    if command -v keymap >/dev/null 2>&1; then
        keymap "$@"
    else
        uvx --from keymap-drawer==0.22.0 -- keymap "$@"
    fi
}

(
    cd "$qmk_root"
    qmk c2json -kb lp36 -km default --no-cpp -o "$work_dir/lp36.json"
)

run_keymap -c "$repo_root/keymap-drawer/config.yaml" parse \
    -q "$work_dir/lp36.json" \
    -b "$repo_root/keymap-drawer/lp36.yaml" \
    -l BASE NAV MOUSE MEDIA NUM SYM FUNC \
    -c 10 \
    -o "$work_dir/lp36.yaml"

cp "$work_dir/lp36.yaml" "$repo_root/keymap-drawer/lp36.yaml"
