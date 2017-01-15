#!/bin/bash

make re; printf "\nDiff:\n"; diff -y example.txt <(./when_sorcerers_think | cat -e)