mkdir $1
cp template.cpp $1/
cd $1/
mv template.cpp $1.cpp
code $1.cpp
