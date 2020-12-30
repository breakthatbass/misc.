import sys

def main():

    if (len(sys.argv) < 2):
        for line in sys.stdin:
            print(line, end='')

    i = 1
    while (i < len(sys.argv)):
        try:
            fp = open(sys.argv[i], 'r')
            for line in fp:
                print(line, end='')
        except:
            print('wcat: cannot open file')
            sys.exit(1)
        i+=1

if __name__ == '__main__':
    main()
