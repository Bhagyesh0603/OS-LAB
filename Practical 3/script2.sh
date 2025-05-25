#Program to implement shell scripting
#Bhumika Jadhav (SY_B_10)

echo -e "Name of Operating System is          : $(uname)"
echo -e "Operating System architecture is     : $(uname -m)"
echo -e "Operating System running on system   : $(uname -o)"
echo -e "Operating System Kernel version is   : $(uname -r)"
echo -e "Operating System release information : $(cat /etc/os-release)"