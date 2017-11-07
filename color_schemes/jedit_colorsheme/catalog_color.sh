#! /bin/sh
mkdir -p ~/.jedit/modes/
cp ezlanguage.xml ~/.jedit/modes/
cp catalog ~/.jedit/modes/
sed -i '/<MODES>/a \<MODE NAME="ezlanguage" FILE="ezlanguage.xml" FILE_NAME_GLOB="*.{ezl,ez}" />' ~/.jedit/modes/catalog

