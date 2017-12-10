#! /bin/sh
mkdir -p ~/.jedit/modes/
cp ezlanguage.xml ~/.jedit/modes/
cd ~/.jedit/modes/
touch catalog
sed -i '/<MODES>/a \<MODE NAME="ezlanguage" FILE="ezlanguage.xml" FILE_NAME_GLOB="*.{ezl,ez}" />' ~/.jedit/modes/catalog

