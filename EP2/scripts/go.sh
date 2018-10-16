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
  mtools copy -nv "a:/teste.c" /root/

  echo "------------------"
  cat /timestamp
  echo "------------------"

  read -p "Press enter to continue" _null

  files_list=$( get_modified_files )
  for i in $files_list
  do
    echo "Arquivo: $i"
    mtools copy -nv "a:$i" "$i"
  done

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
    sudo mkdir -p $floppy_path$(dirname $i) && sudo cp -rv ..$i $floppy_path$i
  done
  sudo cp -rv ./go.sh ../modified_archives ./timestamp ../teste.c $floppy_path
  rm -v timestamp
fi

