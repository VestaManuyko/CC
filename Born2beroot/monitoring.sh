ARCH=$(uname -a)
MEM=$(free --mega | awk '/Mem:/ {used=($2 - $7); used_p=((used/$2)*100); print used "/" $2"MB" " ("used_p"%)"}')
DISK=$(df -h | awk '{if($6 == "/") {print $4 "/" $2 " (" $5 ")"}}')
USER=$(who | awk '{print NR}')
LVM=$(cat /etc/fstab | grep mapper | wc -l | awk '{if($1 >= "1") {print"yes"} else {print "no"}}')
IPv4=$(ip a | awk '/global/ {split($2, a, "/"); print a[1]}')
MAC=$(ip a | grep ether | awk '{print $2}')
SUDO=$(journalctl _COMM=sudo | grep -c 'COMMAND=')
VCPU=$(nproc)
CPUUSG=$(top -bn1 | grep "Cpu" | awk '{split($7, a, ","); print 100 - a[2] "%"}')
PCPU=$(lscpu | grep "Socket" | awk '{print $2}')
BOOT=$(uptime -s)
TCP=$(netstat -t | awk '/ESTABLISHED/ {n++} END {print n " ESTABLISHED"}')

echo "Architecture: $ARCH"
echo "CPU physical: $PCPU"
echo "vCPU: $VCPU"
echo "Memory Usage: $MEM"
echo "Disk Usage: $DISK"
echo "CPU Load: $CPUUSG"
echo "Last boot: $BOOT"
echo "LVM use: $LVM"
echo "Connections TCP: $TCP"
echo "User log: $USER"
echo "Network: IP $IPv4 ($MAC)"
echo "Sudo: $SUDO cmd"
