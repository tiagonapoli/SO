#!/bin/sh

# inside_list() {
#   for i in $2 
#   do
#     if [ $1 = $i ]
#     then
#       echo 1
#       return 1
#     fi
#   done
#   echo 0
#   return 0
# }

# ret=$(inside_list "asdf" "qwe asdf as asd")
# echo "valor $ret"

# for x in $( ls )
# do
#   echo $x
# done

get_modified_files() {
  cat ./modified_archives > /dev/null 2>&1
  if [ $? -eq 0 ]
  then
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

  files_list=$( get_modified_files )
  for i in files_list
  do
    mtools "a:/$i" "/usr/$i"
  done

else
  #PC
  echo "Estou no PC: $host"
  floppy_path=$( cat floppy_path )
  cp -rv $floppy_path ../src
fi

