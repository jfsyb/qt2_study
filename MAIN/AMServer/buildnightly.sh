umount //192.168.0.250/Contract
mount -t cifs //192.168.0.250/Contract -o username=guest /mnt
logfile=/mnt/BuildOut/MAIN/Nightly/log.txt
foldname=/mnt/BuildOut/MAIN/Nightly/3.1.0.`date +%Y%m%d`/var/dl
mkdir -p $foldname
date >>$logfile
rm -r ./AMPRO >>$logfile
svn checkout svn://192.168.10.162/AMPRO >>$logfile
cd /root/AMPRO/MAINBRANCH/MAIN >>$logfile
qmake -r mainMedctrl.pro DEFINES+=arm >>$logfile
make >>$logfile
make clean >>$logfile
cd /root/AMPRO/MAINBRANCH/AM >>$logfile
rm -r bin >>$logfile
cp ./linux_bin_debug/ZipUpDataFile . >>$logfile
rm -r linux_bin_debug >>$logfile
cd /root/AMPRO/MAINBRANCH/ >>$logfile
tar -cvzf AM.tar.gz ./AM >>$logfile
cd /root/AMPRO/MAINBRANCH/AM/ >>$logfile
chmod 777 * >>$logfile
./ZipUpDataFile >>$logfile
cp /root/AMPRO/MAINBRANCH/AM/app.update $foldname >>$logfile
cd /root
umount //192.168.0.250/Contract 
rm -r ./AMPRO

