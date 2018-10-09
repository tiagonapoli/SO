#!/bin/sh

get_modified_files() {
  cat ./modified_archives > /dev/null 2>&1
  if [ $? -eq 0 ]
  then
    #MINIX
    cat ./modified_archives
  else 
    cat ../modified_archives
  fi
}

host=$( hostname 2> /dev/null )
ret=$?

if [ $ret -ne 0 ]
then
  #Minix 
  echo "Estou no MINIX"
  mtools copy -nv "a:/timestamp" /
  mtools copy -nv "a:/modified_archives" /
  files_list=$( get_modified_files )
  for i in $files_list
  do
    echo "Arquivo: $i"
    mtools copy -nv "a:/$(basename $i)" "$i"
  done

  echo "------------------"
  cat /timestamp
  echo "------------------"

  read -p "Press enter to continue" _null
  cd /usr/src
  make world 2> ERRORS
  echo "----------------ERROS----------------"
  more ./ERRORS
  shutdown

else
  #PC
  
  echo "Estou no PC: $host"
  floppy_path=$( cat floppy_path )
  sudo rm -rf $floppy_path/*
  timestamp=$( date +"%T" )
  echo "\nTIMESTAMP: $timestamp\n"
  echo  $timestamp > timestamp
  files=""
  for i in $( get_modified_files )
  do
    files="$files ..$i"
  done
  sudo cp -rv $files ./go.sh ../modified_archives ./timestamp $floppy_path
  rm -v timestamp
fi

