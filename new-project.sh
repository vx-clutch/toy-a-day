#!/bin/env bash

name=$1

mkdir "$name" && cd "$name"

cat > Makefile <<EOF
.POSIX:
CC ::= gcc
CFLAGS ::= -std=c23 -Wall -Wextra -Wpedantic

all: $name

clean:
	\$(RM) $name
EOF

cat > README <<EOF
"$name" is a part of toy-a-day and is under the MIT licence.
EOF

cat > "${name}.c" <<EOF
EOF
