gcc -Wall -Werror -Wextra inter.c -o inter
echo "-----------------------------TEST [1]------------------------------"
echo "$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e"
echo "-------------------------Expected result---------------------------"
echo "padinto$"
echo "---------------------------Your result-----------------------------"
./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
echo "-------------------------------------------------------------------"
echo "\n"
echo "-----------------------------TEST [2]------------------------------"
echo "$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e"
echo "-------------------------Expected result---------------------------"
echo "df6ewg4$"
echo "---------------------------Your result-----------------------------"
./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
echo "-------------------------------------------------------------------"
echo "\n"
echo "-----------------------------TEST [3]------------------------------"
echo "$>./inter "nothing" "This sentence hides nothing" | cat -e"
echo "-------------------------Expected result---------------------------"
echo "nothig$"
echo "---------------------------Your result-----------------------------"
./inter "nothing" "This sentence hides nothing" | cat -e
echo "-------------------------------------------------------------------"
echo "\n"
echo "-----------------------------TEST [4]------------------------------"
echo "$>./inter | cat -e"
echo "-------------------------Expected result---------------------------"
echo "$"
echo "---------------------------Your result-----------------------------"
./inter | cat -e
echo "-------------------------------------------------------------------"
rm -rf inter