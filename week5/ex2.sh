#/bin/bash

while true
do
 if ln file.txt file.txt.lock 
 then
  int=$(tail -1 file.txt | grep -Eo '[0-9]+$')
  int=$(($int + 1))
  echo $int >> file.txt 
  rm file.txt.lock
 else
  echo "can't do this" >> junk.txt
 fi
done
