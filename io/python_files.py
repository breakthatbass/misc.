'''
Notes for working with files in python to keep as a reference

taken from https://realpython.com/working-with-files-in-python/#toc
'''


import os  # for scandir() 

# read from file and print it's contents
with open('test.txt', 'r') as f:
    data = f.read()
# printing it doesn't need to be in the loop
# print(data)


# print a list of the dirs and files
with os.scandir('cs50/') as entries:
    # requires iteration as it is an object
    for entry in entries:
       # print(entry.name)
        pass  # pass is necessary if the above print statement is commented out


# print a list of only dirs, no files
current_dir = 'cs50/'
with os.scandir(current_dir) as entries:
    for entry in entries:
        if entry.is_dir(): # check if entry is a dir
           # print(entry.name)
            pass


# print a list of only files, no dirs
with os.scandir(current_dir) as entries:
    for entry in entries:
        if entry.is_file():  # check if entry is a file
            #print(entry.name)
            pass


# pattern matching with fnmatch()
import fnmatch

for file_name in os.listdir(current_dir):
    if fnmatch.fnmatch(file_name, '*'):
        #print(file_name)
        pass


# pattern matching with glob
import glob
from pathlib import Path

p = Path('cs50/')
for name in p.glob('*.md'):
    #print(name)
    pass


# Walking a directory tree and printing the names of the directories and files
for dirpath, dirnames, files in os.walk('invoice/'):
    print(f'Found directory: {dirpath}')
    for file_name in files:
        #print(file_name)
        pass














