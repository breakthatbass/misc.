#!/bin/bash

# create local copy of notes
echo "creating local copy of pages"
echo "cp -r pages $HOME/"
cp -r pages "$HOME"/

# install the python way
echo "installing with pip"
pip3 install .
