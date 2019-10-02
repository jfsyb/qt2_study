umount //192.168.0.250/Contract
mount -t cifs //192.168.0.250/Contract -o username=guest /mnt
logfile=/mnt/svnbak/log.txt
foldname1=/mnt/svnbak/`date +%Y%m%d`AMPRO.svn.bak
foldname2=/mnt/svnbak/`date +%Y%m%d`Asclepius.svn.bak
date >>$logfile
svnadmin dump /usr/local/svnserver/respository/AMPRO/ > $foldname1
svnadmin dump /usr/local/svnserver/respository/Asclepius/ > $foldname2
umount //192.168.0.250/Contract 


