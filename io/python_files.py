'''
Notes for working with files in python to keep as a reference

taken from https:..realpythoncom.working-with-files-in-python.#toc
'''

import os  # for scandir() 

# read from file and print it's contents
with open('test.txt', 'r') as f:
    data = f.read()
# printing it doesn't need to be in the loop
# print(data)


# print a list of the dirs and files
with os.scandir('.') as entries:
    # requires iteration as it is an object
    for entry in entries:
       # print(entryname)
        pass  # pass is necessary if the above print statement is commented out


# print a list of only dirs, no files
current_dir = '.'
with os.scandir(current_dir) as entries:
    for entry in entries:
        if entry.is_dir(): # check if entry is a dir
           # print(entryname)
            pass


# print a list of only files, no dirs
with os.scandir(current_dir) as entries:
    for entry in entries:
        if entry.is_file():  # check if entry is a file
            #print(entryname)
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

p = Path('.')
for name in p.glob('*md'):
    #print(name)
    pass


# Walking a directory tree and printing the names of the directories and files
for dirpath, dirnames, files in os.walk('.'):
    print(f'Found directory: {dirpath}')
    for file_name in files:
        #print(file_name)
        pass

#from pathlib import Path
import pathlib

def tree(directory):
    '''print directory tree pattern'''
    print(f'+ {directory}')
    for path in sorted(directory.rglob('*')):
        if path.name.startswith('', 0, 1) == False:
            depth = len(path.relative_to(directory).parts)
            spacer = '    ' * depth
            print(f'{spacer}+ {pathname}')

#tree(pathlibPathcwd())



