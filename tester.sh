#! /bin/bash

BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NOCOLOR='\033[0m'

PROGRAM=./so_long
if test -f "$PROGRAM";
then
#	echo "Cleaning all"
	make fclean > /dev/null
fi

i=1

#Testing makefile
echo "#####		TEST MAKEFILE		#####\n\n"

#Test make
test1=$(make | grep "Mac OS Compilation Successful" | wc -l | awk '{$1=$1};1'); sleep 0.5

# #Test re make
# test2=$(make | grep "Mac OS Compilation Successful" | wc -l | awk '{$1=$1};1'); sleep 0.5

# #Test touch libft file
# touch includes/libft/sources/ft_convert/ft_atoi.c
# test3=$(make | grep "Mac OS Compilation Successful" | wc -l | awk '{$1=$1};1'); sleep 0.5

# #Test touch libft header
# touch includes/libft/includes/libft.h
# test4=$(make | grep "Mac OS Compilation Successful" | wc -l | awk '{$1=$1};1'); sleep 1

# #Test touch so_long file
# touch sources/rendering/so_long.c
# test5=$(make | grep "Mac OS Compilation Successful" | wc -l | awk '{$1=$1};1'); sleep 0.5

# TITLE_TEST="nTest nº$i : make\n"; ((i=i+1))
# if [[ "$test1" > "0" ]];
# then
# 	echo "${GREEN}${TITLE_TEST}OK${NOCOLOR}"
# else
# 	echo "${RED}${TITLE_TEST}KO${NOCOLOR}"
# fi

# TITLE_TEST="\n\nTest nº$i : test re make\n"; ((i=i+1))
# if [[ "$test2" = "0" ]];
# then
# 	echo "${GREEN}${TITLE_TEST}OK${NOCOLOR}"
# else
# 	echo "${RED}${TITLE_TEST}KO${NOCOLOR}"
# fi

# TITLE_TEST="\n\nTest nº$i : touch libft file (ft_atoi.c)\n"; ((i=i+1))
# if [[ "$test3" > "0" ]];
# then
# 	echo "${GREEN}${TITLE_TEST}OK${NOCOLOR}"
# else
# 	echo "${RED}${TITLE_TEST}KO${NOCOLOR}"
# fi

# TITLE_TEST="\n\nTest nº$i : touch libft header (libft.h)\n"; ((i=i+1))
# if [[ "$test4" > "0" ]];
# then
# 	echo "${GREEN}${TITLE_TEST}OK${NOCOLOR}"
# else
# 	echo "${RED}${TITLE_TEST}KO${NOCOLOR}"
# fi

# TITLE_TEST="\n\nTest nº$i : touch so_long file (so_long.c)\n"; ((i=i+1))
# if [[ "$test5" > "0" ]];
# then
# 	echo "${GREEN}${TITLE_TEST}OK${NOCOLOR}"
# else
# 	echo "${RED}${TITLE_TEST}KO${NOCOLOR}"
# fi

echo "\n\n\n#####		TEST MAPS		#####\n\n"
i=1
echo "Test nº$i :	no arguments\n./so_long"; ((i=i+1)); ./so_long; sleep 1

echo "\n\n\n#####		TEST Extensions		#####"
i=1
echo "\n\nTest nº$i : no extension\n./so_long map\n\n"; ((i=i+1)); ./so_long map; sleep 1
echo "\n\nTest nº$i : uncomplete\n./so_long map.\n\n"; ((i=i+1)); ./so_long map.; sleep 1
echo "\n\nTest nº$i : uncomplete\n./so_long map.b\n\n"; ((i=i+1)); ./so_long map.b; sleep 1
echo "\n\nTest nº$i : uncomplete\n./so_long map.be\n\n"; ((i=i+1)); ./so_long map.be; sleep 1
echo "\n\nTest nº$i : too long\n./so_long map.berr\n\n"; ((i=i+1)); ./so_long map.berr; sleep 1
echo "\n\nTest nº$i : too short\n./so_long .ber\n\n"; ((i=i+1)); ./so_long .ber; sleep 1
echo "\n\nTest nº$i : with folder\n./so_long /.ber\n\n"; ((i=i+1)); ./so_long /.ber; sleep 1

echo "\n\n\n#####		TEST Map		#####"
i=1
echo "\n\nTest nº$i :	no such file\n./so_long map.ber\n"; ((i=i+1)); ./so_long map.ber; sleep 1
echo "\n\nTest nº$i :	non square\n./so_long maps/non_square.ber\n"; ((i=i+1)); ./so_long maps/non_square.ber; sleep 1
echo "\n\nTest nº$i :	map non closed\n./so_long maps/non_closed.ber\n"; ((i=i+1)); ./so_long maps/non_closed.ber; sleep 1
echo "\n\nTest nº$i :	need 1 start\n./so_long maps/no_start.ber\n"; ((i=i+1)); ./so_long maps/no_start.ber; sleep 1
echo "\n\nTest nº$i :	need 1 exit\n./so_long maps/no_exit.ber\n"; ((i=i+1)); ./so_long maps/no_exit.ber; sleep 1
echo "\n\nTest nº$i :	need at least 1 collectibles\n./so_long maps/no_collectibles.ber\n"; ((i=i+1)); ./so_long maps/no_collectibles.ber; sleep 1
echo "\n\nTest nº$i :	no more than 1 start\n./so_long maps/two_start.ber\n"; ((i=i+1)); ./so_long maps/two_start.ber; sleep 1
echo "\n\nTest nº$i :	no more than 1 exit\n./so_long maps/two_exit.ber\n"; ((i=i+1)); ./so_long maps/two_exit.ber; sleep 1
echo "\n\nTest nº$i :	only 0, 1, C, E, P characters\n./so_long maps/extra_letter.ber\n"; ((i=i+1)); ./so_long maps/extra_letter.ber; sleep 1

