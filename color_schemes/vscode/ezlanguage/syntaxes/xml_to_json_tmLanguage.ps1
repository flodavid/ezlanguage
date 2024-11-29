# Ceci est un script Powershell Permettant de renommer des fichiers mp3 avec une meilleur syntaxe 
## suppression des _ est _-_, remplacés par des espaces ou des -
# Exécution  déplacer le script dans le dossier désiré, puis double clic ou .rename_mp3s.ps1 dans le terminal
#Write-Output Format a tmLanguage xml translated to json file to a tmLanguage proper json
Write-Output "Format a tmLanguage xml file to a tmLanguage json"

# XML declaration removal
(Get-Content EZLanguage.tmLanguage).replace("<?xml version=`"1.0`" encoding=`"UTF-8`"?>", "")   | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace("<!DOCTYPE plist PUBLIC `"-//Apple//DTD PLIST 1.0//EN`" `"http://www.apple.com/DTDs/PropertyList-1.0.dtd`">", "")   | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace("<plist version=`"1.0`">", "") | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace( '</plist>', '}') | Set-Content EZLanguage.tmLanguage.xml2.json

# Escape characters
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('\','\\') | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('\\n','\n')   | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('"','\"')   | Set-Content EZLanguage.tmLanguage.xml2.json

(Get-Content EZLanguage.tmLanguage.xml2.json).replace('<key>','"')      | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('</key>','": ')    | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('<array>','[')     | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('</array>','],')   | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json) -replace "<dict>","{"       | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json) -replace '</dict>','},' | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('<string>','"')    | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('</string>','",')   | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('<integer>','')   | Set-Content EZLanguage.tmLanguage.xml2.json
(Get-Content EZLanguage.tmLanguage.xml2.json).replace('</integer>',',')   | Set-Content EZLanguage.tmLanguage.xml2.json


# (Get-Content EZLanguage.tmLanguage.xml2.json).replace('\b','\\b')   | Set-Content EZLanguage.tmLanguage.xml2.json
# (Get-Content EZLanguage.tmLanguage.xml2.json).replace('\s','\\s')   | Set-Content EZLanguage.tmLanguage.xml2.json
# (Get-Content EZLanguage.tmLanguage.xml2.json).replace('\d','\\d')   | Set-Content EZLanguage.tmLanguage.xml2.json
# (Get-Content EZLanguage.tmLanguage.xml2.json).replace('\.','\\.')   | Set-Content EZLanguage.tmLanguage.xml2.json
# (Get-Content EZLanguage.tmLanguage.xml2.json).replace('\.','\\.')   | Set-Content EZLanguage.tmLanguage.xml2.json

# Manually replace `: \n( )*"` by `: "`
# And `,\n( )*]` by `\n    ]`
# And `,\n( )*}` by `\n      }