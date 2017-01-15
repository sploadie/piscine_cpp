#!/bin/bash

make re; printf "\nDiff:\n"; diff -y example.txt <(./materialize | cat -e)