echo "\n\n\n#####		TEST Finishable		#####"
i=1
echo "\n\nTest nº$i :	player stuck\n./so_long maps/unfinishable_basic_1.ber\n"; ((i=i+1)); ./so_long maps/unfinishable_basic_1.ber; sleep 1
echo "\n\nTest nº$i :	exit blocked\n./so_long maps/unfinishable_basic_2.ber\n"; ((i=i+1)); ./so_long maps/unfinishable_basic_2.ber; sleep 1
echo "\n\nTest nº$i :	collectible blocked\n./so_long maps/unfinishable_basic_3.ber\n"; ((i=i+1)); ./so_long maps/unfinishable_basic_3.ber; sleep 1
echo "\n\nTest nº$i :	wall split map in two\n./so_long maps/unfinishable_basic_4.ber\n"; ((i=i+1)); ./so_long maps/unfinishable_basic_4.ber; sleep 1


echo "\n\n\n#####		TEST LEAKS		#####\n\n"
i=1
echo "Test leaks nº$i :	no arguments\n./so_long\n"; ((i=i+1)); leaks --atExit -- ./so_long; sleep 1

echo "\n\n\n#####		TEST Extensions		#####"
i=1
echo "\n\nTest nº$i : no extension\n./so_long map\n\n"; ((i=i+1)); leaks --atExit -- ./so_long map; sleep 1
echo "\n\nTest nº$i : uncomplete\n./so_long map.\n\n"; ((i=i+1)); leaks --atExit -- ./so_long map.; sleep 1
echo "\n\nTest nº$i : uncomplete\n./so_long map.b\n\n"; ((i=i+1)); leaks --atExit -- ./so_long map.b; sleep 1
echo "\n\nTest nº$i : uncomplete\n./so_long map.be\n\n"; ((i=i+1)); leaks --atExit -- ./so_long map.be; sleep 1
echo "\n\nTest nº$i : too long\n./so_long map.berr\n\n"; ((i=i+1)); leaks --atExit -- ./so_long map.berr; sleep 1
echo "\n\nTest nº$i : too short\n./so_long .ber\n\n"; ((i=i+1)); leaks --atExit -- ./so_long .ber; sleep 1
echo "\n\nTest nº$i : with folder\n./so_long /.ber\n\n"; ((i=i+1)); leaks --atExit -- ./so_long /.ber; sleep 1

echo "\n\n\n#####		TEST Map		#####"
i=1
echo "\n\nTest nº$i :	no such file\n./so_long map.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long map.ber; sleep 1
echo "\n\nTest nº$i :	non square\n./so_long maps/non_square.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/non_square.ber; sleep 1
echo "\n\nTest nº$i :	map non closed\n./so_long maps/non_closed.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/non_closed.ber; sleep 1
echo "\n\nTest nº$i :	need 1 start\n./so_long maps/no_start.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/no_start.ber; sleep 1
echo "\n\nTest nº$i :	need 1 exit\n./so_long maps/no_exit.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/no_exit.ber; sleep 1
echo "\n\nTest nº$i :	need at least 1 collectibles\n./so_long maps/no_collectibles.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/no_collectibles.ber; sleep 1
echo "\n\nTest nº$i :	no more than 1 start\n./so_long maps/two_start.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/two_start.ber; sleep 1
echo "\n\nTest nº$i :	no more than 1 exit\n./so_long maps/two_exit.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/two_exit.ber; sleep 1
echo "\n\nTest nº$i :	only 0, 1, C, E, P characters\n./so_long maps/extra_letter.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/extra_letter.ber; sleep 1

echo "\n\n\n#####		TEST Finishable		#####"
i=1
echo "\n\nTest nº$i :	player stuck\n./so_long maps/unfinishable_basic_1.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/unfinishable_basic_1.ber; sleep 1
echo "\n\nTest nº$i :	exit blocked\n./so_long maps/unfinishable_basic_2.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/unfinishable_basic_2.ber; sleep 1
echo "\n\nTest nº$i :	collectible blocked\n./so_long maps/unfinishable_basic_3.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/unfinishable_basic_3.ber; sleep 1
echo "\n\nTest nº$i :	wall split map in two\n./so_long maps/unfinishable_basic_4.ber\n"; ((i=i+1)); leaks --atExit -- ./so_long maps/unfinishable_basic_4.ber; sleep 1

#Cleaning after tests
make fclean > /dev/null