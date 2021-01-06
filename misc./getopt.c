#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int opt;
    char *user_name = NULL;
    char *file = NULL;


    // options on left side of ':' take args, on right, no args
    while ((opt = getopt(argc, argv, "u:h:gl")) != -1) {
        switch(opt)
        {
            // need args
            case 'u':
                user_name = optarg;
                printf("user is selected\n");
                printf("the user is %s\n", user_name);
                break;
            case 'h':
                printf("h was used and optarg is: %s\n", optarg);
                break;
            // no args
            case 'g':
                printf("group (-g) is selected\n");
                break;
            case 'l':
                printf("the -l flag has been used\n");
                break;
            default:
                printf("invalid option\n");
                return 1;
        }
    }
    return 0;
}