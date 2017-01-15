#!/bin/bash

make re; printf "\nDiff:\n"; diff -y example.txt <(./another_crusade | cat -e)