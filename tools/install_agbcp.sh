#!/bin/bash

set -e

here=$(dirname "$(readlink -f "$0")")/..
temp=$(mktemp -d)
trap 'rm -rf "$temp"' EXIT

# Keep the C++-capable cp toolchain reproducible. This base includes the
# unique-section alignment correction; the local frontend patch preserves
# destructor semantics when a declaration selects its native assembler name.
# The Thumb call patch supports individual far-call declarations without
# changing ordinary calls or requiring fixed-register source constraints.
agbcc_repo="https://github.com/notyourav/agbcc.git"
agbcc_commit="1caa6becde5e4676b59c31c74d68f45ced79557c"

git clone --no-checkout "$agbcc_repo" "$temp"
cd "$temp"
git checkout --detach "$agbcc_commit"
git apply --check "$here/tools/agbcp-asm-destructors.patch"
git apply "$here/tools/agbcp-asm-destructors.patch"
git apply --check "$here/tools/agbcc-long-calls.patch"
git apply "$here/tools/agbcc-long-calls.patch"
./build.sh
./install.sh "$here"
