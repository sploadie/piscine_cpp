#!/bin/bash

make re; printf "\nDiff:\n"; diff -y example.txt <(./wasteland_essentials | cat -e)