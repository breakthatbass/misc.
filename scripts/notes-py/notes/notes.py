import sys
import os
from termcolor import colored
from pathlib import Path


# any of these commands will generate list
list_options = ['l', '-l', '--list', 'list']

def list_notes(debug=True):
    '''list all note files currently availables in pages directory'''
    print()
    print(colored('available notes:', 'magenta'))

    if debug:
        notes_loc = '../pages/'
    else:
        home = str(Path.home())
        notes_loc = home + '/pages/'

    for file in os.walk(notes_loc):
        file_list = file[2]
        for f in file_list:
            print(colored('    - ', 'red'), end='')
            print(colored(f, 'red'))
    print()


# any of these flags will generate usage
help_options = ['-u', '-h', '--usage', '--help']

def print_usage():
    print()
    print(colored('usage: notes command', 'magenta'))
    print()
    print('use ', end='')
    print(colored(f'{list_options}', 'green'), end='')
    print(' to list all available notes')
    print()


def pages_path(note_file, debug=True):
    '''build path to requested note'''
    if debug:
        return '../pages/' + note_file
    else:
        home = str(Path.home())
        return home + '/.pages/' + note_file


def print_info(note_path):
    '''read file and print it'''
    print()
    with open(note_path, 'r') as fp:
        for line in fp.readlines():
            # info line
            if line[0] == '-':
                print(colored(line, 'green'), end='')
            # title
            elif line[0].isalpha():
                print(colored(line, 'magenta', attrs=['bold']), end='')
            # the command
            else:
                IN_OPT = False
                for c in line:
                    if c == '-' or IN_OPT:
                        IN_OPT = True
                        print(colored(c, 'blue'), end='')
                    elif IN_OPT:
                        IN_OPT = False
                        print(colored(c, 'red'), end='')
                    else:
                        print(colored(c, 'red'), end='')
    print('\n')


def main():

    if len(sys.argv) != 2:
        print_usage()
        sys.exit(1)

    # put together path/to/note_file
    note_file = sys.argv[1]
    note_loc = pages_path(note_file, debug=False)

    if note_file in list_options:
        list_notes(debug=False)
        sys.exit(0)

    if note_file in help_options:
        print_usage()
        sys.exit(0)

    if not os.path.isfile(note_loc):
        print('this page doesn\'t exist yet!')
        print('maybe you should add it!')
        sys.exit(1)


    print_info(note_loc)

if __name__ == '__main__':
    main()
