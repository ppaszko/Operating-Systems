#!/bin/bash



FILENAME=lab2skrypt01.sh
FILESIZE=$(stat -c%s "$FILENAME")
echo "Size of $FILENAME = $FILESIZE bytes."


PROCESS_NO=$(ps aux | grep lab2skrypt01.sh | head -n 1 | awk '{print $2}')
MEMORY=$(pmap $PROCESS_NO |tail -n 1 | awk '/[0-9]/{print $2}' | tr -d 'K')
echo $MEMORY
python - << EOF
import time
luj=[]
tabl=[]
plik=open('pamiec.txt', 'a')

while ($MEMORY<100000):
	PROCESS_NO=$(ps aux | grep lab2skrypt01.sh | head -n 1 | awk '{print $2}')
	MEMORY=$(pmap $PROCESS_NO |tail -n 1 | awk '/[0-9]/{print $2}' | tr -d 'K')
	print(str($MEMORY) + "\n")
	luj.append("hehe")
	tabl.append("bieda")
	plik.writelines(luj)
	time.sleep(0.5)
EOF


