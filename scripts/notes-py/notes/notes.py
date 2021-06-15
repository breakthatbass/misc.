import sys
import os
from termcolor import colored
from pathlib import Path

DEBUG = False


# any of these commands will generate list
list_options = ['l', '-l', '--list', 'list']


def list_notes(debug=DEBUG, bash=False):
    '''list all note files currently availables in pages directory'''
    print()
    print(colored('available notes:', 'magenta'))

    if debug:
        if bash:
            notes_loc = '../pages/bash/'
        else:
            notes_loc = '../pages/'
    else:
        home = str(Path.home())
        if bash:
            notes_loc = home + '/pages/bash/'
        else:
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


def pages_path(note_file, debug=DEBUG):
    '''build path to requested note'''
    if debug:
        return '../pages/' + note_file
    else:
        home = str(Path.home())
        return home + '/pages/' + note_file


def print_info(note_path):
    with open(note_path, 'r') as fp:
        for line in fp.readlines():
            if line[0] == '-':
                print(colored(line, 'green'), end='')
            elif line[0] == '#':
                # comment
                print(colored(line, 'yellow'), end='')
            elif line[0].isalpha():
                title = line.rstrip()
                print()
                print(colored(title, 'magenta', attrs=['bold']))
            else:
                words = line.split()
                print('    ', end='')
                for word in words:
                    if word == title:
                        print(colored(word, 'magenta'), end=' ')
                    elif word[0] == '-' or word[0] == '$':
                        print(colored(word, 'blue'), end=' ')
                    elif word[0] == '#':
                        # comment
                        print(colored(word, 'grey'), end='')
                    elif word == 'tab':
                        # if the word is tab, it means we want a tab inserted here
                        print('    ', end='')
                    else:
                        print(colored(word, 'red'), end=' ')
                print()



def bash(bash_arg=None, debug=DEBUG):
    '''bash notes requires a second argument. manage it'''
    if debug:
        bash_path = '../pages/bash/'
    else:
        home = str(Path.home())
        bash_path = home + '/pages/bash/'

    bash_options = next(os.walk(bash_path), (None, None, []))[2]
    if bash_arg not in bash_options:
        print(f'{bash_arg}: not found in bash pages')
        print('available bash pages:')
        print(f'\t{colored(bash_options, "green")}')
        sys.exit(1)

    bash_path = bash_path + bash_arg
    print_info(bash_path)
    
                    

def main():

    if len(sys.argv) < 2:
        print_usage()
        sys.exit(1)

    # put together path/to/note_file
    note_file = sys.argv[1]
    note_loc = pages_path(note_file, debug=DEBUG)

    if note_file in list_options:
        list_notes(debug=DEBUG)
        sys.exit(0)

    if note_file in help_options:
        print_usage()
        sys.exit(0)

    if note_file == 'bash':
        if len(sys.argv) < 3:
            bash()
        else:
            bash(sys.argv[2])
        sys.exit(0)

    if not os.path.isfile(note_loc):
        print('this page doesn\'t exist yet!')
        print('maybe you should add it!')
        sys.exit(1)


    print_info(note_loc)

if __name__ == '__main__':
    main()

